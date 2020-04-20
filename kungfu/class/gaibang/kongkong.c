// kongkong.c 空空儿

inherit NPC;

void create()
{
	set_name("空空儿", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "妙手神丐");
	set("gender", "男性" );
	set("age", 53);
	set("long",@LONG
一个满脸风霜之色的老乞丐。
LONG
);
	set("attitude", "peaceful");
	set("class", "beggar");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);

	set_skill("force", 400); 
	set_skill("unarmed", 400);
	set_skill("sword", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("stealing", 400);
	set_skill("begging", 400);
	set_skill("checking", 400); 
	set_skill("huntian-qigong", 400); 
	set_skill("xianglong-zhang", 400);
	set_skill("xiaoyaoyou", 400); 
	set_skill("training", 400);
	set_skill("hand",400);
	set_skill("shexing-diaoshou",400);
	set_skill("blade",400);
	set_skill("liuhe-daofa",400);
	map_skill("hand","shexing-diaoshou");
	map_skill("blade","liuhe-daofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry","xianglong-zhang");

	create_family("丐帮", 19, "八袋长老");

	set("chat_chance",10);
	set("chat_msg", ({
		"空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
		"空空儿懒洋洋地打了个哈欠。\n",
		"空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
		(: random_move :)
	}) );

	setup();

	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");
	add_money("silver", 10);
	
}

void init()
{	
	object ob;
	if( interactive(ob = this_player())) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}
void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
		|| ((fam = ob->query("family")) && fam["family_name"] == "丐帮")
		|| (int)ob->query_skill("taoism", 1) > 30
		|| ob->query_int() > 30
	  ) return;

	switch( random(5) ) {
		case 0:
			   command("hehe " + ob->query("id"));
			   command("beg all from " + ob->query("id"));
			   command("buy jitui");
			   break;
		case 1:
			   command("grin " + ob->query("id"));
			   command("steal silver from " + ob->query("id"));			
			   command("eat jitui");
			   break;
		case 2:
			   command("hi " + ob->query("id"));
			   command("steal gold from " + ob->query("id"));			
			   command("drink jiudai");
			   break;
		case 3:
			   command("pat " + ob->query("id"));
			   command("beg all from " + ob->query("id"));	
			   command("eat jitui");
			   break;
		case 4:
			   command("ppp " + ob->query("id"));
			   command("beg all from " + ob->query("id"));	
			   command("drink jiudai");
			   break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
		 command("smile");
		 command("say 多谢啦！其实我还是有点钱的，这次只不过试试你罢了！");
		 command("give 10 silver to " + me->query("id"));
	}
	else {
		 command("shake");
		 command("say 这种东西鬼才要！滚一边去！");
		 command("give " + obj->query("id") + " to " + me->query("id"));
	}

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}
