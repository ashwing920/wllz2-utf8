// master.c
// Design By robert 蝴蝶君 robert_st@sian.com

//#pragma optimize
//#pragma save_binary
#include <config.h>
#include <localtime.h>
nosave int DEBUG = 0;

private void create()
{
	write("master：加载成功！\n");
}
mixed valid_database(object caller, string func, mixed *info)
{
    if(DEBUG){
        debug_message("[MASTER_OB]->valid_database():");
        debug_message("([caller : " + file_name(caller) + ", func : " + func + "])");
    }
    if (func == "connect")
        return "secret"; // mysql数据库密码
    else
        return 1;
}
private object connect(int port)
{
	object login_ob;
	mixed err;
	err = catch(login_ob = new(LOGIN_OB));

	if (err) {
		write("现在有人正在修改使用者连线部份的程式，请待会再来。\n");
		write(err);
		destruct(this_object());
	}
	if (port == 2000)
    {
        set_encoding("GBK");
    }
	if (port == 2002)
    {
        login_ob->set_temp("webclient",1);
    }
	return login_ob;
}
private mixed compile_object(string file)
{
	object daemon;
	if( daemon = find_object(VIRTUAL_D) )
		return daemon->compile_object(file);
	else
		return 0;
}
private void crash(string error, object command_giver, object current_object)
{
	mixed cmds;
	int i;
	foreach (object player in users()){
		player->save();
	   tell_object(player,"系统核心发出一声惨叫：哇—哩—咧—\n系统核心告诉你：要当机了，自己保重吧！\n");
	}
	log_file("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +", error: " + error + "\n");
		if (command_giver){
		log_file("static/CRASHES",
			sprintf("this_player：%s(%s)，最后命令：%s，%s\n",
			command_giver->name(1),command_giver->query("id"),command_giver->process_input("!0"),
			command_giver->process_input("!1")));
			cmds = command_giver->query_commands();
		for(i = 0; i<sizeof(cmds); i++) {
				if( cmds[i][2]==command_giver ) continue;
		log_file("static/CRASHES",sprintf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]));
	}
		if (environment(command_giver))
		log_file("static/CRASHES", sprintf( "所在地：%s(%s),\n",
			environment(command_giver)->query("short"),base_name(environment(command_giver)) ));
	}
	if (current_object)
		log_file("static/CRASHES",sprintf( "this_object: %O\n", current_object));
}

protected string *update_file(string file)
{
	string *list;
	string str;
	int i;

	str = read_file(file);
	if (!str)
		return ({});
	list = explode(str, "\n");
	for (i = 0; i < sizeof(list); i++) {
		if (list[i][0] == '#') {
			list[i] = 0;
		}
	}
	return list;
}
protected string *epilog(int load_empty)
{
	string *items;

	items = update_file(CONFIG_DIR + "preload");
	return items;
}
protected void preload(string file)
{
	int t1;
	string err;
	if (file_size(file + ".c") == -1) return;
	t1 = time();
	write("Preloading : " + file );
	err = catch(call_other(file, "??"));
	if (err)
		write(" -> Error " + err + " when loading " + file + "\n");
	else
		write(".... Done.\n");

}
protected void log_error(string file, string message)
{
	string name, home;

	if( find_object(SIMUL_EFUN_OB) )
		name = file_owner(file);

	if (name) home = user_path(name);
	else home = LOG_DIR;

	if(this_player(1)) efun::write("编译时段错误：" + message+"\n");

	efun::write_file(home + "log", message);
}
protected int save_ed_setup(object who, int code)
{
	string file;

	if (!intp(code))
	return 0;
	file = user_path(getuid(who)) + ".edrc";
	rm(file);
	return write_file(file, code + "");
}
private int retrieve_ed_setup(object who)
{
	string file;
	int code;

	file = user_path(getuid(who)) + ".edrc";
	if (file_size(file) <= 0) {
		return 0;
	}
	sscanf(read_file(file), "%d", code);
	return code;
}

void destruct_env_of(object ob)
{
	if (! userp(ob)) return;
	tell_object(ob, "你所存在的空间被毁灭了。\n");
	ob->move(VOID_OB);
}
protected string make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query("cwd"), file);
	return file;
}
protected string get_save_file_name(string fname)
{
	return fname + "." + time();
}

protected string get_root_uid()
{
	return ROOT_UID;
}

protected string get_bb_uid()
{
	return BACKBONE_UID;
}

protected string creator_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
	int i, s;
	string res;

	res = (caught) ? "错误讯息被拦截: " : "";
	res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件: %s\n",
	res, error["error"],
	error["program"], error["line"],
	file_name(error["object"]));

	for (i=0, s = sizeof(error["trace"]); i < s; i++) {
		res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
		res,
		error["trace"][i]["program"],
		error["trace"][i]["function"],
		error["trace"][i]["line"],
		error["trace"][i]["object"] );
	}
	return res;
}

string error_handler( mapping error, int caught )
{
	if (this_player(1)) {
		this_player(1)->set_temp("error", error);
		tell_object(this_player(1), standard_trace(error, caught));
	}

	return standard_trace(error, caught);
}

int valid_shadow( object ob ) { return 0; }
int valid_override( string file, string name )
{
	// simul_efun can override any simul_efun by Annihilator
	if (file == SIMUL_EFUN_OB || file == MASTER_OB)
		return 1;

	// Must use the move() defined in F_MOVE.
	if ((name == "move_object") && file != F_MOVE && file != F_COMMAND)
		return 0;

	if ((name == "destruct") && ! sscanf(file, "/adm/simul_efun/%s", file))
		return 0;

	//  may also wish to protect destruct, shutdown, snoop, and exec.
	return 1;
}
protected int valid_seteuid( object ob, string str )
{
	return (int)SECURITY_D->valid_seteuid( ob, str );
}
protected int valid_socket( object eff_user, string fun, mixed *info )
{
	return 1;
}
protected int valid_asm( string file )
{
	return 1;
}
protected int valid_save_binary( string filename )
{
	return 1;
}
protected int valid_compile_to_c( string file )
{
	return 1;
}
protected int direct_run_binary( string file )
{
	return 1;
}
protected int valid_hide( object who )
{
	return 1;
}
protected int valid_object( object ob )
{
	return (!clonep(ob)) || inherits(F_MOVE, ob);
}
protected int valid_link( string original, string reference )
{
	return 0;
}
protected int valid_write( string file, mixed user, string func )
{
	object ob;

	if( ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_write(file, user, func);

	return 0;
}
protected int valid_read( string file, mixed user, string func )
{
	object ob;
	if(ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_read(file, user, func);
	return 1;
}
string object_name(object ob)
{
	if(ob) return ob->name();
}

int valid_bind(object binder, object old_owner, object new_owner)
{
	object ob;

	if (ob = find_object(SECURITY_D))
		return (int)ob->valid_bind(binder, old_owner, new_owner);

	return 1;
}
