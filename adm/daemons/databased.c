// databased.c
// Create by 发现号(Find@TX).
// Updated by Lonely@NT

// databased.c 提供的外部函数：
//
// 通用语句：
//   mixed *db_fetch_row()        - 为查找一行
//   mixed  db_query()            - 为执行语句
//   mixed *db_all_query()        - 查找所有行
//   mixed  db_crypt()            - 加密字符串
//   string query_db_status()     - 数据库状态

// 用户管理：
//   int db_find_user()           - 查询 ID 是否存在
//   int db_create_user()         - 创建新的用户
//   int db_remove_user()         - 删除用户档案
//   int db_set_user()            - 设定用户属性
//   int db_add_user()            - 增加用户属性
//   int db_query_user()          - 查询用户属性
//   int db_count_user()          - 计算用户数量

#ifdef DB_SAVE

#include <mudlib.h>
#include "/adm/etc/database.h"

#define REG_BONUS       2100

class target
{
        string host;
        string user;
        mapping quest;
}
nosave int db_handle = 0;
#ifdef STATIC_LINK

public int query_db_handle()
{
        return db_handle;
}
#endif

nosave int crc_status = 0;
protected mixed *all_target = ({});
protected int max_repeat = 3;
public void broadcast(string sql);

string *do_sql(string);


// db_save_all() 时这里的好几个字段应该从 DBASE 里分离出来单独存储
nosave string *cols = ({
        "id", "name", "surname", "purename", "password", "ad_password",
        "birthday", "online", "on_time", "fee_time", "save_time", "f_mail",
        "last_from", "last_on", "last_off", "last_station", "endrgt",
        "login_dbase", "store_base", "store_data", "f_dbase", "f_damage",
        "f_condition", "f_attack", "f_skill", "f_alias", "f_user", "f_business",
});

// 确定用户返回数据时是否校验数据和 临时举措
int crc_status() { return crc_status; }
int clean_up() { return 1; }

protected void chat(string msg)
{
#ifdef DEBUG
        CHANNEL_D->channel_broadcast("nch", "MySQL："+(string)msg);
        log_file("database", "chat() call : " + msg + "\n");
#endif
}


protected void log_error(string func, mixed err)
{
        log_file("database", sprintf("%s ERROR ** %s\n%O\n", func, ctime(time()), err));
}

int query_db_status()
{
        mixed ret;

#ifdef STATIC_LINK
        ret = DATABASE_D->db_fetch_row("SHOW DATABASES");
        if( db_handle && arrayp(ret) && sizeof(ret) > 0 )
                return 1;
#endif

        return 0;
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
        mixed n;

        n = db_connect(DB_HOST, DATABASE, DB_USER);

        if( intp(n) && (n > 0) )  // 连接成功
        {
#ifdef STATIC_LINK
                db_handle = n;
                write("已经与sqlite数据库建立连接！连接号是：" + n);
                return;
#else
                return n;
#endif
        }
        else
        {
                log_error("db_connect", n);
#ifdef STATIC_LINK
                // call_out("connect_to_database", 30);
                return;
#endif
                return 0;
        }
}

protected void close_database(int db)
{
        mixed ret;

        db_handle = 0;

        if( !intp(db) || (db < 1) )
                return;

        ret = db_close(db);

        if( intp(ret) && (ret == 1) )
                return;

        else
                log_error("db_close", ret);
}

protected void create()
{
        seteuid(ROOT_UID);

#ifdef STATIC_LINK
        connect_to_database();
        set_heart_beat(1);
#endif
        crc_status = 1;
}

protected void heart_beat()
{
        if( !query_db_status() )
                connect_to_database();
}

protected int valid_caller()
{
#ifdef DEBUG
        return 1;
#else
        if( !previous_object() ||
            (previous_object() != find_object(SIMUL_EFUN_OB)) )
                return 0;

        else
                return 1;
#endif
}

// 不能增加记录，只能修改已经有的记录里存在字段的合适值
int db_remove_player(string id)
{
        int db;
        string sql;
        mixed ret;

        if( !stringp(id) || id == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = "delete from users where id='" + id + "'";
        chat("执行删除语句！" + sql);
        ret = db_exec(db, sql);
        
#ifndef STATIC_LINK
        close_database(db);
#endif

        if( !intp(ret) )
        {
                log_error("db_delete.db_exec", ret + "\n" + sql);
                return 0;
        }

        return ret;
}

// 不能增加记录，只能修改已经有的记录里存在字段的合适值
int db_set_player(string id, string prop, mixed value)
{
        int db;
        string sql;
        mixed ret;
        if( !stringp(id)   || id  == "" ||
            !stringp(prop) || prop == "")
                return 0;
        if( member_array(prop, cols) == -1 )
                return 0;
        if( prop == "login_dbase" && (value == 0 ||
            !stringp(value) || sizeof(value) < 2 ) )
                return 0;
#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif
        // 对于不同类型的属性应该有不同的设置手段，分整型，MAPP，数组
        if( intp(value) )
                sql = "update users set " + prop + "=" + value + " where id = '" + id + "'";
        else if( mapp(value) || arrayp(value) )
                sql = "update users set " + prop + "=" + DB_STR(save_variable(value)) + " where id = '" + id + "'";
        else if( stringp(value) )
                sql = "update users set " + prop + "=" + DB_STR(value) + " where id = '" + id + "'";
        else
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                write("数据库函数db_set的参数value类型不可识别！\n");
                return 0;
        }   
        ret = db_exec(db, sql);
		//write(sql+"\n");
#ifndef STATIC_LINK
        close_database(db);
#endif

        if( !intp(ret) )
        {
                log_error("db_set.db_exec", ret + "\n" + sql);
                return 0;
        }

        return ret;
}

mixed db_query_player(string id, string prop)
{
        int db;
        string sql,*res;
        mixed ret;

        if( !stringp(id)   || id  == "" ||
            !stringp(prop) || prop == "")
                return 0;

        if( member_array(prop, cols) == -1 &&
            prop != "count(*)" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = "select " + prop + " from users where id='" + id + "'";
        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error("db_query.db_exec", ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                
        res = db_fetch(db, 1);

#ifndef STATIC_LINK
        close_database(db);
#endif

        //write("查询" + id + "的" + prop + "属性字段值。返回：" + save_variable(res[0])+"\n");
        return res[0];
}

int db_new_player(object ob, object user)
{
        int db,n,total;
        string sql;
        mixed ret;
        mapping my, myob;

        if( !objectp(ob) || !objectp(user) )
                return 0;

        myob = ob->query_entire_dbase();
        my = user->query_entire_dbase();

        if( !stringp(my["id"])   || (my["id"] == "") ||
            !stringp(my["name"]) || (my["name"] == "") )
        {
                write("存储字段ID或NAME为空，拒绝存储。\n");
                return -1;
        }

#ifdef STATIC_LINK
        if( !db_handle )
        {
                write("数据库失去连接。\n");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        // 不判断数据库里是否已经有该项记录
        // fee_time不在这里做修改，故不存储了
		total = my["str"]+my["int"]+my["con"]+ my["dex"]+my["per"]+my["kar"]+my["cor"]+my["spi"];
		if (DB_TYPE=="sqlite") 
		{
			sql = "insert into users (id,username,password,inborn,brithday,online,on_time,login_dbase,user_dbase) values ('" + my["id"] + "',"+ DB_STR(my["name"])+","+
               DB_STR(myob["password"]);
			sql += ","+total;
			sql += ",datetime('now','localtime'),1,0";
			sql += "," + DB_STR(save_variable(myob));
			sql += "," + DB_STR(save_variable(my))+")";
		} else {
        sql = "insert into users set id = '" + my["id"] + "',";
        sql += "username = " + DB_STR(my["name"]) + ", password = " +
               DB_STR(myob["password"]) ;
        sql += ", birthday = now(), online = 1, on_time = 0";
		sql += ", inborn = " + total;
        sql += ", login_dbase = " + DB_STR(save_variable(myob));
        sql += ", user_dbase = " + DB_STR(save_variable(my));
		}
        //write("请求数据库创建帐号！\n");
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif 
                write("数据库存储失败!!!\n");
                log_error(sprintf("db_new_player(%s).db_exec", my["id"]), ret);
                return -1;
        }
        ;
        
#ifndef STATIC_LINK
        close_database(db);
#endif        

        return ret;
}

int db_restore_all(object user)
{
        int db, n;
        string sql, *res;
        mixed ret;
        mapping my;
        object myob;

        myob=user->query_temp("link_ob");
        my = user->query_entire_dbase();

        if( !mapp(my) || !stringp(my["id"]) || (my["id"] == "") ||
            !stringp(my["name"]) || (my["name"] == "") )
        {
                write("存储字段ID或NAME为空，拒绝存储。");
                return -1;
        }

#ifdef STATIC_LINK
        if( !db_handle )
        {
                write("数据库失去连接。");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        sql = "select login_dbase, autoload, user_dbase, ghost, condition, " +
              "skills, alias,username from users where id = '" + my["id"] + "'";

        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif 
                write("数据库存储失败!!!");
                log_error(sprintf("db_restore_all(%s).db_exec",my["id"]),ret);
                return -1;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif 
				 write(my["id"]+"数据库存储失败1!!!");
                return 0;
        }
                
        res = db_fetch(db, 1);
        if( sizeof(res) < 1 ) {
                n = 0;
			write("没有数据!!!");
		}
        else
        {
                string login_dbase, autoload, user_dbase, ghost;
                string condition, skills, alias,username;

                n = 0;
                login_dbase = res[n];
                autoload = res[n + 1];
                user_dbase = res[n + 2];
                //f_dbase = replace_string(f_dbase, "\\n", "\\"+"\\n");          // Added by Lonely 2011/6/10
                ghost = res[n + 3];
                condition = res[n + 4];
                skills = res[n + 5];
                alias = res[n + 6];
                username = res[n + 7];
                user->set_dbase(restore_variable(user_dbase));
                user->set_autoload_info(restore_variable(autoload));
                user->set_CONDITION(restore_variable(condition));
                user->set_ALIAS(restore_variable(alias));
                user->set_ghost(restore_variable(ghost));
                user->set_SKILL(restore_variable(skills));
                if( objectp(myob)) myob->set_dbase(restore_variable(login_dbase));
                n = 1;
        }
#ifndef STATIC_LINK
        close_database(db);
#endif
        return n;
}

int db_save_all(object user)
{
        int db, n;
        string sql;
        mixed ret;
        mapping my, myob;
        object link_ob=user->query_temp("link_ob");

        if( objectp(link_ob) )
                myob = link_ob->query_entire_dbase();

        my = user->query_entire_dbase();

        if( !stringp(my["id"])   || (my["id"] == "") ||
            !stringp(my["name"]) || (my["name"] == "") )
        {
                write("存储字段ID或NAME为空，拒绝存储。");
                return -1;
        }

#ifdef STATIC_LINK
        if( !db_handle )
        {
                write("数据库失去连接。");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        // 不判断数据库里是否已经有该项记录
        // fee_time不在这里做修改，故不存储了
        sql = "update users set ";
        sql += "username = " + DB_STR(my["name"]);

        if( objectp(link_ob) && mapp(myob) )
        {
                if( sizeof(myob["password"]) )
                        sql += ", password=" + DB_STR(myob["password"]);
                sql += ", login_dbase = " + DB_STR(save_variable(myob));
        }
        if( my["on_time"] > 0 ) // 认为已经挪移到on_time计费了
                sql += ", online = 1, on_time = " + my["on_time"] + ", save_time = datetime('now','localtime')"; //mysql 这里是now()
        else
        {
                sql += ", online = 1, on_time = " + my["mud_age"] + ", save_time = datetime('now','localtime')";//mysql 这里是now()
                // my["on_time"] = my["mud_age"]; 因为要重新计算sec_id，所以这里不能这样做
        }
        
        sql += ", autoload = " + DB_STR(save_variable(user->query_autoload_info()));
        sql += ", user_dbase = " + DB_STR(save_variable(my));
        sql += ", ghost = " + DB_STR(save_variable(user->is_ghost()));
        sql += ", condition = " + DB_STR(save_variable(user->query_CONDITION()));
        sql += ", skills = " + DB_STR(save_variable(user->query_SKILL()));
        sql += ", alias = " + DB_STR(save_variable(user->query_all_alias()));
        sql += " where id = '" + my["id"] + "'";
        ret = db_exec(db, sql);
		 //write(sql+"\n");
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                write("数据库存储失败!!!" + sql);
                log_error(sprintf("db_save_all(%s).db_exec", my["id"]), ret);
                return -1;
        }
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

string *do_sql(string sql)
{
        int db;
        string *res;
        mixed ret;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        ret = db_exec(db,sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error("do_sql.db_exec", ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                
        //只返回首行
        res = db_fetch(db, 1);
        
#ifndef STATIC_LINK
        close_database(db);
#endif

        return res;
}

// 查询 ID 是否存在
int db_find_user(string key, mixed data)
{
        int db;
        mixed ret;
        string sql;

        if( !stringp(key) || key == "" || !data )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        if( intp(data) )
                sql = sprintf("SELECT id FROM %s WHERE %s = %s",
                              USER_TABLE, key, data);
        else if( stringp(data) )
                sql = sprintf("SELECT id FROM %s WHERE %s = \"%s\"",
                              USER_TABLE, key, data);
        else sql = sprintf("SELECT id FROM %s WHERE %s = %O",
                           USER_TABLE, key, data);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
        close_database(db);
#endif

        if( !intp(ret) )
        {
                log_error("db_find_user.db_exec", ret);
                return 0;
        }

        return ret;
}

// 创建新的用户
int db_create_user(string id)
{
        int db;
        mixed ret;
        string sql;

        if( !stringp(id) || id == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif
		if (DB_TYPE=="sqlite")
			sql = sprintf("INSERT INTO %s (id) values(\"%s\")",
                      USER_TABLE, id);
		else
			sql = sprintf("INSERT INTO %s SET id = \"%s\"",
                      USER_TABLE, id);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
        close_database(db);
#endif

        if( !intp(ret) )
        {
                log_error("db_create_user.db_exec", ret);
                return 0;
        }

        return ret;
}

// 删除用户
int db_remove_user(string id)
{
        int db, n;
        mixed ret;
        string sql;

        if( !stringp(id) || id == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",
                      USER_TABLE, id);
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error(sprintf("db_romove_user(%s).db_exec", id), ret);
                return 0;
        }


#ifndef STATIC_LINK
        close_database(db);
#endif                
        return ret;
}

// 设定用户属性
int db_set_user(string id, string key, mixed data)
{
        int db, n;
        mixed ret;
        string sql;

        if( !stringp(id)  || id  == "" ||
            !stringp(key) || key == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        if( intp(data) )
                sql = sprintf("UPDATE %s SET %s = %d WHERE id = \"%s\"",
                              USER_TABLE, key, data, id);
        else if( stringp(data) )
                sql = sprintf("UPDATE %s SET %s = \"%s\" WHERE id = \"%s\"",
                              USER_TABLE, key, data, id);
        else sql = sprintf("UPDATE %s SET %s = %O WHERE id = \"%s\"",
                           USER_TABLE, key, data, id);
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error(sprintf("db_set_user(%s).db_exec", id), ret);
                return 0;
        }

#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

// 增加用户属性点
int db_add_user(string id, string key, int num)
{
        int db, n;
        mixed ret;
        string sql;

        if( !stringp(id)  || id  == "" ||
            !stringp(key) || key == "" ||
            !intp(num)    || !num )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = sprintf("UPDATE %s SET %s = %s + %d WHERE id = \"%s\"",
                      USER_TABLE, key, key, num, id);
        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error(sprintf("db_add_user(%s).db_exec", id), ret);
                return 0;
        }

        
#ifndef STATIC_LINK
        close_database(db);
#endif
        
        return ret;
}

// 查询用户属性
mixed db_query_user(string id, string key)
{
        int db;
        mixed ret, *res;
        string sql;

        if( ! stringp(id)  || id  == "" ||
            ! stringp(key) || key == "")
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = sprintf("SELECT %s FROM %s WHERE id = \"%s\"",
                      key, USER_TABLE, id);
        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                log_error("db_query_user.db_exec", ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                         
        res = db_fetch(db, 1);
#ifndef STATIC_LINK
        close_database(db);
#endif 
        return res[0];
}

// 加密函数
mixed db_crypt(string passwd)
{
        int db;
        mixed res, ret;
        string sql;

        if( !stringp(passwd) || passwd == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = sprintf("SELECT %s(\"%s\")",
                      DB_CRYPT, passwd);

        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif 
                log_error("db_crypt.db_exec", ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                
        res = db_fetch(db, 1);

#ifndef STATIC_LINK
        close_database(db);
#endif 

        return ret[0];
}

// 查找一行
varargs mixed *db_fetch_row(string sql, int row)
{
        int db;
        mixed ret;

        if( !stringp(sql) || sql == "")
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        if( stringp(sql) && sql != "" )
        {
                db_exec(db, sql);
        }

        if( !row ) row = 1;
        ret = db_fetch(db, row);
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

// 执行语句
mixed db_query(string sql)
{
        int db;
        mixed ret;

        if( !stringp(sql) || sql == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        ret = db_exec(db, sql);

        if( !intp(ret) )
                ret = 0;

#ifndef STATIC_LINK
        close_database(db);
#endif

        return ret;
}

// 查找所有行
mixed *db_all_query(string sql)
{
        int db, i;
        mixed max, ret;

        if( !stringp(sql) || sql == "" )
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        max = db_exec(db, sql);
        
        if( !intp(max) || max < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                     
        ret = ({ });
        for( i = 1; i <= max; i++ )
                ret += ({ db_fetch(db, i) });

#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

// 计算玩家数量
int db_count_user()
{
        int db;
        mixed ret, res;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        ret = db_exec(db, sprintf("SELECT COUNT(*) FROM %s", USER_TABLE));
        //ret = db_exec(db, sprintf("SELECT MAX(id) FROM %s", USER_TABLE));
        if( !intp(ret) || (ret < 1) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }

        res = db_fetch(db, 1);
                
#ifndef STATIC_LINK
        close_database(db);
#endif

        return res[0];
}

int db_remove_item(string id)
{
        int db;
        string sql;
        mixed ret;

        if( !stringp(id) || id == "")
                return 0;

        sscanf(id, "%s.c", id);

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif

        sql = "delete from items where id='" + id + "'";
        chat("执行删除语句！" + sql);
        ret = db_exec(db, sql);

#ifndef STATIC_LINK
        close_database(db);
#endif

        if( !intp(ret) )
        {
                log_error("db_remove_item.db_exec", ret + "\n" + sql);
                return 0;
        }
                
        return ret;
}

mixed db_restore_item(mixed ob)
{
        int db;
        string sql, *res;
        string index;
        mixed ret;
        mapping data = ([]);

        if( !ob ) return 0;              

        if( stringp(ob) )
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } 
        else if( objectp(ob) )
                index = base_name(ob);
        else
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif
        
        sql = "select dbase from items where id = '" + index + "'";

        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                chat("数据库存储失败!!!");
                log_error(sprintf("db_restore_item(%s).db_exec", index), ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                
        res = db_fetch(db, 1);
#ifndef STATIC_LINK
        close_database(db);
#endif
        if( !res[0] ) return 0;
        if( mapp(restore_variable(res[0])) )
                data = restore_variable(res[0]);

        return data;
}

mixed db_restore_skill(mixed ob)
{
        int db;
        string sql, *res;
        string index;
        mixed ret;
        mapping data = ([]);

        if( !ob ) return 0;
        
        if( stringp(ob) )
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } 
        else if( objectp(ob) )
                index = base_name(ob);
        else
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return 0;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return 0;
#endif
        
        sql = "select skill from items where id = '" + index + "'";

        ret = db_exec(db, sql);

        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                chat("数据库存储失败!!!");
                log_error(sprintf("db_restore_item(%s).db_exec", index), ret);
                return 0;
        }
        
        if( ret < 1 )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                return 0;
        }
                
        res = db_fetch(db, 1);
#ifndef STATIC_LINK
        close_database(db);
#endif        
        if( !res[0] ) return 0;
        if( mapp(restore_variable(res[0])))
                data = restore_variable(res[0]);

        return data;
}

int db_create_item(mixed ob, mixed data)
{
        int db, n;
        string sql;
        string index;
        mixed ret;

        if( !ob ) return 0;

        if( stringp(ob) )
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } 
        else if( objectp(ob) )
                index = base_name(ob);
        else
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        sql = "insert into items set id = '" + index +
              "', dbase = " + DB_STR(save_variable(data));
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                chat("数据库存储失败!!!" + sql);
                log_error(sprintf("db_create_item(%s).db_exec", index), ret);
                return -1;
        }
        
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

int db_save_item(mixed ob, mixed data)
{
        int db, n;
        string sql;
        string index;
        mixed ret;

        if( !ob ) return 0;               

        if( stringp(ob) )
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } 
        else if( objectp(ob) )
                index = base_name(ob);
        else
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        /*
        sql = "select dbase from items where id = '" + index + "'";
        ret = db_exec(db, sql);
        if( ! intp(ret))
                sql = "insert into items set id = '" + index +
                      "', dbase = " + DB_STR(save_variable(data));
        else
        */
        sql = "update items set dbase = " + DB_STR(save_variable(data)) +
              " where id = '" + index + "'";
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                chat("数据库存储失败!!!" + sql);
                log_error(sprintf("db_save_item(%s).db_exec", index), ret);
                return -1;
        }

#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

int db_save_skill(mixed ob, mixed data)
{
        int db,n;
        string sql;
        string index;
        mixed ret;

        if( !ob ) return 0;              

        if( stringp(ob) )
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } 
        else if( objectp(ob) )
                index = base_name(ob);
        else
                return 0;

#ifdef STATIC_LINK
        if( !db_handle )
        {
                chat("数据库失去连接。");
                return -1;
        }
        db = db_handle;
#else
        if( !(db = connect_to_database()) )
                return -1;
#endif

        sql = "update items set skill = " + DB_STR(save_variable(data)) +
              " where id = '" + index + "'";
        ret = db_exec(db, sql);
        if( !intp(ret) )
        {
#ifndef STATIC_LINK
                close_database(db);
#endif
                chat("数据库存储失败!!!" + sql);
                log_error(sprintf("db_save_item(%s).db_exec", index), ret);
                return -1;
        }

#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

void broadcast(string sql)
{
	if( !all_target || !sizeof(all_target) )
		return;

	foreach(class target one in all_target)
		one->quest += ([ sql : 0 ]);

	if( find_call_out("do_broadcast") == -1 )
		call_out("do_broadcast",3);
}



#ifdef STATIC_LINK
void remove(string id)
{
        /*
	if( !valid_caller() )
		return;
	*/	
        close_database(db_handle);
}
#endif

string query_name()
{
        return "MySQL数据库(DATABASE_D)";
}

#endif

