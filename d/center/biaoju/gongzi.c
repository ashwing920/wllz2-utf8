// man.c

#include <ansi.h>

inherit NPC;

int ask_finish();
int ask_where();

void create()
{
	set_name(npc_name("男性"),({ "fujia gongzi","gongzi"}));
	set("title","富家公子");
	set("long",@LONG
一个衣着华丽的富家公子，手持折扇，一副刁钻刻薄的模样就知道不是
什么好人。
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

	set("chat_chance_combat",5);
	set("chat_msg_combat", ({
		name() +"大声叫喊：救命啊！救命啊！打劫呀！",
	}) );

	set("back_time",time()+ 60);
	set("max_jing",1000);
	set("jing",1000);
	set("qi",1500);
	set("max_qi",1500);
	set("neili",1500);
	set("max_neili",1500);
	set("env/wimpy",20);
	set("combat_exp",400000);
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
		&& living(obj)
		&& obj->query("guard") == ob
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
		return notify_fail(ob->name()+"骂道：你他妈眼瞎啦？这里有出路嘛？\n");

	if(random(50) > 47) {
		write(name()+"摇了摇头，说道：好累啊，休息一下再走吧。\n"
		"说完往地上一坐，开始闭目养神。\n");
		set("sleep_time",time()+ 5 + random(10));
		return 1;
	}
	command("go "+ dir);
	ob->add("go",1);
	message_vision("$N一路护送$n离开了"+ env->short()+"。\n",me,ob);
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
		|| ob != quest["obj"] || quest["from"] != "镖局"
		|| ob->query("guard") != me) return 0;

	target = query("target");

	if( base_name(env) != query("target_file")){
		command("shake");
		command("say 我要到"+ target +"去，你当我胡涂了啊。");
		return 1;
	}
	exp = quest["exp_bonus"] + query("go") / 10;
	pot = quest["pot_bonus"] + query("go") / 5;
	diff = quest["diff"];
	
	command("say 好好好，本公子到了，这点碎银子就当打赏你的，你走吧！");
	command("drop silver");
	message_vision("$N丢下几两碎银，转身离开了。\n",ob);
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
	me->delete("quest");
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
	object me,env,npc,guard;
	me = this_object();
	env = environment(me);

	if( random(35) == 34 && !objectp(query("killer"))){
		npc = new(__DIR__"qiangdao");
		npc->move(environment(me));
		message_vision("忽然一个身影窜了出来，喝道：要从此路过，留下买路钱！！\n",me);
		npc->kill_ob(me);
		set("killer",npc);
		if(objectp(guard = me->query("guard"))
			&& environment(me) == environment(guard)){
			message_vision("$N冷笑道：妨碍大爷发财的人都得死！受死吧！\n",npc);
			npc->create_skill(guard);
			npc->kill_ob(guard);
			npc->set_leader(guard);
			message_vision("$N连忙躲到了$n的背后。\n",me,guard);
			remove_all_killer();
		}
	}
	if(time() >= me->query("back_time")){
		message_vision("$N一脸恼怒的说道：妈的什么破保镖，全是饭桶！老子的事情全被耽误了。\n"
				"$N骂完，头也不回的离开了。\n",me);
		destruct(me);
	}
	return;
}
string query_move_msg()
{
	return name() +"风度翩翩的从镖局内堂走了过来。\n";
}
string query_emote()
{
	return "$N高傲的打量了$n一番，说道：喂，你行不行的？\n";
}
int heal_up(){ return ::heal_up() + 1;}
void die()
{
	object me,guard;
	me = this_object();

	if(objectp(guard = me->query("guard"))){
		tell_object(guard,HIR"\n你要护送的"+ me->name()+"已经遇害，你的任务失败了。\n"NOR);
		guard->delete_temp("count");
	}
	::die();
}