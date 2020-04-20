// zhanggui.c - 王掌柜
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("王掌柜", ({ "wang zhanggui","zhanggui","wang" }) );
	set("long", @LONG
他是凌云棋社的王掌柜，笑呵呵的脸上让人感到亲切。
LONG
);
	set("rank_info/respect", "掌柜");
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 52);
	set("str", 30);

	set("combat_exp", 50000+random(10000));
	set("env/wimpy", 30);                   

	set_skill("unarmed", 50); 
	set_skill("parry",   50);
	set_skill("dodge",   50);

	setup();
	
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 10);
}

void init()
{       
	object ob;

	
	if( this_object()->query_temp("unconcious") ) return;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
       
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( this_object()->query("name") + "迎了上来，笑呵呵地说道：这位" + RANK_D->query_respect(ob)
				+ "，快请进，快请进！\n");
			break;
		case 1:
			say( this_object()->query("name") + "抬头看了"+ ob->query("name") +"一眼，又忙着他的事情去了。\n");
			break;
		case 2:
			say( this_object()->query("name") + "说道：这位" + RANK_D->query_respect(ob)
				+ "真是稀客啊，快请快请！\n");
			break;
	}
}