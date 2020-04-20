// linghu.c 令狐冲

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("令狐冲", ({ "ling huchong", "ling", "huchong" }));
	set("nickname", "大师兄");
	set("long",@LONG
令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，他在同门中排行老大，是华
山派年轻一代中的顶尖好手。
LONG
);
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);

	set("combat_exp",2700000);
	set("score", 10000);

	set_skill("blade", 300);
	set_skill("cuff", 300);
	set_skill("feiyan-huixiang", 300);
	set_skill("hand", 300);
	set_skill("finger", 300);
	set_skill("strike",300);
	set_skill("claw", 300);
	set_skill("unarmed",300);
	set_skill("force", 300);
	set_skill("zixia-shengong", 300);
	set_skill("huashan-neigong", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("huashan-sword", 300);
	set_skill("literate", 300);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "huashan-sword");

	create_family("华山剑派", 14, "弟子");

	set("inquiry", ([
		"风清扬" : "唉，已经很久没有见到他老人家了。你问这干嘛？\n",
		"任盈盈" : "你真有她的消息吗？\n",
	]));
	setup();	 	
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2")->wear();
}
void init()
{
	object ob;
	ob = this_player();	
	if( interactive(ob) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 何日才能见道盈盈啊！" + RANK_D->query_respect(ob)+"，你可有她的消息？");
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if( !objectp(ob) ) return 0;
	if( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if((string)ob->query("id") != "qing xin")
			return notify_fail("令狐冲不需要这件东西。\n");
	say( "令狐冲双手捧着任盈盈的信，泪如雨下，这块白虎堂令牌你拿去还给盈盈，告诉她我就去找她！\n" );
	obn = new("/d/heimuya/npc/obj/card2");
	obn->set_amount(1);
	obn->move(who);
	destruct(obn);
	set_temp("card2",0);
	return 1;
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000) {
		command("say 我华山剑派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}

	if ((int)ob->query_int() < 29) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山剑派武功？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
	return;
}
