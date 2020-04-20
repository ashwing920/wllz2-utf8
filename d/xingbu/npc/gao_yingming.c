// gao_yingming.c

#include <ansi.h>

inherit NPC;

#include "qflist.h"

int is_guanfu() { return 1;}
int time_period(int timep, object me);

string ask_finish();

void create()
{
	set_name("高英明", ({ "gao yingming","xingbu shangshu","gao"}));
	set("gender", "男性" );
	set("title","刑部尚书");
	set("age", 35);
	set("long","一脸正气，未怒先威，一看就知道是一个清官。\n");
	set("str", 20);
	set("int", 25);
	set("inquiry",([
		"复命": (: ask_finish() :),
	]));
	set("combat_exp",1500000);
	set("attitude", "friendly");
	setup();
	add_money("silver", 12);
	carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_quest","quest");
}
void greeting(object ob)
{
	if(!ob || environment(ob) != environment() ) return;
	say( "高英明一拍惊堂木，大喝一声：大胆小民，有何冤情，快快道来。\n" );
}
void create_event(object me)
{
	object obj;
	string env,where,city;
	mapping quest;
	int time;

	quest = ([ ]);

	time = time() + (4 * 240 + random(70));

	if(random(5) > 2){
		obj = new("/clone/npc/yifan");
                                obj->set_name(npc_name("男性"),({me->query("id")+" yi fan"}));
		env = arrest_path[random(sizeof(arrest_path))];
		quest["quest_type"] = "抓";
		quest["exp_bonus"] = 15 + random(10);
		quest["pot_bonus"] = 20 + random(10);
	}
	else {
		obj = new("/clone/npc/xiongfan");
                                obj->set_name(npc_name("男性"),({me->query("id")+" xiong fan"}));
		env = kill_path[random(sizeof(kill_path))];
		quest["quest_type"] = "杀";
		quest["exp_bonus"] = 20 + random(10);
		quest["pot_bonus"] = 15 + random(10);
	}

	obj->move(env);
	city = query_city(env);
	where = environment(obj)->query("short");
	where = replace_string(where,city,"");
	where = city + where;
	obj->set("back_time",time);
	quest["obj"] = obj;
	quest["quest"] = obj->name();
	quest["task_time"] = time;
	quest["where"] = where;
	quest["diff"] = 4;
	quest["score"] = 1;
	quest["from"] = "官府";
	me->set("quest",quest);
	return;
}
string ask_finish()
{
	object me,ob,money;
	mapping quest;
	int exp,pot;

	me = this_player();

	if(!mapp(quest =  me->query("quest")) || quest["from"] != "官府")
		return "我好象没吩咐你做事吧？";

	if( quest["quest_type"] != "抓")
		return "我叫你去抓人了吗？";

	if(!objectp(ob = me->query_temp("arrest")) || !present(ob,environment(me)))
		return "我叫你去抓的人带来了吗？";

	if(!objectp(me = ob->query_temp("arrest")) || !objectp(ob = me->query("quest/obj")))
		return "我叫你去抓疑犯，你怎么就随便抓了个人来见我？";

	message_vision("$N成功的把疑犯$n带到了刑部尚书高大人手中。\n",me,ob);
	message_vision("$n被几个衙差押入了大牢，等待审讯。\n",me,ob);

	if((int)me->query("quest/task_time") < time()){
		command("sigh");
		command("say 虽然时间迟了，但人总算带到了。");
		tell_object(me,"你没有在要求的时间内把疑犯带到，任务只完成了一半。\n");
		tell_object(me,"你获得了一些白银做为奖励！\n");
		money = new("/clone/money/silver");
		money->set_amount((int)me->query("quest/diff") * 5);
		money->move(me,1);
		me->delete("quest");
		me->delete_temp("arrest");
		destruct(ob);
		return "好吧，你下去休息吧！";
	}
	else {
		command("say 好！你做得好！");
		exp = quest["exp_bonus"]+ random(10) + 20;
		pot = quest["pot_bonus"]+ random(20) + 20;
		tell_object(me,"由于你成功的完成了任务，你获得了高大人的嘉奖。\n");
		tell_object(me,sprintf("你获得了%s点经验、%s点潜能和一些银两做为奖励。\n",chinese_number(exp),chinese_number(pot)));
		me->add("combat_exp",exp);
		me->add("potential",pot);
		money = new("/clone/money/silver");
		money->set_amount(quest["diff"] * 8);
		money->move(me,1);
		if( ob->query_temp("fight_lost_for") == me) {
			tell_object(me,HIW"由于你在捉拿疑犯时与疑犯生死相搏，表现英勇，你还获得了额外的一些奖励。\n"NOR);
			tell_object(me,HIW"你的江湖威望增加了十点，江湖阅历增加了一点。\n"NOR);
			me->add("weiwang",10);
			me->add("score",1);
			SCORE_D->set_score(me);
		}
		me->delete("quest");
		destruct(ob);
		me->delete_temp("arrest");
		return "好吧，你下去休息吧！";
	}
}
int do_quest()
{
	object me,ob;
	mapping quest;
	string where;

	ob = this_object();
	me = this_player();

	if((int)me->query("combat_exp") < 500000){
		tell_object(me,CYN + name() +"说道：这位"+ RANK_D->query_respect(me)+"一心为朝廷办事虽然精神可佳，可惜经验尚浅，恐怕难以担此大任！\n"NOR);
		return 1;
	}

	if((int)me->query("combat_exp") > 3000000){
		tell_object(me,CYN + name() +"说道："+ RANK_D->query_respect(me)+"大名如雷灌耳，本官岂敢劳烦您呢？\n"NOR);
		return 1;
	}
	if((int)me->query("gfquest_fail_time") > time()){
		tell_object(me,CYN + name() +"说道：你的差事我已经派人去办了，你稍后再来吧！\n"NOR);
		return 1;
	}
	if(mapp(quest =  me->query("quest"))){
		if( quest["from"] != "官府"){
			tell_object(me,CYN + name()+"说道：这位"+ RANK_D->query_respect(me)+"好象心事重重，是否心里还有事情牵挂？\n"NOR);
			return 1;
		}
		if( quest["task_time"] > time()){
			tell_object(me,CYN + name()+"说道：我交待的事情你办得怎么样了？\n"NOR);
			return 1;
		}
		else {
			tell_object(me,CYN + name()+"说道：好吧，我就再给你一次机会。\n"NOR);
			me->receive_damage("qi",100,ob);
			if(me->query("quest")) me->delete("quest");
			if(me->query_temp("arrest")) me->delete_temp("arrest");
			me->delete_temp("count");
		}
	}
	create_event(me);

	if((string)me->query("quest/quest_type") == "杀")
		tell_object(me,sprintf("%s说道：凶犯『%s』在『%s』抢劫路人财物，连伤数条人命。\n"
				"你速去将他捉拿归案。如有违抗者：杀无赦！\n",
				name(),me->query("quest/quest"),me->query("quest/where")));
	else
		tell_object(me,sprintf("%s说道：据报疑犯『%s』在『%s』附近出没。\n"
			"你速去将他["HIG"arrest"NOR"]抓来问话。记得：切勿将他杀死！\n",
				name(),me->query("quest/quest"),me->query("quest/where")));
	return 1;
}

int accept_object(object who, object ob)
{
	object obj,me;
	mapping quest;

	me = this_object();

	if (ob->query("money_id")){
		if(!mapp(quest = who->query("quest")) || quest["from"] != "官府"){
			tell_object(who,CYN + me->name() +"说道：无功不受禄，这位"+ RANK_D->query_respect(who) +"还是把钱收回去吧！\n"NOR);
			return 0;
		}
		if ( ob->value() < 3000) {
			tell_object(who,CYN + me->name() +"说道：这位"+ RANK_D->query_respect(who)+"未必也太小看我们刑部了吧？！\n"NOR);
			return 0;
		}
		if( who->query("quest")) {
			tell_object(who,CYN + me->name() +"说道：嗯...好吧，我找让其他巡捕去做！你下去休息吧！\n"NOR);
			if(objectp(obj = who->query("quest/obj"))) destruct(obj);
			if(who->query("weiwang") > 20) who->add("weiwang",-20);
			who->delete("quest");
			who->delete_temp("arrest");
			who->delete_temp("count");
			who->set("gfquest_fail_time", time() + 60);
			return 1;
		}
	}
	command("say 无功不受禄，你给我这个做什么？");
	return 0;
}
