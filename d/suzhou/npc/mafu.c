// mafu1.c 马夫

inherit NPC;
#include <ansi.h>
int do_ride();

void create()
{
	set_name("马夫", ({ "ma fu","ma fu"}));
	set("age", 32);
	set("gender", "男性");
	set("long","驯马和租马的小贩，给他租金就可以雇到马。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/armor", 30);
	set("chat_chance",2);
	setup();
}

void init()
{
	object ob;

	
	if( interactive(ob = this_player()) && !is_fighting() ) {
		   remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_rideyz", "rideyz");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "马夫点头哈腰地说道：这位客官，是想到这里挑一匹好马吧？\n");
}

int accept_object(object who, object ob)
{
	if ( who->query_temp("is_riding")) {
		message_vision("马夫邹起眉头，说到：这位客倌您不正骑着马吗？\n",who);
		return 0;
	}		
	if (ob->query("money_id") && ob->value() >= 100)
	{
	message_vision("马夫对$N说：好！这位"+RANK_D->query_respect(who) +
		"现在就出发马? 那就上马吧。\n", who);
		this_player()->set_temp("marks/horserent",1);
			return 1;
	}
	else  
		message_vision("马夫皱眉对$N说：您给的也太少了吧？\n", who);
	return 1;
}

int do_rideyz()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat 来人啦！"+ob->query("name")+
		"这个"+RANK_D->query_rude(ob)+"想偷马！");
		return 1;
	}
	switch (random(3))
	{
		case 1:
			hname=MAG"紫骝马"NOR;
			break;
		case 2:
			hname=RED"枣红马"NOR;
			break;
		default:
			hname=HIY"黄骠马"NOR;
			break;
	}
	message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
	message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
	ob->move("/d/suzhou/beidajie1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/suzhou/canlangting");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/suzhou/dongdajie1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/suzhou/dongdajie2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/suzhou/dongmen");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/quanzhou/qzroad2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/quanzhou/qzroad1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/taishan/yidao1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/taishan/yidao");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/dongmen");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/dongdajie2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/dongdajie1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/guangchang");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/beidajie1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/kedian");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/majiu");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达扬州。\n");
	message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}

