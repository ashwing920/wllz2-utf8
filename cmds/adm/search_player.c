// search.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

private void create()
{
        seteuid(getuid());
        set("channel_id", "档案精灵[Data]");
}

int help(object me)
{
write(@HELP
指令格式：search [<未上线天数>]

寻找制定范围内未上线之玩家资料档。
HELP
        );
        return 1;
}

private int do_search_players(int day);

int main(object me, string arg)
{
        string name, reason;
        string status;
        int day;
        object player;

        status = wizhood(me);

        if( me!=this_player(1)|| wiz_level(me) < wiz_level(status) )
                return notify_fail("你没有权力使用这个指令。\n");
        if( !arg ) return help(me);

        if( sscanf(arg, "%d", day) && day >= 0) return do_search_players(day);

        seteuid(getuid());

        if(SECURITY_D->get_status(name) == "(admin)")
                return notify_fail("你没有权利使用这个命令。\n");

        return 1;
}

private int do_search_players(int day)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        mixed info;
        object who;

        if(day<30) return notify_fail("天数应该大于30。\n");
        seteuid(getuid());
        LOGIN_D->set_lock(1);
        write("\n*** 整理玩家储存档中，请稍候.... ***\n");
        write("处理中：\n");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write("目录"+dir[i]+"：玩家\n");
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                // 如果使用者是巫师，不能删除。
                                if( (string)SECURITY_D->get_status(name)!="(player)" ) continue;


        who = new(LOGIN_OB);
        who->set("id", name);
        if(!who->restore()) continue;
                if( (time()-who->query("last_on"))/86400 >= day ) {
                        log_file("mail",who->query("email")+"\n");
                        write(" "+name);
                        count ++;
        }
                        destruct(who);
                }
                        write(" 被邮件地址被整理。\n");
        }
        write( count + " 个超过 " + day + " 天未上线的使用者邮件地址被记录了。\n");
        log_file("static/search",sprintf("[%s] %s 清理了 %d 个超越 %d 天没有登陆的玩家资料，剩余 %d 个玩家资料存在。\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));
	LOGIN_D->set_lock(0);
        return 1;
}