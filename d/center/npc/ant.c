// ant.c

inherit NPC;

void create()
{
	set_name("蚂蚁", ({ "ant" }));
	set("long", @LONG
一只爬来爬去的蚂蚁。
LONG
);
	set("race","昆虫");
	set("subrace","爬虫");
	set("age", 1);
	set("str", 24);		// 膂力
	set("cor", 26);		// 胆识
	set("combat_exp", 100);
	set_temp("apply/attack", 0);
	set_temp("apply/armor", 0);
	set_temp("apply/damage", 1);
	set_temp("apply/dodge", 0);
	setup();
}
