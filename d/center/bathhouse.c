// bathhouse.c - 澡  堂

#include <room.h>

inherit ROOM;

void create()
{
        set("short","华清池");
        set("long", @LONG
这里是桃源城里，最多达官贵人们出入的澡堂--华清池。华清池门口
装饰豪华，大门上方还挂着一块金字招牌。说起这间澡堂，在桃源城里开
办已经有数十年之久，澡堂内装饰别致，服务周到，来到了这里，也许应
该进去看看吧！门口竖着一块牌子(sign)，上面好象写着什么。
LONG
);
	set("item_desc",([
		"sign": @TEXT
$CYN$

为优化华清池环境，请各位客倌遵守以下规则：
$MAG$
1、为保持您的尊贵形象，请勿在华清池内大声喧哗，吵闹。
2、华清池乃高雅的澡堂，请勿赤身裸露在澡堂内奔跑，走动。
3、华清池内不欢迎色狼、狗，尼姑、和尚。
$CYN$
				华清池
$NOR$
TEXT
	]));
        set("exits", ([
                "east"  : __DIR__"roadn3",
                "enter" : __DIR__"bathhouse_m",
        ]) );                   
        set("objects", ([
                __DIR__"npc/laoban-zt": 1,
        ]) );

        setup();

}
int valid_leave(object me,string dir)
{
        if (!me->query_temp("give_wash_money") && present("lao ban",environment(me))
        &&      dir == "enter")
                return notify_fail("澡堂老板挡在门口，说道：华清池内谢绝参观。\n");
                
        if ( me->query_temp("give_wash_money") && present("lao ban",environment(me)) && dir != "enter" )
        me->delete_temp("give_wash_money");
        return ::valid_leave(me, dir);

}
