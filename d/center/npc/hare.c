// hare.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("野兔", ({ "hare" }));
	set("long", @LONG
一只毛色灰黄的野兔。
LONG
);
	set("race", "野兽");
	set("age", 3);
	set("str", 24);         // 膂力
	set("cor", 26);         // 胆识
	set("combat_exp", 100);
	set("eatable",1);
	set("afterdie","/clone/food/hare-meat");
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 2);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 30);
	setup();
}
