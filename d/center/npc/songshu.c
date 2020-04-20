// songshu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("松鼠", ({ "song shu" }));
	set("long", @LONG
一只可爱的松鼠。
LONG
);
	set("race", "野兽");
	set("age", 2);
	set("str", 24);		// 膂力
	set("cor", 26);		// 胆识
	set("combat_exp", 100);
	set("eatable",1);
	set("afterdie","/clone/food/songshu-meat");
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 2);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 50);
	setup();
}
