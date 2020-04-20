// seller-hd.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit NPC;
inherit F_VENDOR;
int ask_hua();

#include <ansi.h>

void create()
{
	set_name("花店老板", ({ "seller", "waiter" }) );
	set("gender", "女性" );
	set("age", 20);
	set("long", "她是花店老板。\n");
	set("combat_exp",13000+ random(30000));
	set("attitude", "friendly");
	set("inquiry",([
		"送花": (: ask_hua :),
	]));
	set("vendor_goods", ([
		"/clone/obj/purple_flower": 1,
		"/clone/obj/red_flower"   : 1,
		"/clone/obj/yellow_flower": 1,
		"/clone/obj/blue_flower"  : 1,
		"/clone/obj/white_flower" : 1,
		"/clone/obj/black_flower" : 1,
	]) );

	setup();
	add_money("silver",10);
	carry_object("/clone/cloth/white-silk")->wear();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
	add_action("do_songhua","song");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(1) ) {
		case 0:
			say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)+ "，想买鲜花吗？\n");
			break;
	}
}
int ask_hua()
{
	object me;

	me = this_player();

	if(me->query_temp("ask_songhua")){
		write(this_object()->name()+"说道：想清楚要送什么花了吗？\n");
		return 1;
	}
	say(this_object()->name()+"说道：你要告诉我，要送什么样的花和什么样的卡。我们这里提供的花有：\n\n"
	+ HIY"黄玫瑰"NOR"：通常只有道歉的时候送，配上一张道歉的卡，价格 80 两黄金。\n"
	+ HIR"红玫瑰"NOR"：代表火辣辣的爱情，通常只有求爱的时候送，价格 120 两黄金。\n"
	+ HIW"白玫瑰"NOR"：代表纯洁善良的友谊，通常只有送给朋友，价格 140 两黄金。\n"
	+ HIM"粉色玫瑰"NOR"：代表温馨浪漫的爱情，通常只送给最深爱的人，价格 160 两黄金。\n\n"
	+ "你如果决定了，请输入[song <花的中文名字> to <对象的id>]。\n");
	me->set_temp("ask_songhua",1);
	return 1;
}
int do_songhua(string arg)
{
	object me,obj;
	string type,target;
	int value;

	me = this_player();

	if(!me->query_temp("ask_songhua")) return 0;
	if(!arg || sscanf(arg,"%s to %s",type,target) != 2)
		return notify_fail("指令格式：song <花的中文名字> to <对象的id>]。\n");

	if(!objectp(obj = find_player(target)) || !me->visible(obj))
		return notify_fail(this_object()->name()+"疑道：好象没有这个人吧？\n");

	if(obj == me)
		return notify_fail(this_object()->name()+"“嗤嗤”的笑了起来，说道：送花给自己？好可怜哦！\n");

	if( type != "黄玫瑰" && type != "红玫瑰" && type != "白玫瑰" && type != "粉色玫瑰")
		return notify_fail(this_object()->name()+"说道：目前本店只提供黄玫瑰、红玫瑰、白玫瑰和粉色玫瑰。\n");

	if(me->query_temp("songhua"))
		return notify_fail("你已经预订了一束"+ me->query_temp("songhua/type")+"，需要"+ MONEY_D->price_str(me->query_temp("songhua/value"))+"。\n");

	if( type == "黄玫瑰") value = 800000;
	else if( type == "红玫瑰") value = 1200000;
	else if( type == "白玫瑰") value = 1400000;
	else if( type == "粉色玫瑰") value = 1600000;

	me->set_temp("songhua/type",type);
	me->set_temp("songhua/target",obj);
	me->set_temp("songhua/value",value);

	tell_object(me,sprintf("你决定送一束%s给%s。\n",type,obj->query("name")));
	command("say 好吧！请付"+ MONEY_D->price_str(value) +"，我们会立刻把花送到"+ obj->name()+"的手中。");
	return 1;
}
int accept_object(object who,object ob)
{
	int value;
	object obj,flower;
	string type;
	string *finish = ({
		"说完，头也不回的跑了。",
		"说完，闪了一闪就不见了。",
		"说完正要走，又摔了一交。你赶紧扶稳他，他它一瘸一拐的走了。",
		"说完，卷起卷轴，满意的踱着方步走了。",
	});


	value = (int)who->query_temp("songhua/value");
	type = who->query_temp("songhua/type");

	if(ob->query("money_id")){
		if(!who->query_temp("ask_songhua")) {
			command("say 好端端的送钱给我做什么呀？");
			return 0;
		}
		if( !who->query_temp("songhua")){
			command("say 你还没告诉我送什么样的花，送给谁呢！");
			return 0;
		}
		if( !objectp(obj = who->query_temp("songhua/target"))){
			who->delete_temp("songhua");
			who->delete_temp("ask_songhua");
			command("say 你要送花的对象已经不在游戏中了。");
			return 0;
		}
		if( ob->value() < value){
			command("say 这点钱恐怕不够吧？");
			return 0;
		}
		if( type == "黄玫瑰") flower = new("/clone/obj/y_flower");
		else if( type == "红玫瑰") flower = new("/clone/obj/r_flower");
		else if( type == "白玫瑰") flower = new("/clone/obj/w_flower");
		else if( type == "粉色玫瑰") flower = new("/clone/obj/p_flower");
		flower->set("target",obj->query("name") +"("+ obj->query("id")+")");
		flower->set("master",who->query("name")+"("+ who->query("id")+")");
		say(this_object()->name()+"连忙点了点头，从花店里精挑细选的挑出几朵"+ type +"，嗖嗖嗖快速的包了起来。\n"
		+"不一会儿，一束"+ type +"就包扎好了。上面还插上了一张卡，交给小花童，小花童立马就给"+ obj->name() +"送了过去。\n");
		flower->move(obj);
		tell_room(environment(obj),HIM"\n小花童飞奔的跑到"+ obj->name()+"面前，气喘吁吁的说道："+ obj->name() +"，这是"+ who->name()+"送给你的"+ type+ "，请收好了。\n"+ finish[random(sizeof(finish))] +"。\n\n"NOR);
		say("小花童跑了过来，说道："+ type +"已经送到"+ obj->name()+"手中了。\n");
		who->delete_temp("songhua");
		who->delete_temp("ask_songhua");
		return 1;
	}
	command("say 嘻，你给我这个做什么呀？");
	return 0;
}