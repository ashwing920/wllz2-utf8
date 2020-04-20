// mawude.c 马五德

inherit NPC;

void create()
{
	set_name("马五德", ({ "ma wude", "ma", "wude" }));
	set("long", "馆主马五德豪富好客，颇有孟尝之风，人缘甚佳。\n");
	set("gender", "男性");
	set("age", 55);

	set_skill("literate",100);
	set_skill("sword",200);
	set_skill("blade",200);
	set_skill("staff",200);
	set_skill("club", 200);
	set_skill("whip", 200);
	set_skill("hammer",200);
	set_skill("wuchang-zhang",200);

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"学武" : "学武只须付五两银子，并可住在武馆里。",
		"学费" : "只须付五两银子。",
		"陈浒" : "他是二当家，擅于棒法(stick)，杖法(staff) 及拳法(cuff)。",
		"龙铨" : "他是刀刃部教头，以刀法(blade)和爪法(claw)见称。",
		"刘虹瑛" : "她是剑部教头，以剑法(sword)和掌下(strike)出名。",
		"萧飞" : "他是暗器部教头，擅于暗器(throwing)及指法(finger)。",
	]) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"马五德说道：「欢迎到来扬威武馆。」\n",
		"马五德说道：「学武只须付五两银子，并可住在武馆里。」\n",
		"马五德说道：「在此可学到内功，拳脚，兵器，轻功和招架。」\n",
		"马五德说道：「二当家陈浒是棒杖部教头，拳法亦是一绝。」\n",
		"马五德说道：「龙铨是刀刃部教头，以刀法和爪法见称。」\n",
		"马五德说道：「刘虹瑛是武馆的剑部教头，同时掌下败将无数。」\n",
		"马五德说道：「萧飞是武馆的暗器部教头，并擅于指法。」\n",
	}) );	
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
}

int accept_object(object who, object ob)
{
	int time;

	if (ob->query("money_id") && ob->value() >= 500) {
		time = ob->value();
		if(time > 5000) time = 5000;
		command("say "+RANK_D->query_respect(who)+"不远千里而来，真是赏脸，请到后院学习你所喜欢的功夫吧。");
		who->set_temp("mark/马",time);
		return 1;
	}
	command("say 这位"+ RANK_D->query_respect(who) +"给的未必也太少了吧？");
	return 0;
}

int recognize_apprentice(object ob)
{
	if(!(int)ob->query_temp("mark/马")) return 0;
	ob->add_temp("mark/马",-1);
	return 1;
}
