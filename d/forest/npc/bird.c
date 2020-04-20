// bird.c

inherit NPC;

void create()
{
	set_name("小鸟", ({ "bird" }));
	set("long", @LONG
一只小鸟。
LONG
);
	set("race","飞禽");
	set("age", 1);
	set("str", 24);		// 膂力
	set("cor", 26);		// 胆识
	set("combat_exp", 100);
	set("eatable",1);
	set("afterdie","/clone/food/bird-meat");
	set_temp("apply/attack", 0);
	set_temp("apply/armor", 0);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 100);
	setup();
}
