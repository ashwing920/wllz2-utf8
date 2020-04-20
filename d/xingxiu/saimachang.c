// room: /d/xingxiu/saimachang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "赛马场");
        set("long", @LONG
这里是小镇的赛马场。场上正在举行维吾尔族的「姑娘追」表演。一
个小伙子可以找一个姑娘并骑慢驰到一处折返点。去的路上小伙子可以对
姑娘随便挑逗。回来时姑娘则可以用鞭子抽打小伙子。当然，如果姑娘喜
欢这个小伙子，落鞭就会轻些。否则的话，有小伙子好受的。马场上还有
几个人在练马[lianma]呢！
LONG
);
        set("exits", ([
                 "southeast" : __DIR__"beijiang",]));
        set("outdoors", "xingxiuhai");
        set("objects", ([
                __DIR__"npc/alamuhan" : 1,
        ]) );
        setup();
}

void init()
{
        add_action("do_lianma","lianma");
}
int do_lianma(string arg)
{
        object me, ob;
        int cost, high, low, n;

        me = this_player();

        if( !arg || !sscanf(arg, "%d", cost) )
                return notify_fail("指令格式 : lianma <花费的精和神的值>\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法练马。\n");

        if( cost < 10 )
                return notify_fail("你最少要花 10 点「精」和「气」。\n");

        if( (int)me->query("jing") < cost || (int)me->query("qi") < cost )
                return notify_fail("你现在的「精」或「气」太少了。\n");

        if( !me->query("make_horse/finish"))
                return notify_fail("你现在没有独门坐骑。\n");

        if ( !objectp( ob = present( "my horse", me ) ) )
                return notify_fail("你现在没有独门坐骑。\n");

        if ( ob->query("equipped") )
                return notify_fail("你必须跳下「" + ob->name() + "」。\n");

        high = me->query("make_horse/points_high");
        low  = me->query("make_horse/points_low");
        low += cost;
        if( low > 1000 ) {
                high += low / 1000;
                low  %= 1000;
        }

        if( high >= pow( 2.0, me->query( "make_horse/max_life" ) / 5.0 + 1.0 ) ) {
                high = 0; low = 0;
                me->add("make_horse/max_life", 1);
                ob->init();
                ob->set_up();
                tell_object(me, WHT "你的「" + me->query("make_horse/name") + WHT "」升级了！\n" NOR);
                tell_object(me, WHT "「" + me->query("make_horse/name") + WHT "」的最大生命值是："
                        + chinese_number( me->query("make_horse/max_life") ) + "。\n" NOR);
        }
        else {
                n = high * 100 / pow( 2.0, me->query( "make_horse/max_life" ) / 5.0 + 1.0 );
                tell_object(me, WHT "「" + me->query("make_horse/name") + WHT "」的完成度是：百分之"
                        + chinese_number( n ) + "。\n" NOR);
        }

        me->set("make_horse/points_high", high);
        me->set("make_horse/points_low", low);

        tell_object(me, "你开始训练「" + ob->name() + "」....\n");

        me->receive_damage("jing", cost);
        me->receive_damage("qi", cost);
        me->start_busy(1);
        return 1;
}
