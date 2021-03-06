// /d/beijing2/xingbu/npc/sharen_kuangmo.c

inherit NPC;

void create()
{
	set_name("杀人狂魔", ({ "sharen kuangmo","kuangmo" }) );
	set("gender", "男性" );
	set("age", 40);
        set("title","不吃人头");
	set("long", "江湖上最凶悍的大盗，杀人如麻，没想到现在被囚禁在这里。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
        set("kar",30);  
        set("per",10);
	set("shen_type",-1);
	set("combat_exp",500000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	setup();
        NPC_D->full_init(this_object());
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

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

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);

		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_gin",  hp_status["max_gin"]);
		me->set("eff_gin",  hp_status["eff_gin"]);
		me->set("gin",      hp_status["gin"]);
      		me->set("max_sen",  hp_status["max_sen"]);
		me->set("eff_sen",  hp_status["eff_sen"]);
		me->set("sen",      hp_status["sen"]);

		me->set("max_force", hp_status["max_force"]);
		me->set("neili",     hp_status["force"]);
		me->set("force_factor",     hp_status["force_factor"]);
		me->set("combat_exp",hp_status["combat_exp"] * 105/100);

	return 1;
}

