// dunan.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡难", ({ "du nan", "nan" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",@LONG
这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。
LONG
);

	set("attitude", "peaceful");
	set("class", "bonze");
	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("jing",2000);
	set("max_jing",1000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",80);
	set("combat_exp",6400000);
	set("score", 200000);

	set_skill("unarmed",400);
	set_skill("buddhism",400);
	set_skill("force", 400);
	set_skill("whip", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("riyue-bian", 400);
	set_skill("shaolin-shenfa", 400);
	set_skill("blade", 400);
	set_skill("claw", 400);
	set_skill("club", 400);
	set_skill("cuff", 400);
	set_skill("finger", 400);
	set_skill("hand", 400);
	set_skill("staff", 400);
	set_skill("strike", 400);
	set_skill("sword", 400);
	set_skill("banruo-zhang", 400);
	set_skill("cibei-dao", 400);
	set_skill("damo-jian", 400);
	set_skill("fengyun-shou", 400);
	set_skill("fumo-jian", 400);
	set_skill("jingang-quan", 400);
	set_skill("longzhua-gong", 400);
	set_skill("luohan-quan", 400);
	set_skill("nianhua-zhi", 400);
	set_skill("pudu-zhang", 400);
	set_skill("qianye-shou", 400);
	set_skill("sanhua-zhang", 400);
	set_skill("weituo-gun", 400);
	set_skill("wuchang-zhang", 400);
	set_skill("xiuluo-dao", 400);
	set_skill("yingzhua-gong", 400);
	set_skill("yizhi-chan", 400);
	set_skill("zui-gun", 400);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set("inquiry", ([
		"菩提子"	 : (: ask_me :),
	]));

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);
	set("count", random(10)-8);
	setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	if( interactive(me) ) {
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] == 36 ) return;

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] > 36 		
		&& me->query("qi") < 50 ) {
			me->move("/d/shaolin/qyping");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );

		me->set_temp("fighter", 1);
		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("halt");
}

string ask_me()
{
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||	this_player()->query("combat_exp") < 100000 ){
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if (uptime() < 1800)
		return "菩提子乃天地之灵物，制炼艰难无比，我现在还没炼成。";

	if ( present("puti zi", this_player()) )
		return RANK_D->query_respect(this_player()) + "菩提子只有一颗，而且就在你身上，真是贪得无餍！";

	if ( present("puti zi", environment()) )
		return RANK_D->query_respect(this_player()) + "菩提子只有一颗，而且就在这里任你取走，真是贪得无餍！";

	if (query("count") < 1)
		return "菩提子乃天地之灵物，采集艰难无比，我这里现在可没有。";

	ob = new("/d/shaolin/obj/puti-zi");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n渡难惨然一笑，接着长叹一声，从树洞里取出个白玉磁瓶，倒出菩提子递给$N。\n\n", this_player());

	return "我等昔年于佛祖座前发下宏愿，每十年遍访名山大川，历尽捐险，\n" +
		   "方采得数颗菩提子，君乃有缘人，能得此造化奇物，望好自为之！";
}
#include "/kungfu/class/shaolin/du.h"