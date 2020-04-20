//xuemuh.c 薛慕华

inherit NPC;
inherit F_MASTER;

int ask_me();

void create()
{
	set_name("薛慕华", ({ "xue muhua", "xue" }));
	set("long",@LONG
他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。
LONG
);
	set("gender","男性");
	set("title","逍遥派“函谷八友”");
	set("nickname","阎王敌薛神医");
	set("age", 50);
	set("class","shaman");
	set("attitude","peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);

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

	set("inquiry", ([
		"疗伤" : (:ask_me:),
	]) );

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
	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();
}


void attempt_apprentice(object ob)
{
	if((int)ob->query_skill("beiming-shengong", 1) < 200) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。");
		command("say " + RANK_D->query_respect(ob) + "的北冥神功是否还应该有所提高啊？");
		return;
	}
	if((int)ob->query_skill("lingboweibu",1) < 200) {
		command("say 本派的凌波微步是以身法为基础，依我看" + RANK_D->query_respect(ob) + "的身法似乎还不够啊。");
		return;
	}

	if (ob->query_int() < 35) {
		command("say 我逍遥派武功最重视“逍遥”二字，何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}
	command("nod");
	command("say 好好，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("class","scholar");
}

int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("family/family_name") != "逍遥派"){
		command("say 你不是我派弟子，我不可以为你疗伤。\n");
		return 1;
	}
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")){
		command("?"+ob->query("id"));
		command("say 你没有受任何伤啊？");
		return 1;
	}
	else{
		message_vision("薛慕华喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		remove_call_out("recover");
		call_out("recover",4,ob);
		return 1;
	}
}


int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("大约过了一盅茶的时份，薛慕华慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了,可以走啦。");
	return 1;
}
