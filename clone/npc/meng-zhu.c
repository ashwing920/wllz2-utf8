// meng-zhu.c 武林盟主

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "meng-zhu"

#include <ansi.h>
inherit NPC;
inherit F_SAVE;
int do_clone(object me, object ob);
string query_save_file()
{
	return MENGZHU;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("魏无双", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
	set("title", "武林盟主" );
	set("gender", "男性" );
	set("age", 40);
	set("long","他就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n");
	set("attitude", "heroism");
	set("generation",0);
	set("double_attack", 1);
	set("winner","????");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("shen_type", 0);
	set("no_clean_up",1);
	set("combat_exp", 50000);

	set_skill("force", 100);		 // 基本内功
	set_skill("huntian-qigong", 100);	// 混天气功
	set_skill("unarmed", 100);	   // 基本拳脚
	   set_skill("xianglong-zhang", 60);   // 降龙十八掌
	set_skill("dodge", 100);		 // 基本躲闪
	set_skill("xiaoyaoyou", 100);	// 逍遥游
	set_skill("parry", 100);		 // 基本招架
	set_skill("staff", 100);		 // 基本棍杖
	set_skill("dagou-bang", 100);	// 打狗棒法
	set_skill("begging", 100);	   // 叫化绝活
	set_skill("checking", 100);	  // 道听途说

	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	setup();
	}
	else {
		set_name(query("name"), ({ query("id") }));
		setup();
	}

}
void init()
{
	add_action("do_kill", "kill");
	add_action("do_recover", "recover");
}
int accept_kill(object me)
{
	object ob;
	int i;

	command("say 你想谋害本盟主，当真是自找死路！ 座下红衣武士何在！");
	message_vision("四周的红衣武士群起对$N发动攻击！\n", this_player());

	for(i=0; i<4; i++) {
		if(objectp(ob = present("wei shi " + (i+1), environment(this_object()))))
			ob->kill_ob(me);
	}
	return 1;
}
int accept_fight(object ob)
{
	object me,npc,weapon;

	me = this_object();

	npc = find_living("shangshan shizhe");
	if(!npc) npc = load_object("/clone/npc/shang-shan");
	if((string)npc->query("winner") == (string)ob->query("id"))
		return notify_fail(me->name()+"摇了摇头，说道：你已经是赏善使者了，还要抢当武林盟主？！\n");

	npc = find_living("fae shizhe");
	if(!npc) npc = load_object("/clone/npc/fa-e");
	if((string)npc->query("winner") == (string)ob->query("id"))
		return notify_fail(me->name()+"摇了摇头，说道：你已经是罚恶使者，还要抢当武林盟主？！\n");

	if((string)me->query("winner") == (string)ob->query("id"))
		return notify_fail(me->name()+"摇了摇头，说道：莫非你是走火入魔，连自己都不认得了吗？\n");

	if(wizardp(ob))
		return notify_fail(me->name()+"摇了摇头，说道：巫师不能抢盟主之位！\n");

	if(me->is_fighting())
		return notify_fail(me->name()+"怒道：想倚多为胜，这不是欺人太甚吗！\n");

	if(objectp(weapon = ob->query_temp("weapon")))
		return notify_fail(me->name()+"摇了摇头，说道：挑战武林盟主使必须空手！难道你想杀人不成！？\n");

	if((int)ob->query("combat_exp") < (int)me->query("combat_exp"))
		return notify_fail(me->name()+"摇了摇头，说道：就凭你这微末得道行就想当武林盟主？\n");

	me->set("eff_qi",(int)me->query("max_qi"));
	me->set("qi",(int)me->query("max_qi"));
	me->set("eff_jing",(int)me->query("max_jing"));
	me->set("jing",(int)me->query("max_jing"));
	me->set("neili",(int)me->query("max_neili"));
	me->set("jingli",(int)me->query("max_jingli"));
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	return 1;
}
int checking(object me, object ob)
{

	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1;

	if (( (int)me->query("qi")*100 / my_max_qi) <= 30 ) {
		command("say 佩服佩服，看来我的担子可以交卸了，恭喜你成为新一代武林盟主！\n");
		command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！");
		command("chat 恭喜" + ob->query("name") + "被推举为现任武林盟主！\n");
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 看来" + RANK_D->query_respect(ob) +"还得多加练习，方能在当今武林中有所作为！\n");
		return 1;
	}

	return 1;
}

int do_copy(object me, object ob)
{
	if(me->unconcious()) me->revive();
	me->set("winner",(string)ob->query("id"));
	me->add("generation",1);
	me->set_name(ob->query("name"),({"wulin mengzhu","mengzhu","meng zhu"}));
	me->set("title","第" + chinese_number(me->query("generation")) + "代武林盟主");
	ob->set("title",HIC"第" + chinese_number(me->query("generation")) + "代武林盟主"NOR);
	do_clone(me,ob);
	return 1;
}
int do_clone(object me, object ob)
{
	object *inv, new1;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}

/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("age", hp_status["age"]);
		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("spi", hp_status["spi"]);
		me->set("kar", hp_status["kar"]);
		me->set("cor", hp_status["cor"]);
		me->set("per", hp_status["per"]);
	if(!userp(me)){
		me->set("max_qi",hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("max_jingli",hp_status["max_jingli"]);
		me->set("jingli",hp_status["jingli"]);
	}
		me->set("combat_exp",hp_status["combat_exp"]);

	if(me->save()) tell_object(ob, "状态储存完毕。\n");
	if(!userp(me)){
		me->clear_condition(1);
		new1 = new("/clone/npc/meng-zhu");
		new1->move("/d/taishan/fengchan");
		destruct(me);
	}
	return 1;
}
/* 这个指令是让玩家从该NPC身上恢复资料到自己身上。 */
int do_recover()
{
	object me, ob;

	me = this_object();
	ob = this_player();

	if((string)me->query("winner") != (string)ob->query("id"))
		return notify_fail("你不是现任武林盟主！\n");;

	if((time() - ob->query("recover_time")) < 86400)
		return notify_fail("你刚刚才恢复过，这么快又要恢复了？\n");

	ob->delete_all_skills();
	do_clone(ob,me);
	ob->set("recover_time",time());
	log_file("recover",sprintf("[%s]%s(%s)从武林盟主处得到恢复，胜利者识别为(%s)。\n",ctime(time()),ob->query("name"),ob->query("id"),me->query("winner")));
	write("状态恢复完毕。\n");
	return 1;
}
void unconcious(){ }
void die(){ unconcious();}
