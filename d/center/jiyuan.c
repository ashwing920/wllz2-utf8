// jiyuan.c - 千金楼

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "千金楼大门");
	set("long", @LONG
这里是桃源城里最热闹的千金楼。楼里到处张灯结彩，香气扑鼻。几
个打扮得妖里妖气的女人站在门口对你暗送秋波，你一下子就明白这是什
么地方了。据说千金楼的老板背后有朝廷大官支持，连皇亲国戚都偶尔来
光顾光顾。这儿的姑娘以才貌双全著称，市侩俗气的人用再多的钱也别想
得到她们的青眸。门口竖着一块牌子(sign)，上面好象写着什么。
LONG
);

	set("item_desc", ([
		"sign": @TEXT
$HIM$		
千金楼：

１．不可夹带任何兵器进院。
２．以防您被千金楼小姐误认为没有消费能力，不可夹带任何食物，酒水进入。
３．大家出门在外是朋友，相互给点面子，打架，闹事者楼规处置。
４．＂赏头＂给得越多，您受的伺侯越好。
$NOR$
TEXT
        ]) );
	set("exits", ([
                "west": __DIR__"roadn2",
                "east": "/d/qianjinlou/main-01",
        ]) );			
        set("objects", ([
                "/d/qianjinlou/npc/pitiao-ke": 1,
                "/d/qianjinlou/npc/guinu": 1,
	]) );

	setup();
	replace_program(ROOM);
}
