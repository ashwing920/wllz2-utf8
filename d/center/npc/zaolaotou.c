//polan.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("糟老头", ({ "zao laotou","zao","laotou" }));
	set("title","一问三不知");
	set("nickname",HIG"超级路痴"NOR);
	set("long", @LONG
他是桃源城里出了名的健忘汉，不管什么事情，一回头就忘记了。
所以人们称他为糟老头。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 48);
	set("str", 30);
	set("con", 30);
	set("per", 30);
	set("int", 30);
	set("kar", 30);
	set("combat_exp",random(30000)+10000);
	set("shen_type",1);
	set("chat_chance",5);
	set("chat_msg", ({
		(: command, "say" :),
		(: random_move :),
		(: command, "emote" :),
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 50);

}
void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer","answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say(name()+"疑道：这位" + RANK_D->query_respect(ob)+ "，你知道去桃源的路怎么走吗？\n");
			ob->start_busy(random(3));
			break;
		case 1:
			say(name()+"笑呵呵的问道：这位" + RANK_D->query_respect(ob) + "，你知道哪里可以存钱吗？\n");
			ob->start_busy(random(3));
			break;
		case 2:
			say(name()+"一把拉住你问道：这位" + RANK_D->query_respect(ob) + "，你知道这里的当铺在哪吗？\n");
			ob->start_busy(random(3));
			break;
		case 3:
			say(name()+"说道："+RANK_D->query_respect(ob)+"，你知道哪有去扬州的马车吗？\n");
			ob->start_busy(random(3));
			break;
		case 4:
			say(name()+"疑道：这位" + RANK_D->query_respect(ob)+ "，你知道这是哪吗？\n");
			ob->start_busy(random(3));
			break;
	}
}
int accept_object(object me, object obj)
{
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "！");
	return 1;
}
int do_answer(string arg)
{
	if(!id(arg)) return 0;
	command("oh");
	command("say 真是有劳这位"+ RANK_D->query_respect(this_player()));
	return 1;
}
