// Npc: /kungfu/class/shaolin/hui-zhen.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慧真尊者", ({"huizhen zunzhe","huizhen","zunzhe",}));
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
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

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

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	mapping mine;
	object me, room;

	me = this_player();

	if (!mapp(mine = me->query("family"))) 
		return;

	if(!( room = find_object("/d/shaolin/cjlou")) )
	room = load_object("/d/shaolin/cjlou");

	if( (mapp(mine = me->query("family")) && mine["family_name"] != "少林派")
	|| ((!present("daoyi chanshi", room)) && (!present("letter", me)))){
		  command("say 大胆狂徒，竟敢杀人闯入藏经阁，看招！\n");
		  call_out("kill_ob", 0, this_player()); 
		  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));		  
		  return;
	}
	return;
}


