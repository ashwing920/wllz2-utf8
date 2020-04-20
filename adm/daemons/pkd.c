// pkd.c

#include <ansi.h>
#include <localtime.h>

inherit F_DBASE;

#define ENTRY_ROOM      "/d/xuanbing/entry"
#define READY_ROOM      "/d/xuanbing/ready"
#define PK_ROOM         "/d/xuanbing/stone"

// the state of daemon
static int state;

#define SLEEPING        0
#define GET_READY       1
#define STARTING        2

#define GET_READY_TIME  600

static object *total = ({ });
static int ready_time = 0;

// 四次比赛列表
static mapping *tlist = ({
([      "name" : "屠人热身赛",
	"time" : ({ 2200, 2210, }),
	"age"  : ({ 14, 20 }),
	"last_day" : 0,
]),
([      "name" : "屠人准备赛",
	"time" : ({ 400, 410, }),
	"age"  : ({ 21, 30 }),
	"last_day" : 0,
]),
([      "name" : "屠人选拔赛",
	"time" : ({ 1000, 1010, }),
	"age"  : ({ 31,45 }),
	"last_day" : 0,
]),
([      "name" : "屠人大赛",
	"time" : ({ 1600, 1610 }),
	"age"  : ({ 18,400 }),
	"last_day" : 0,
])

});

static int selected;

private void change_state(int new_state);
private void init_player(object me);
private int  start_competition();
private void message_competition(string msg);
private void auto_check();
private void give_bouns(object me);
private void kickout_players();
private void restore_status(object me);
private void send_invite_message();

// 外部可调用的函数
int check_out(object me);

// return the time of prompt
int is_pking()              { return state == STARTING; }
int is_ready()              { return state == GET_READY; }

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "比赛精灵");
	CHANNEL_D->do_channel(this_object(),"sys","比赛精灵已经启动。");
	state = SLEEPING;
	set_heart_beat(30);
}

int clean_up()
{
	return 1;
}

// join in competition
int join_competition(object ob)
{
	if (state != SLEEPING)
		return notify_fail("现在玄冰石室正在举行活动，你还是等等再说吧。\n");

	if (ob->query("combat_exp") < 800000)
		return notify_fail("你这点本事就别进去啦。\n");

	if(sizeof(ob->query_conditions()) > 1)
		return notify_fail("你现在状态不佳，还是别进去了。\n");

	if (! arrayp(total))
		total = ({ ob });
	else
	if (member_array(ob, total) == -1)
		total += ({ ob });

	message_competition("听说" +(ob->query("is_zongshi")? "一代武林宗师" : "一代武林侠客") +
			    ob->name(2)+"进入玄冰石室。");

	init_player(ob);
	set_heart_beat(1);
	return 1;
}

// scan
private void heart_beat()
{
	mixed lt;
	int ti;
	int i;
	int last_day;

	seteuid(ROOT_UID);
	lt = localtime(time());
	ti = lt[LT_HOUR] * 100 + lt[LT_MIN];

	switch (state)
	{
	case SLEEPING:
		last_day = time() / 86400;
		for (i = 0; i < sizeof(tlist); i++)
		{
			if (ti < tlist[i]["time"][0] || ti > tlist[i]["time"][1])
				// not change state
				continue;
			if (last_day == tlist[i]["last_day"])
				// this day has do it
				break;
			tlist[i]["last_day"] = last_day;
			selected = i;

			// chanage state to "GET_READY";
			change_state(GET_READY);
			break;
		}
		break;

	case GET_READY:
		if (time() < ready_time + GET_READY_TIME)
			break;

		// change state to "GET_READY_2";
		change_state(STARTING);
		break;

	case STARTING:
		break;
	}

	if (sizeof(total))
		auto_check();
}

// the daemon change to a new state
private void change_state(int new_state)
{
	mixed lt;
	int n;

	lt = localtime(time());
	switch (new_state)
	{
	case GET_READY:
		// kickout the player now in competition
		kickout_players();

		ready_time = time();
		message_competition("听说一年一度的" + tlist[selected]["name"] + "马上就要"
				    "举行了，不知道今年的冠军是谁？");
		set_heart_beat(1);
		send_invite_message();
		break;

	case STARTING:
		if (! (n = start_competition()))
		{
			message_competition("听说今年的" + tlist[selected]["name"] + "因故"
					    "取消了，真是没劲。");
			new_state = SLEEPING;
		} else
		{
			message_competition("听说今年的" + tlist[selected]["name"] +
					    "吸引了" + chinese_number(n) +
					    "名高手！走...看看热闹去。");
			set_heart_beat(1);
		}
		break;

	default:
		total = ({ });
		break;
	}

	// change to new state
	state = new_state;
	if (state == SLEEPING)
		set_heart_beat(30);
	return;
}

// set player's override functions
private void init_player(object me)
{
	tell_object(me, HIC"你眼前忽然一亮...\n"NOR);

	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("surrender", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));

	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/first_kill",me->query_temp("first_kill"));

	me->move(sprintf(PK_ROOM "%d", random(10) + 1));
	tell_object(me, HIC"你来到了" + environment(me)->short() + HIC "里。\n");
	me->set("backup/condition", me->query_conditions());
	me->remove_all_killer();
	me->delete_temp("first_kill");
	me->clear_conditions();
}

// kickout the players in competition when formal competition
// get ready
private void kickout_players()
{
	object ob;
	string room;
	mapping my;

	if (! arrayp(total))
		return;

	foreach (ob in total)
	{
		if (! objectp(ob))
			continue;
		room = base_name(environment(ob));
		if (! sscanf(room, PK_ROOM "%*s"))
			// not in pk room
			continue;

		my = ob->query_entire_dbase();
		my["eff_qi"] = my["max_qi"];
		my["eff_jing"] = my["max_jing"];
		my["qi"] = 1;
		my["jing"] = 1;

		tell_object(ob, HIC "\n石室守卫走了过来，嚷嚷道：“清场了！清场了，都快走吧！”\n" NOR);

		restore_status(ob);
		ob->move(ENTRY_ROOM);
		message("vision", "只见" + ob->name() + "悻悻的走了出来。\n",
			environment(ob), ({ ob }));
		if (! living(ob))
			ob->revive();
	}
}

// start competition, overide all the player's unconcios/die
// function
private int start_competition()
{
	object env;
	object *obs;
	object shadow;
	int i;

	env = find_object(READY_ROOM);
	if (! objectp(env))
		return 0;

	obs = filter_array(all_inventory(env), (: userp($1) && ! wizardp($1) :));
	if (sizeof(obs) < 2)
		return 0;

	if (sizeof(obs) == 2)
	{
		if (obs[0]->query("marry") == obs[1]->query("id"))
		{
			message_vision("石室守卫在外面喊道：“就你们夫妻"
				       "俩个参加？还是算了吧。”\n", obs[0]);
			return 0;
		}
	}

	message("vision", "一个黑影走了过来，打开了门，冷冷道：“都进去吧！”\n", env);

	for (i = 0; i < sizeof(obs); i++)
	{
		reset_eval_cost();
		init_player(obs[i]);
	}

	set_heart_beat(1);
	message("vision", HIG "屠人大会已经开始，快动手吧！\n", obs);
	return sizeof(total = obs);
}

// send message out
private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

// check all the players who join the competition
private void auto_check()
{
	object ob;
	string msg;
	string room;
	object *lost;
	int i;

	lost = ({ });
	for (i = 0; i < sizeof(total); i++)
	{
		if (! objectp(total[i]))
			continue;
		room = base_name(environment(total[i]));
		if (! sscanf(room, PK_ROOM "%*s"))
		{
			// not in pk room
			restore_status(total[i]);
			total[i] = 0;
		}
		if (total[i]->query("qi") < 1 || total[i]->query("jing") < 1)
			lost += ({ total[i] });
	}

	// kickout the players who lost competition
	foreach (ob in lost)
		check_out(ob);

	total -= ({ 0 });
	if (state == SLEEPING)
	{
		if (sizeof(total) < 1)
			// end of competition. call the change_state
			// function to restore the normal heart beat.
			change_state(SLEEPING);

		return;
	}

	if (state != STARTING)
		return;

	if (sizeof(total) < 1)
	{
		msg = "听说屠人大会大赛参赛者死的死，逃的逃，现在一个人都没有啦！";
	} else
	if (sizeof(total) == 1)
	{
		// change the daemon's state
		msg = "听说本次屠人大会圆满结束，" +
		      total[0]->name(1) + "成为屠人大会冠军！";
		give_bouns(total[0]);
	} else
	if (sizeof(total) == 2 && total[0]->query("marry") == total[1]->query("id"))
	{
		msg = "听说本次屠人大会圆满结束，" +
		      total[0]->name(1) + "和" + total[1]->name(1) +
		      "夫妻双双把家还。";
		give_bouns(total[0]);
		give_bouns(total[1]);
	} else
		return;

	message_competition(msg);
	change_state(SLEEPING);
}

private void give_bouns(object me)
{
	int exp;
	int pot;
	int weiwang;
	int score;
	string msg;

	// lead me out
	restore_status(me);
	tell_object(me, "这次真是爽呆了...\n");
	me->move(ENTRY_ROOM);
	message("vision", me->name() + "慢慢的走了过来，一脸奸笑。\n",environment(me), ({ me }));

	// bouns
	pot = (int)me->query("combat_exp") / 1000 + 3000;
	exp = (int)me->query("combat_exp") / 500 + 3000;
	weiwang = (int)me->query("combat_exp") / 1000 + 500;
	score = (int)me->query("combat_exp") / 1000 + 500;

	msg = HIG "通过这次大会，你获得了 " + (string)exp + " 点经验";

	if (pot > 0)
	{
		pot = random(pot / 3) + 1;
		msg += "和 " + (string) pot + " 点潜能。\n";
	} else
	{
		pot = 0;
		msg += "。\n";
	}

	if(weiwang > 0)
	{
		weiwang = random(weiwang / 3) + 1;
		msg += "你的江湖威望提高了 "+ (string)weiwang+" 点。";
	}else
	{
		weiwang =0;
		msg += "";
	}
	
	if(score > 0)
	{
		score = random(score / 3) + 1;
		msg += "你的江湖阅历也提高了 "+ (string)score +" 点。\n"NOR;
	}else
	{
		score =0;
		msg += "。\n"NOR;
	}

	me->add("potential", pot);
	me->add("combat_exp", exp);
	me->add("weiwang",weiwang);
	me->add("score",score);
	tell_object(me, msg);
	log_file("fight_win",sprintf("%s比武胜利获得经验：%d，潜能：%d，威望：%d，阅历：%d。\n",
		me->name(2),exp,pot,weiwang,score));
}

// remove overide function
// restore condition
private void restore_status(object me)
{
	mapping cnd;
	string *ks;
	int i;

	me->delete_override("unconcious");
	me->delete_override("die");
	me->delete_override("surrender");
	me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
	me->clear_conditions();
	me->receive_damage("qi", 0);
	me->apply_killer(me->query_temp("backup/killer"));
	me->set_temp("first_kill",me->query_temp("backup/first_kill"));
	cnd = me->query("backup/condition");
	me->delete("backup/condition");
	me->delete_temp("backup");
	me->delete_temp("block_msg/all");
	if (! mapp(cnd)) return;
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);
}

// send invite message
private void send_invite_message()
{
	object *obs,mengzhu;
	int exp_ul, exp_dl;
	string name;

	exp_dl = tlist[selected]["age"][0];
	exp_ul = tlist[selected]["age"][1];
	obs = filter_array(all_interactive(),
			   (: ! wizardp($1) &&
			      $1->query("age") >= $(exp_dl) &&
			      $1->query("age") <= $(exp_ul) :));
	if (! sizeof(obs))
		return;

	mengzhu = find_living("wulin mengzhu"); 
	if(!mengzhu) mengzhu = load_object("/clone/npc/meng-zhu");
	name = mengzhu->name();

	message("vision",HIR"武林盟主"+ name +"发来了的武林盟帖，邀请你参加这次" +
		tlist[selected]["name"] + "，有没有兴趣去显显身手？\n" NOR,obs);
}

int start_by_others(int n)
{
	if (state == STARTING)
		return notify_fail("现在屠人大会正在进行中。\n");

	if (state == GET_READY)
		return notify_fail("现在屠人大会正在报名中。\n");

	if (n < 0 || n >= sizeof(tlist))
		return notify_fail("没有这个等级的屠人大会(0-" +
				   (sizeof(tlist) - 1) + ")。\n");
	selected = n;
	change_state(GET_READY);
	return 1;
}

object *query_all_competitor()
{
	return total;
}

// overide function of quit
int check_quit(object me)
{
	message_competition("听说" + me->name(1) +
			    "临阵脱逃，溜走了。");
	restore_status(me);
	if (arrayp(total))
		total -= ({ me });

	tell_object(me, "你逃出了玄冰石室。\n");

	// continue run quit function
	me->move(ENTRY_ROOM);
	message("vision", "只见" + me->name() + "慌里慌张的跑了出来。\n",environment(me), ({ me }));
	return 1;
}

// overide function of lost(die/unconcious)
int check_out(object me)
{
	object ob;
	mapping my;
	string msg;
	string room;

	room = base_name(environment(me));
	if (! sscanf(room, PK_ROOM "%*s"))
	{
		// not in pk room
		total -= ({ me });
		return 0;
	}

	my = me->query_entire_dbase();
	my["eff_qi"] = my["max_qi"];
	my["eff_jing"] = my["max_jing"];
	my["qi"] = 1;
	my["jing"] = 1;

	tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！\n" NOR);
	if (ob = me->query_temp("last_damage_from"))
	{
		msg = "听说" + me->name(1) + "惨遭" + ob->name(1) + "的毒手，被无情淘汰。";
	} else
		msg = "听说" + me->name(1) + "运气不佳，本领有限、已经惨遭淘汰。";
	message_competition(msg);

	restore_status(me);
	total -= ({ me });

	message("vision","只听见“乓”的一声，" + me->name() +"被人从玄冰石室里踢了出来，样子好狼狈。\n", environment(me), ({ me }));
	tell_object(me,HIY"恍恍忽忽之中，有人朝你屁股狠狠的揣了一脚，还骂道：这点本事也敢出来混？不自量力！\n"
	"话音刚落，你立刻被人从玄冰石室里踢了出来，重重的摔倒了地上。\n"NOR);

	me->move(ENTRY_ROOM);

	if (! living(me))
		me->revive();
	return 1;
}

// reject_join?
string reject_join(object me)
{
	int age;

	if (state == STARTING)
		return "现在" + tlist[selected]["name"] + "正在举行，"
		       "你还是下次再来吧。";

	if (state != GET_READY)
		return "现在没要举行屠人大会啊？你跑来干什么？";

	age = (int)me->query("age");
	if (age < tlist[selected]["age"][0])
		return "你还是算了吧，小小年纪何必去送死呢？";

	if (age > tlist[selected]["age"][1])
		return "嘿，一把年纪了还要和小辈们争？";

	return 0;
}
