// zhizhuren.c 蜘蛛人 by netkill

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("蜘蛛人", ({ "zhizhu ren", "ren", }) );
	set("gender", "无性" );
	set("age", 20);
	set("long", "这是一个用来练功的木头蜘蛛人,形似蜘蛛。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
}
