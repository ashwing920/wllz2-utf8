// officer.c - 驿站站长

#include <ansi.h>

inherit NPC;
string send_mail();
string receive_mail();
int time_period(int timep, object me);

void create()
{
	set_name("驿站站长", ({ "officer" }) );
	set("long", @LONG
他是驿站的站长。
LONG
);
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 40);

	set("str", 30);
	set("cps", 30);
	set("cor", 30);
	set("per", 26);
	set("con", 30);

	set("inquiry", ([
		"驿站" : "是啊....这里就是驿站，你要寄信吗？",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"mail" : (: receive_mail :),
	]) );

	set("combat_exp",500000);
	set("env/wimpy", 70);

	set_skill("unarmed",50); 
	set_skill("parry",  50);
	set_skill("dodge",  50);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 50);
}
void init()
{
	add_action("give_quest","quest");
}
int give_quest()
{
	mapping quest ;
	object me,letter,ob;
	int combatexp, timep;
	me = this_player();
	ob = this_object();
	
	combatexp = (int)me->query("combat_exp");
	
	if(combatexp < 100000){
		message_vision("$N对$n说：这位"+ RANK_D->query_respect(me)+"怎么好象很面生呀？\n",ob,me);
		return 1;
	}

	if(combatexp > 1000000){
		tell_object(me,ob->name()+"对你说道：您已是武林高手了，这种小事怎敢劳您大驾？！\n");
		if(me->query("quest/quest_type") == "把信交给")
		me->delete("quest");
		return 1;
	}

	if((mapping)me->query("quest") && (string)me->query("quest/quest_type") != "把信交给" ) {
		tell_object(me,ob->name()+"说道：你还是先把其他任务完成了再说吧！\n");
		return 1;
	}
	if((mapping)me->query("quest") && (string)me->query("quest/quest_type") == "把信交给" 
	&& (int)me->query("quest/task_time") > time()){
		tell_object(me,ob->name()+"对你说道：交给你的信，你还没送去吗？\n");
		return 1;
	}
	if((int)me->query("letter_fail_time") > time()){
		tell_object(me,ob->name()+"说道：你把信弄丢了，我怎么放心让你替我办事呀？\n");
		return 1;
	}

	tell_object(me,ob->name()+"对你说道：你来得正好，我这正有一封信要送出去。\n");
	
	quest = QUEST_LET->query_quest();
	timep = random(180) + 180;
	time_period(timep, me);

	tell_object(me,"把这封信交到『" + quest["quest"] + "』手中。\n"NOR);
	message_vision("$N给了$n一封信。\n",ob,me);
	letter = new("/clone/obj/letter");
	letter->move(me,1);
	quest["quest_type"] = "把信交给";
	quest["exp_bonus"] = random(15) + 15;
	quest["pot_bonus"] = random(20) + 15;
	quest["score"] = 0;
	quest["from"] = "驿站";
	quest["get_from"] = "『驿站站长』";
	quest["task_time"] = (int)time() + timep;
	me->set("quest", quest);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;                      t /= 60;
	m = t % 60;                      t /= 60;
	h = t % 24;                      t /= 24;
	d = t;

	if(d)
	time = chinese_number(d) + "天";
	else
	time = "";
	if(h)
	time += chinese_number(h) + "小时";
	if(m)
	time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	tell_object(me, CYN+this_object()->name() +"说道：请你在" + time + "内");

	return 1;
}


string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||      base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player(),1);
	return "哦....要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}
string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||      base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player(),1);
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
