  // shutdown.c

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string wiz_status;
        object *user, link_ob;
        int i;

        if( me != this_player(1) ) return 0;

        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                return notify_fail("只有 (arch) 以上的巫师才能重新启动" + code_name() + "\n");

        log_file("static/shutdown.log",
               sprintf("%s(%s) do shutdown at %s \n",me->query("name"),me->query("id"),ctime(time())));
        message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

        user = users();
        for(i=0; i<sizeof(user); i++) {
                if( !environment(user[i]) ) continue;
                user[i]->save();
                link_ob = user[i]->query_temp("link_ob");
                if( objectp(link_ob) ) link_ob->save();
                user[i]->save();
        }

        if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

        shutdown(1);
        return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown

马上重新起动游戏。

HELP
);
        return 1;
}

