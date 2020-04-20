// bird.c

inherit NPC;

void create()
{
	set_name("秃鹰",({ "tu ying" }));
	set("long", @LONG
一只凶猛的秃鹰，凶狠的目光正死盯着你看，准备随时向你扑来。
LONG
);
	set("race","飞禽");
	set("age", 4);
	set("attitude", "aggressive");
	set("max_qi",10000);
	set("qi",10000);
	set("max_jing",5000);
	set("jing",5000);
	set("neili",8000);
	set("max_neili",8000);
	set("combat_exp",3000000);
	set_skill("force",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_temp("apply/armor",200);
	set_temp("apply/dodge",200);
	set_temp("apply/damage",100);
	setup();
}
