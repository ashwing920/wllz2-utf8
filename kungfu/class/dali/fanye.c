// fanye.c 范骅

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();

void create()
{
	set_name("范骅", ({ "fan ye", "fan" }));
	set("title",  "大理司马" );
	set("long",@LONG
他是大理国三公之一。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	

	set("jing",3000);
	set("max_jing",3000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score", 200000);

	set("inquiry", ([
		"指点武功" : (: ask_me :),
	]));

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("sword", 400);
	set_skill("staff", 400);
	set_skill("kurong-changong", 400);
	set_skill("tiannan-step", 400);
	set_skill("jinyu-quan", 400);
	set_skill("duanjia-sword", 400);
	set_skill("literate", 400);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武将");
}
#include "/kungfu/class/dali/wujiang.h";
