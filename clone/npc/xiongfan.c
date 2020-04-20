// man.c

#include <ansi.h>

inherit NPC;

void checking(object ob);

void create()
{
	set_name(npc_name("男性"),({ "xiong fan","fan","robber"}));
	set("title","通缉要犯");
	set("attitude", "heroism");
	set("age", 30+random(20));
	set("str", 30);
	set("per", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
		 (: command, "exert recover":),
		 (: command, "exert regenerate":),
	}));
	set("back_time",time()+60);
	set("max_jing",5000);
	set("jing",5000);
	set("qi",5000);
	set("max_qi",5000);
	set("neili",2000);
	set("max_neili", 2000);
	set("env/wimpy",20);
	set("combat_exp",100000);
	setup();
	carry_object(sprintf("clone/cloth/male%d-cloth",1 + random(8)))->wear();
	add_money("silver",10);
}
void init()
{
	object ob,obj;
	obj = this_object();

	::init();

	if( interactive(ob = this_player())
	&& ob->query("quest/quest") == obj->name(1)
	&& ob->query("quest/task_time") > time()) {
		if(!obj->query("checked")) checking(ob);
	}
}

int accept_fight(object ob)
{
	command("say 在下怎么是"+ 
		RANK_D->query_respect(this_player())+"的对手呢？见笑！见笑！");
	return 1;
}
void checking(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if( !ob || environment(ob) != environment() ) return;
	if (mapp(skill_status = ob->query_skills()))//判断对象是否有功夫，如有将用这个函数复制全部功夫
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);//传回所有对象功夫阵列

		for (i = 0; i < sizeof(skill_status); i++)
		me->set_skill(sname[i], skill_status[sname[i]]);//为自己复制所有功夫
	}

	if (mapp(map_status = me->query_skill_map()))//判断自己是否有已装配的基本功夫
	{
		mname = keys(map_status);
		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
		me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))//判断对象所装配的基本功夫，如有将用这个函数复制
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
		me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))//判断自己是否有已装配的特殊功夫
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
		me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))//判断对象所装配的特殊功夫，如有将用这个函数复制
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
		me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

		hp_status = ob->query_entire_dbase();//得到对象现有状态
		my = me->query_entire_dbase();//得到自己现有状态

	my["str"] = hp_status["str"];//开始复制状态
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];
	my["spi"] = hp_status["spi"];
	my["cor"] = hp_status["cor"];
	my["kar"] = hp_status["kar"];

	my["max_qi"] = hp_status["max_qi"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["eff_qi"];
	my["max_jing"] = hp_status["max_jing"];
	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["eff_jing"];
	my["max_neili"] = hp_status["max_neili"]* 2;
	my["neili"] = hp_status["neili"]* 2;
	my["jiali"] = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];//结束复制状态
	me->set_temp("apply/armor",250);
	me->reset_action();//更新身体
	me->set("checked",1);
	return;

}
void scan()
{
	object me,env;
	me = this_object();
	env = environment(me);
	
	if(env && env->query("no_fight")){
		message_vision("$N往鬼鬼祟祟的东张西望。\n",me);
		random_move();
	}
	if(time() >= me->query("back_time")){
		destruct(me);
	}
	return;
}	
int heal_up(){ return ::heal_up() + 1;}
