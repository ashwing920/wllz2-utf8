// wuguan-dizi.c - 武馆弟子
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("武馆弟子", ({ "wuguan dizi", "dizi" }) );
	set("long", @LONG
这是一位武馆弟子。
LONG
);
	set("gender", "男性" );
	set("age", random(20)+10);
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

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
	
}
