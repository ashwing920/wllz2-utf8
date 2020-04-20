// xiaoer2.c 酒店小二

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",@LONG
这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。
LONG
);
	set("combat_exp", 6000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"/clone/food/jitui": 20,
		"/clone/food/jiudai": 20,
		"/clone/food/baozi": 20,
		"/clone/food/laiyitong": 20,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{          
	object ob; 
	mapping myfam; 

	ob = this_player();

	
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "丐帮" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	 
	add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/center/roadn1");
	message("vision","只听“乒”地一声，" +  ob->query("name") +
		"被人从客栈里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}

int accept_object(object who, object ob)
{
	if( ob->value() >= 1000 ) {
		message_vision("店小二点头哈腰，对$N说道：这位客官楼上请！\n",who);
		who->set_temp("give_sleep_money",1);
		} 
	else   {
		command("say 就这点儿钱就想住店？快给我滚开，穷光蛋！");
		return 0;
	}
	return 1;
}
