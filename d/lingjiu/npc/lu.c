// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//lu.c

inherit NPC;

void create()
{
	set_name("梅花鹿", ({ "meihua lu", "lu" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只可爱的梅花鹿，它的血是大补之物。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("cor", 26);
	set("combat_exp", 3000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);
	setup();
}
