// zhudanchen.c 朱丹臣

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
int ask_for_toushen();
void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu" }));
	set("title",  "大理护卫" );
	set("long", @LONG
他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);

	set("jing",3000);
	set("max_jing",3000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);
	set("score", 10000);

	set("inquiry",([
		"投身"	: (: ask_for_toushen :),
		"toushen" : (: ask_for_toushen :),
		"指点武功" : (: ask_me :),
	]));

	set_skill("force",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("cuff", 200);
	set_skill("sword",200);
	set_skill("staff",200);
	set_skill("kurong-changong",200);
	set_skill("tiannan-step",200);
	set_skill("jinyu-quan", 200);
	set_skill("duanjia-sword",200);
	set_skill("literate",200);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object(__DIR__"obj/diaogan")->wield();
	add_money("silver", 10);

	create_family("大理段家",19,"护卫");
}
int ask_for_toushen()
{
	object me;

	me = this_player();

	if( (string)me->query("gender") == "无性"){
		command("say 公公？我们府里不收公公。");
		return 1;
	}
	if( (int)me->query_str() < 20){
		command("say 这位" + RANK_D->query_respect(me)+ "这么文弱，怎么能在府里承值？");
		return 1;
	}
	command("say 这位" + RANK_D->query_respect(me)+ "就委屈你先在府里听用吧。\n");
	me->set("dali_title","大理镇南王府家奴");
	return 1;
}

#include "/kungfu/class/dali/weishi.h"; 