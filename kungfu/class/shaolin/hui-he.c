// Npc: /kungfu/class/shaolin/hui-he.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("慧合尊者", ({"huihe zunzhe","huihe","zunzhe",}));
	set("long",@LONG
他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，太阳穴
微凸，双目炯炯有神。
LONG
);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("max_jing",1000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp",2700000);
	set("score", 100);

	set_skill("force", 300);
	set_skill("hunyuan-yiqi", 300);
	set_skill("dodge", 300);
	set_skill("shaolin-shenfa", 300);
	set_skill("finger", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("damo-jian", 300);
	set_skill("buddhism", 300);
	set_skill("literate", 300);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("finger", "nianhua-zhi");

	create_family("少林派", 38, "弟子");

	set("inquiry", ([
		"买铁" :	(: ask_me :),
	]));

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

#include "/kungfu/class/shaolin/hui.h"

string ask_me()
{
	return "买铁？ 他现在又不缺铁！ 前天老乔不是刚送来一堆铁块，铁手掌什麽的给他吗？！";
}
