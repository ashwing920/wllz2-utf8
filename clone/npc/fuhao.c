// man.c

#include <ansi.h>

inherit NPC;

int ask_finish();
int ask_where();

void create()
{
	set_name(npc_name("男性"),({ "fu hao","hao"}));
	set("title","富豪");
	set("long",@LONG
一个家财万贯的富豪，满脸横肉，一看就知道是那种专门搜刮穷苦百姓
的钱财的主。
LONG);
	set("age", 30+random(20));
	set("str", 20);
	set("per", 30);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("inquiry",([
		"去哪":	(: ask_where :),
		"到了": (: ask_finish :),
	]));
	set("back_time",time()+ 60);
	set("max_jing",500);
	set("jing",500);
	set("qi",500);
	set("max_qi",500);
	set("neili",1000);
	set("max_neili",1000);
	set("env/wimpy",20);
	set("combat_exp",100000);
	setup();
	carry_object(sprintf("clone/cloth/male%d-cloth",1 + random(8)))->wear();
}
void init()
{
	object ob,obj;
	obj = this_object();

	::init();

	if( interactive(ob = this_player()) && living(obj)
		&& ob->query("quest/obj") == obj){
		add_action("do_husong","husong");
	}
}
int do_husong(string arg)
{
	object me,ob,env;
	string dir,target;
	mapping exit;

	me = this_player();
	ob = this_object();
	env = environment(me);

	if(!arg || sscanf(arg,"%s to %s",target,dir) != 2)
		return notify_fail("指令格式：husong <目标 id> to <方向> \n");

	if(!id(target))
		return notify_fail("你要护送谁？\n");

	if( ob != me->query("quest/obj") || me->query("quest/from") != "镖局")
		return notify_fail("你搞错了吧？这不是你要护送的对象。\n");

	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if(is_fighting())
		return notify_fail(ob->name() +"正被袭击，赶紧保护他呀。\n");

	if(!living(ob))
		return notify_fail(ob->name()+"现在走也走不动了。\n");
	
	if(query("sleep_time") > time())
		return notify_fail(ob->name()+"正在休息，等一下再走吧。\n");

	if(!mapp(exit = env->query("exits")) || undefinedp(exit[dir]))
		return notify_fail(ob->name()+"急道：这个方向没有任何出路。\n");

	if(random(50) > 47) {
		write(name()+"摇了摇头，说道：好累啊，休息一下再走吧。\n"
		"说完往地上一坐，开始闭目养神。\n");
		set("sleep_time",time()+ 5 + random(10));
		return 1;
	}
	command("go "+ dir);
	ob->add("go",1);
	return 1;
}
int ask_finish()
{
	object me,ob,env,money;
	string target;
	mapping quest;
	int exp,pot,diff,count_point;

	me = this_player();
	ob = this_object();
	env = environment(ob);

	if(!mapp(quest = me->query("quest"))
		|| ob != quest["obj"] || quest["from"] != "镖局") return 0;

	target = query("target");

	if( base_name(env) != query("target_file")){
		command("shake");
		command("say 我要到"+ target +"去，你可别胡弄我呀。");
		return 1;
	}
	exp = quest["exp_bonus"] + ob->query("go");
		if( exp > 180) exp = 180;
	pot = quest["pot_bonus"] + ob->query("go");
		if( pot > 180) pot = 180;

	diff = quest["diff"];
	
	command("say 龙门镖局果然明不虚传，多谢这位"+ RANK_D->query_respect(me)+"一路照料。");
	message_vision("$N说完，转身离开了。\n",ob);
	tell_object(me,sprintf("你顺利的将%s护送到%s，使得龙门镖局声望大增。\n"
			"你的实战经验也随之提高了%s点，潜能增加了%s点，\n"
			"你的江湖阅历增加了一点，江湖威望也提高了一点。\n",
			name(),target,chinese_number(exp),chinese_number(pot)));
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("score",1);
	me->add("weiwang",1);
	me->add_temp("count",1);
	if(me->query_temp("count") > 15){
		count_point = diff * 15 * 100;
		if(count_point > 6000) count_point = 6000;
		tell_object(me,sprintf(HIC"恭喜！由于你连续的完成了十五个任务。\n"
			"你获得了%s点实战经验和一百点江湖威望的额外奖励。\n\n"NOR,
			chinese_number(count_point)));
		me->add("combat_exp",count_point);
		me->add("weiwang",100);
		me->delete_temp("count");
	}
	destruct(ob);
	return 1;
}
int ask_where()
{
	if(!query("target")){
		command("say 我也不知道啊，你说呢？");
		return 1;
	}
	command("say 我打算到"+ query("target")+"去一趟。");
	return 1;
}
		
void scan()
{
	object me,env;
	me = this_object();
	env = environment(me);

	if(time() >= me->query("back_time")){
		message_vision("$N一脸恼怒的说道：妈的什么破保镖，全是饭桶！老子的事情全被耽误了。\n"
				"$N骂完，头也不回的离开了。\n",me);
		destruct(me);
	}

	return;
}
string query_move_msg()
{
	return name() +"一副不可一世的样子，大摇大摆的走了过来。\n";
}
string query_emote()
{
	return "$N瞧了瞧$n，一副爱理不理的样子。\n";
}
int heal_up(){ return ::heal_up() + 1;}

