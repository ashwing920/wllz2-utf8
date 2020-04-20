// fly.c

inherit NPC;

void create()
{
	set_name("苍蝇", ({ "fly" }));
	set("long", @LONG
一只飞来飞去的苍蝇。
LONG
);
	set("race","昆虫");
	set("subrace","飞虫");
	set("age", 1);
	set("str", 24);		// 膂力
	set("cor", 26);		// 胆识
	set("combat_exp", 100);
	set_temp("apply/attack", 0);
	set_temp("apply/armor", 0);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 80);
	setup();
}
