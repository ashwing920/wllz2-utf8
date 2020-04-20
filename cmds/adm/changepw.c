//changepw.c

#include <login.h>;
inherit F_CLEAN_UP;

void create() {seteuid(getuid());}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;
        if(!arg||sscanf(arg,"%s %s",id,password)!=2)
                return notify_fail("你要更改谁的密码？更改密码之前请三思一定要得到其本人同意\n");
        ob=find_player(id);
        if(!ob){
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() ) return notify_fail("没有这个玩家。\n");
        if( wizardp(ob)) return notify_fail("对不起，目前不开放修改巫师密码！\n");
        else
        {
#ifdef  ENABLE_MD5_PASSWORD
	ob->set("password",crypt(password,sprintf("$1$%d", random(99999999))));
#else
	ob->set("password",crypt(password,0));
#endif

                tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")+ ")的密码已经更改为："+password+"。\n");
                ob->save();
                destruct(ob);
                return 1;
        }
         
}
        link_ob=ob->query_temp("link_ob"); 
        if( wizardp(ob)) return notify_fail("对不起，目前不开放修改巫师密码！\n");
        if(link_ob){
#ifdef  ENABLE_MD5_PASSWORD
	link_ob->set("password",crypt(password,sprintf("$1$%d", random(99999999))));
#else
	link_ob->set("password",crypt(password,0));
#endif
                link_ob->save();
                tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")+ ")的密码已经更改为："+password+"。\n");
                log_file("static/changepw",sprintf("%s（%s） change %s（%s）password at %s。\n",
                        me->name(),me->query("id"),ob->name(),ob->query("id"),ctime(time())));
                return 1;
        }
        else
                return notify_fail("错误。无法进行修改。\n");
        return 1;
}


int help(object me)

{
        write(@HELP
指令格式 : changepw ID
 
这个指令可以修改玩家的密码，请谨慎使用。
 
HELP
    );
    return 1;
}


