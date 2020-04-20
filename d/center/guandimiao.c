// guandimiao.c 关帝庙
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "关帝庙");
	set("long", @LONG
这里是桃源城里的关帝庙，每逢正月十五，关帝庙里便是人头攒攒，
进香拜关帝的人更是络绎不绝。只见关帝庙中有一个香案，一个红脸的菩
萨端坐香案之上，他便是传说中的关帝老爷了。关帝庙两旁的墙壁已经被
长年的香火熏得乌黑，可以看出，这里香火极为旺盛。旁边竖着一块牌子
(sign)，好象写着什么。
LONG
);
	set("exits", ([
		"south"  : __DIR__"roadn5",
	]) );
	set("objects", ([
		__DIR__"npc/jinxiangke": 4,
	]) );
	set("item_desc",([
		"sign":@TEXT
$MAG$

心诚则灵！拜(mobai)关帝者，可化杀气为祥和！

$NOR$
TEXT
	]));
	set("restrict_action", 1);
	set("no_sleep_room",1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("no_steal", 1);
	set("no_beg",1);
	setup();

}

void init()
{
	add_action("do_mobai", "mobai");
}

int do_mobai()
{
	object me;
	me = this_player();

	if((int)me->query("jing") <= 50)
		return notify_fail("你的精不够。\n");

	if((int)me->query("bellicosity") < 1)
		return notify_fail("你耳边似乎传来一个声音说道：心诚则灵！\n");

	message_vision("$N虔诚地跪在关帝塑像前磕了个头。\n" ,me);

	me->receive_damage("jing",50);

	if(me->query("bellicosity") > 10)
		me->add("bellicosity", - (me->query("bellicosity") / 5) - 1);
	else
		me->set("bellicosity",0);

	write(HIC"你的杀气降低了，心中一片祥和！\n"NOR);
	return 1;
}
