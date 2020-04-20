//fight.c

inherit NPC;

int is_fight_npc(){ return 1;}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;
	me = this_object();

	if(is_fighting()) return 0;

	if( me->query("master") && me->query("master") != this_player()->query("id"))
		return notify_fail("这不是你买的"+ me->query("name")+"吧？\n");

	if(me->query("damaged"))
		return notify_fail(me->query("name") +"已经受伤太重，不能再陪你练功了！\n");

	if(random(me->query("fight_times")) >= 10) {
		set("damaged",1);
		return notify_fail(me->query("name") +"受伤太重了！\n");
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("你刚和"+ me->query("name")+"练过功！\n");

	me->set("last_fighter",ob->query("id"));
	me->set("fight_npc",1);
	me->set("no_get",1);
	me->add("fight_times", 1);
	me->set_temp("fighter_id",ob->query("id"));

	remove_call_out("renewing");
	call_out("renewing", 300 + random(100), me);

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

	hp_status = ob->query_entire_dbase();

//		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("kar", hp_status["kar"]);
//		me->set("dex", hp_status["dex"]);
		me->set("cor", hp_status["cor"]);
		me->set("spi", hp_status["spi"]);
		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("qi",        hp_status["max_qi"]);
		me->set("jing",      hp_status["max_jing"]);
		me->set("max_jingli",hp_status["max_jingli"]);
		me->set("jingli",    hp_status["jingli"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     me->query("max_neili"));
		me->set("combat_exp",hp_status["combat_exp"]/4*3);
		me->set_temp("apply/armor",1500);
		return 1;

}
void renewing(object me)
{
	if(!me) return;
	me->delete("last_fighter");
}
