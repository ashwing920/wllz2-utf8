//ride.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_ride(object me, object ob);

private void create() { seteuid(getuid()); }

private string *banned_race = ({
        "鼠","猴","蝴蝶","鸟","蚁","蛇","苍蝇","蛐蛐","兔","狗","麻雀",
        "狼","虎","熊","蟒","竹叶青蛇",
});

int main(object me, string arg)
{
        object obj, env;
        string name;
        int i;

        if( !arg )
                return notify_fail("你要骑什么东西？\n");

        if( me->query_temp("is_riding") || objectp(me->query_temp("ride_ob")))
                return notify_fail("你已经有座骑了！\n");

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        if( me->is_fighting() )
                return notify_fail("你还在战斗中。\n");

        // Check if a container is specified.
        env = environment(me);

        if( !objectp(obj = present(arg, env)) || !living(obj) )
                return notify_fail("这里没有这样东西可骑。\n");

        if( !obj->query("ridable") )
                return notify_fail("这个东西你也要骑？当心你的屁股！\n");

        if( obj->query("must_money"))
                return notify_fail("骑"+ obj->name()+"可是要付钱的呀！\n");

        name = obj->query("name");
        for(i=0; i<sizeof(banned_race); i++) {
                if( strsrch(name, banned_race[i]) == -1) continue;
                return notify_fail(obj->name()+"无法承受你的体重。\n");
        }

        return do_ride(me, obj);
}

int do_ride(object me, object obj)
{

        object  *guard;

        if( !obj ) return 0;

        if( guard = obj->query_temp("guarded") ) {
                guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
                if( sizeof(guard) )
                        return notify_fail( guard[0]->name()
                                + "正守在" + obj->name() + "一旁，防止任何人骑走。\n");
        }

        if( obj->move(me) )
        {
                message_vision( "$N飞身跃上$n，身手很是矫捷。\n", me, obj );
                obj->set_temp("is_rided_by", me->query("id"));
                me->set_temp("is_riding", obj->query("name"));
                me->set_temp("ride_ob",obj);
                obj->set("equipped","horse");
        }
        else
        {
                message_vision( "$N身上带的东西太重了，无法骑到$n身上去。\n", me, obj );
        }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : ride | qi <生物名>

这个指令可以让你骑上代步的已驯养的动物。

HELP
    );
    return 1;
}
