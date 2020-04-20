// youxun.c
// pal 1997.05.28

#include <ansi.h>

inherit NPC;

string ask_cancel();

void create()
{
	set_name("游讯", ({ "you xun", "you", "xun" }) );
	set("nickname", "滑不留手");
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"他就是专门打探、贩卖消息的游讯。\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("inquiry", ([
		"name" : "小的就是游讯，不知您要打听点什么？",
		"欧冶子"  : "您问可以帮玩家造兵器的欧冶老爷子呀！据说他现在带着徒弟到西域去\n居住了，有人说他现在本事更大了，也不知真假\n",
		"江湖事": (: ask_cancel() :),
	]) );

	set_skill("literate", 100);
	set_skill("dodge", 500);
	set_skill("unarmed", 300);
	setup();
	carry_object("clone/cloth/male1-cloth")->wear();
}
void init()
{
	object ob;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment() ) return;
	command("hi "+ob->query("id"));
}
string ask_cancel()
{
	object me;
	mapping quest;
	int time;

	me = this_player();
	
	if(!mapp(quest = me->query("quest"))
	|| quest["from"] != "江湖")
		return "嗯！你若是想在江湖中混出一个名堂，倒是可以找一些老板打听江湖消息。";
	
	time = quest["task_time"] - time();
	if( time < 0) time = 0;

	me->delete("quest");
	me->delete_temp("continue_job");
	me->add("score",-10);
	me->set("world_fail_time",time + time());
	tell_object(me,"由于你的失误，你的江湖阅历降低了十点。\n");
		return "唉，就知道你不是这个料，好吧，这件事情，我帮你解决就是了。";
}
