// mafu2.c 马夫

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
	add_action("do_rideem", "rideem");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "马夫笑咪咪说道：这位客官留步，我们这里多的是各地良马，您不妨瞧瞧。\n");
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

int do_rideem()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat 来人啦！"+ob->query("name")+
		"这个"+RANK_D->query_rude(ob)+"想偷马！");
		return 1;
	}
	switch (random(4))
	{
		case 1:
			hname=MAG"紫骝马"NOR;
			break;
		case 2:
			hname=RED"枣红马"NOR;
			break;
		case 3:
			hname=HIW"白骆驼"NOR;
			break;
		default:
			hname=HIY"黄骠马"NOR;
			break;
	}
	message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上"+hname+"背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
	message_vision("\n只见$N骑两腿一夹，"+hname+"穿过草棚而去。\n",ob);
	ob->move("/d/emei/huayanding");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/shierpan4");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/shierpan3");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/shierpan2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/shierpan1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/wannianan");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/bailongdong");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/qingyinge");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/zhongfengsi");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/shenshuian");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/chunyangdian");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/guiyunge");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/guanyintang");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/jietuopo");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/milin2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/fhs");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/milin1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/bgs");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/bgsgate");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/qsjie2");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/caopeng");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/emei/majiu1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达峨嵋山脚。\n");
	message_vision("\n$N身形一转，轻松落地，姿态十分优美。闲人也给$N一大哄！\n",ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
