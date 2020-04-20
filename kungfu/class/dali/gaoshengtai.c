// gaoshengtai.c 高升泰

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();

void create()
{
	set_name("高升泰", ({ "gao shengtai", "gao" }));
	set("title",  "大理善阐侯" );
	set("long",@LONG
大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。
LONG
);
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	

	set("jing",3000);
	set("max_jing",3000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp", 6400000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("strike",400);
	set_skill("sword", 400);
	set_skill("unarmed",400);
	set_skill("finger",400);
	set_skill("kurong-changong",400);
	set_skill("tiannan-step",400);
	set_skill("jinyu-quan", 400);
	set_skill("wuluo-zhang", 400);
	set_skill("duanjia-sword", 400);
	set_skill("literate", 400);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	set("inquiry", ([
		"指点武功" : (: ask_me :),
	]));
	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
	carry_object(__DIR__"obj/tiedi")->wield();
	add_money("silver", 20);
	create_family("大理段家",19,"武将");
}

#include "/kungfu/class/dali/wujiang.h";