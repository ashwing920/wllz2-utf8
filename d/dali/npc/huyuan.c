// huyuan.c 护院
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(npc_name("男性"), ({ "hu yuan",}));
	set("title",HIC"大理镇南王府护院"NOR);
	set("gender", "男性" );
	set("age", 30);
	set("long", "他是大理王府的护院，大理弟子经常和他切磋武艺。\n");
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
