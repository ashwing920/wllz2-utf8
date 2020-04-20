// qingyun.c

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("青云", ({ "qingyun", "shizhe" }));
	set("long",@LONG
他是掌门人的得意门生，一个十分厉害的神秘人物。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("str", 35);
	set("int", 28);
	set("con", 30);
	set("dex", 28);

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "shield" :),
		(: exert_function, "neilisuck" :),
		(: exert_function, "jinglisuck" :),
		(: perform_action, "blade.riyue" :),
		(: perform_action, "blade.wenrou" :),
		(: perform_action, "blade.suifeng" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "dodge.lingbo" :),
	}) );

	set("jing",3000);
	set("max_jing", 3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp",2700000);

	set_skill("hand",300);
	set_skill("strike",300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed",300);
	set_skill("parry", 300);
	set_skill("lingboweibu",300);
	set_skill("chixin-jian",300);
	set_skill("beiming-shengong", 300);
	set_skill("zhemei-shou", 300);
	set_skill("liuyang-zhang",300);
	set_skill("literate",300);
	set_skill("sword",300);
	set_skill("blade",300);
	set_skill("ruyi-dao",300);

	map_skill("unarmed", "zhemei-shou");
	map_skill("hand","zhemei-shou");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("sword","chixin-jian");
	map_skill("force", "beiming-shengong");
	map_skill("blade","ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派护法使者");
	set("nickname","天使之侣");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}

void init()
{
	object ob;
	ob = this_player();

	if (interactive(ob)
	&& (!ob->query("family")
	|| ob->query("family/master_name")!="逍遥子")){
		command("grin");
		command("say 你好大的胆子，本派的密室也敢闯进来 ？！\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);

	}
	else {
		command("smile");
		command("say 师弟辛苦啦，快去见师父吧，他惦记着你呢。");
	}
}
