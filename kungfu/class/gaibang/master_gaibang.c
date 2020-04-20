// gaibang.c 掌门长老

#ifndef NPCDATA
#define NPCDATA         "/data/family/"
#endif
#define FAMILY_MASTER   NPCDATA + "gaibang";

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

int do_clone(object me, object ob);
	
string query_save_file()
{
	return FAMILY_MASTER;
}
void create()
{
	seteuid(getuid());
	if (!restore()) {
		set_name(npc_name("男性"),({ "master_gaibang","master",}));
		set("family/family_name","丐帮");
		set("gender", "男性" );
		set("age", 40);
		set("attitude", "heroism");
		set("generation",0);
		set("winner","");
		set("str", 30);
		set("int", 30);
		set("con", 30);
		set("dex", 30);
		set("combat_exp",100000);
		NPC_D->full_init(this_object());
	}
	else {
		set_name(query("name"), ({ query("id") }));
	}
	set("title","丐帮掌门长老");
	setup();
	carry_object("/clone/weapon/staff")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("do_recopy",  "recopy");
}
int do_recopy(object me, object ob)
{
	me = this_object();
	ob = this_player();

	if((string)me->query("winner") != (string)ob->query("id"))
		return notify_fail("你无权更新本门师兄！\n");;

	if((time() - query("recopy_time")) < 600)
		return notify_fail("你刚刚才更新过，这么快又要更新了？\n");

	set("recopy_time",time());
	do_clone(me,ob);
	return 1;
}
int accept_fight(object ob)
{
	object me  = this_object();
	object weapon;
		
	if( me->query("winner") == ob->query("id") ) 
		return notify_fail("你跟你自己打什么架？！\n");

	if( me->query("family/family_name") != ob->query("family/family_name"))
		return notify_fail("你不是"+ me->query("family/family_name") +"弟子，不能向"+ me->name()+"挑战。\n");

	if( wizardp(ob))
		return notify_fail("你是巫师，不能挑战掌门师兄。\n");

	if( ob->query("betrayer"))
		return notify_fail(me->name()+"说道：你这背信弃义的家伙，没资格向我挑战。\n");

	if( ob->query("combat_exp") < me->query("combat_exp") ) 
		return notify_fail("就凭你这微末得道行就想挑战掌门师兄？\n");

	if( objectp(weapon = ob->query_temp("weapon")))
		return notify_fail("挑战掌门长老必须空手！难道你想杀人不成！？\n");

	if( me->is_fighting() ) 
		return notify_fail("已经有人正在挑战掌门长老了！\n");

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",    me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	return 1;
}

int checking(object me, object ob)
{

	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting(ob)) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say 果然厉害，恭喜你成为当今掌门长老！\n");
		command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！\n");
		command("chat 恭喜" + ob->query("name") + "成为"+ me->query("family/family_name")+"第" + chinese_number(me->query("generation")+1) + "代掌门长老 ！\n");
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 看来" + RANK_D->query_respect(ob) + "还得多加练习，方能在当今武林中出人头地！\n");
		return 1;
	}

	return 1;  
}

int do_copy(object me, object ob)
{

	seteuid(getuid());

	me->add("generation", 1);          

	me->set("name",  ob->query("name") );
	me->set("title", ob->query("family/family_name")+"第" + chinese_number(me->query("generation")) + "代掌门长老");
	me->set("short", me->query("title") + " " + me->query("name") + "[" + capitalize(ob->query("id")) + "]");
	ob->set("title", me->query("family/family_name")+"第" + chinese_number(me->query("generation")) + "代掌门长老"NOR);
	
	ob->set_temp("apply/short", ({me->query("short")}));
	
	me->set("short", me->query("title") + " " + me->query("name") + "[Master_gaibang]");
	me->delete("title");
	remove_call_out("do_clone");
	call_out("do_clone",0,me,ob);

	return 1;
}

int do_clone(object me, object ob)
{
	object *inv, new1;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );
	me->set("winner", ob->query("id"));

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
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop/damage") > 100 
		||  inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",       hp_status["max_qi"]);
		me->set("eff_qi",       hp_status["eff_qi"]);
		me->set("qi",   hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",   hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",         hp_status["neili"]);
		me->set("jiali",         hp_status["jiali"]);
		me->set("gender",       hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);
		me->set("death_count",hp_status["death_count"]);
		me->set("death_times",hp_status["death_times"]);
		me->set("age",       hp_status["age"]);
		me->set("modify_age",hp_status["modify_age"]);
		me->set("long",      hp_status["long"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	clear_condition();
	save();

	tell_object(ob, "状态储存完毕。\n");
	new1 = new(base_name(this_object()));
	new1->restore();
	new1->move(me->query("startroom"));
	destruct(me);
	return 1;
}
