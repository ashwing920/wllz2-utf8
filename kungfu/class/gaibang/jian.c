//jianzhanglao.c

inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
void create()
{
	set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "执法长老");
	set("gender", "男性");
	set("age", 50);
	set("long",@LONG
简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。他向来嫉恶如
仇，弟子中有谁犯过，出手决不容情。
LONG
);

	set("attitude", "heroism");
	set("class", "beggar");
	set("no_get",1);

	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);
	set("shen_type",1);
	set("jing",1000);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("inquiry", ([
		  "青竹令" :     (: ask_me :)
	]));

	set("combat_exp",6400000);
	set("score", 20000);

	set_skill("force", 400);
	set_skill("huntian-qigong", 400);
	set_skill("unarmed", 400);
	set_skill("xianglong-zhang",400);
	set_skill("dodge", 400);
	set_skill("xiaoyaoyou",400);
	set_skill("parry", 400);
	set_skill("staff", 400);
	set_skill("dagou-bang",400);
	set_skill("begging", 400);
	set_skill("checking", 400);
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
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");

	create_family("丐帮", 18, "九袋长老");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "丐帮") &&
			(!wizardp(ob))) {
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment())
		return;

	message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
		"随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
		"说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
		"－－叭叽\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking",1,ob);

}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment())
		return;

	ob->move("/d/city/pomiao");
	 message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
		"从小门里飞了出来，屁股上有一个清楚的鞋印。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}
string ask_me()
{
	mapping fam;
	object ob,me=this_player();

	if(!(fam = me->query("family")) || fam["family_name"] != "丐帮")
		return RANK_D->query_respect(me) +"与本派素无来往，不知此话从何谈起？";
	if((int)me->query("combat_exp") < 100000)
		return "你的实战经验不足，还未到资格挑战你的同门大师兄呢！\n";

	ob = new(__DIR__"obj/qingzhu-ling");
	ob->move(me);
	message_vision("$N获得一面青竹令。\n",me);

	return "好吧，凭这面青竹令，你可自由向你的同门大师兄挑战。";

}
int accept_object(object ob, object obj)
{
	object me = this_object();

	if ( ob->query_temp("have_cloth") && present("po bu", ob) ){
		command("say 既然升袋，就当牢记帮规，为民除害！");
		message_vision("$N把破布钉在$n的破衣服上，俨然一个新口袋。\n", me, ob);
		ob->delete_temp("have_cloth");
		ob->set("title",ob->query("newtitle"));
		if (ob->query("title") == "丐帮一袋弟子"){
			ob->set("beggarlvl",1);
		}
		if (ob->query("title") == "丐帮二袋弟子"){
			ob->set("beggarlvl",2);
		}
		if (ob->query("title") == "丐帮三袋弟子"){
			ob->set("beggarlvl",3);
		}
		if (ob->query("title") == "丐帮四袋弟子"){
			ob->set("beggarlvl",4);
		}
		if (ob->query("title") == "丐帮五袋弟子"){
			ob->set("beggarlvl",5);
		}
		if (ob->query("title") == "丐帮六袋弟子"){
			ob->set("beggarlvl",6);
		}
		if (ob->query("title") == "丐帮七袋弟子"){
			ob->set("beggarlvl",7);
		}
		if (ob->query("title") == "丐帮八袋弟子"){
			ob->set("beggarlvl",8);
		}
		if (ob->query("title") == "丐帮九袋长老"){
			ob->set("beggarlvl",9);
		}
		return 1;
	}
}
