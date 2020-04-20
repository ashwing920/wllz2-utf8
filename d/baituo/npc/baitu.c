//baitu.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("白兔", ({ "bai tu", "tu" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只雪白的小白兔，可爱之致。\n");
	set("attitude", "peaceful");
	set("str", 15);
	set("cor", 16);
	set("combat_exp", 200);
	set("eatable",1);
	set("afterdie","/d/baituo/obj/turou");
	set_temp("apply/attack", 5);
	set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",2);
	setup();
}
