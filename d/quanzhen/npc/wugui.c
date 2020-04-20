// wugui.c

inherit NPC;

void create()
{
	set_name("乌龟", ({ "wu gui", "gui" }) );
	set("race", "野兽");
	set("age", 10);
	set("long", "一只大乌龟，看来岁数不小了。\n");
	set("attitude", "peaceful");
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 1000);
	set("eatable",1);
	set("afterdie",__DIR__"obj/guijia");
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	setup();
}
