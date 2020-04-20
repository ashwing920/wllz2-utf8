// benyin.c
// xueer

inherit NPC;

#include <ansi.h>
inherit F_MASTER;

string ask_me();
string ask_sao();
string ask_over();

void create()
{
	set_name("本因", ({ "ben yin","ben","yin"}) );
	set("gender", "男性" );
	set("title", "天龙寺第十七代住持");
	set("long", "一个神情潇洒的僧人，他是天龙寺住持方丈。\n");
	set("class", "bonze");
	set("age", 43);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing", 2000);
	set("max_jing",2000);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp", 800000);
	set("score", 10000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 200);
	set_skill("sword", 200);
	set_skill("tiannan-step", 200);
	set_skill("kurong-changong", 200);
	set_skill("duanjia-sword", 200);
	set_skill("liumai-shenjian", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","liumai-shenjian");

	set("inquiry" ,([
		"舍利子" : (:ask_me():),
		"六脉神剑谱" : "“施主不会是打什么主意吧？”\n",
		"六脉神剑" :  "“施主不会是想和我较量较量吧？”\n",
		"job" : (:ask_sao():),
		"扫地" : (:ask_sao():),
		"完成" : (:ask_over():),
		"over" : (:ask_over():),
	]));

	create_family("大理段家",17,"高僧");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp0"))
		{
		me->set_temp("marks/ask_temp1",1);
		return "“那是本寺的镇寺之宝，多年以前不慎丢失。施主如能找回此物，\n	 老衲必有重谢。”\n";
		}
	else
		return "“施主不可妄言。”\n";
}

#include "ben1.h"
#include "ben.h"
