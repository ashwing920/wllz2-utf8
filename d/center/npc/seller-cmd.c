// seller-cmd.c - 车马店老板

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

int buy_horse();
int ask_change_name();

void create()
{
	set_name("马夫", ({ "ma fu", "seller" }));
	set("long", @LONG
他是这里的马夫，正在细心的照料马匹。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 36);
	set("str", 30);
	set("combat_exp",30000+random(30000));
	set("shen_type",1);
	set("env/wimpy", 30);
	set("inquiry",([
		"买马": (: buy_horse :),
		"改名": (: ask_change_name :),
	]));
	set("vendor_goods", ([
		"/clone/horse/horse" : 1,
		"/clone/horse/horse_1" : 1,
		"/clone/horse/horse_2" : 1,
		"/clone/horse/horse_3" : 1,
		"/clone/horse/horse_4" : 1,
		"/clone/horse/horse_5" : 1,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 1);
}

void init()
{
	object ob;
	if( interactive(ob = this_player()) && !is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list","list");
	add_action("make_horse","make");
	add_action("change_horse_name","改");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(1) ) {
		case 0:
			say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，想挑一匹快马吗？\n");
			break;
	}
}
int buy_horse()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if(me->query("make_horse")) {
		message_vision("$N疑惑道：这位"+ RANK_D->query_respect(me)+"不是已经有你的坐骑吗？\n",ob);
		return 1;
	}
	command("say 定制一匹骏马需要500两黄金，这位"+ RANK_D->query_respect(me)+"如果想清楚了，就付钱吧。");
	me->set_temp("ask_buy_horse",1);
	return 1;
}
int make_horse(string arg)
{
	object me,ob,horse;
	mapping name;

	me = this_player();
	ob = this_object();


	if(me->query("make_horse")) {
		message_vision("$N疑惑道：这位"+ RANK_D->query_respect(me)+"不是已经有你的坐骑吗？\n",ob);
		return 1;
	}

	if(!me->query_temp("make_horse_money")){
		message_vision("$N疑惑道：这位"+ RANK_D->query_respect(me)+"好象还没下定金呢？\n",ob);
		return 1;
	}

	if(!arg || arg == "")
		return notify_fail("你要给你的马匹起个什么名字？\n");

	if( strlen(arg) > 20 )
		return notify_fail("你取的名字太长了，想一个短一点的吧。\n");


	if(!PNAME_D->check_name(arg)){
		message_vision("$N摇了摇头，笑道：拿人家的名字来为你的坐骑命名？这可不行。\n",ob);
		message_vision("$N又说道：马匹命名只能一次，你可要考虑清楚呀。\n",ob);
		return 1;
	}
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	if(!CHECK_D->check_obj_name(arg)) return notify_fail(ob->query("name")+"摇了摇头道：抱歉！你不能使用这种名字！\n");

	message_vision("$N点了点头，笑道：好吧，这位"+ RANK_D->query_respect(me)+"请稍等，俺这就给您牵来。\n",ob);
	message_vision("$N转身走进马房，不一会儿就牵出了一匹骏马。\n",ob);
	horse = new("/clone/misc/animal");
	horse->set("name",arg+NOR);
	horse->move(me,1);
	message_vision("$N得到了一匹"+ arg +NOR"。\n",me);
	me->set("make_horse/finish",1);
	me->set("make_horse/max_life",1);
	me->set("make_horse/name",arg+NOR);
	me->save();
	return 1;
}
int accept_object(object who, object ob)
{

	if(!who->query_temp("ask_buy_horse")
	&& !who->query_temp("ask_change_horse_name")) {
		command("say "+ RANK_D->query_respect(who)+"没事拿钱给我花？这可真是太好了。");
		return 1;
	}
	if( ob->query("money_id")) {
		if( who->query_temp("ask_buy_horse") && ob->value() >= 5000000) {
			command("nod");
			command("say 那好吧，请先为你的马匹命名：make 马匹的中文名");
			who->set_temp("make_horse_money",1);
			return 1;
		}
		if(who->query_temp("ask_change_horse_name") && ob->value() >= 2000000 ) {
			command("nod");
			command("say 好吧，请输入：改 马匹的中文名字。");
			who->set_temp("give_change_horse_money",1);
			return 1;
		}
	}

	command("say 你给我这个干什么？！");
	return 0;
}

int ask_change_name()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if(!me->query("make_horse")) {
		message_vision("$N疑惑道：这位"+ RANK_D->query_respect(me)+"还没有坐骑呢。\n",ob);
		return 1;
	}
	command("say 想改坐骑的名字需要200两黄金，这位"+ RANK_D->query_respect(me)+"如果想清楚了，就付钱吧。");
	me->set_temp("ask_change_horse_name",1);
	return 1;
}
int change_horse_name(string arg)
{
	object me,ob,horse;
	mapping name;
	me = this_player();
	ob = this_object();

	if(!me->query("make_horse")
	|| !me->query_temp("give_change_horse_money")) return 0;

	if( !me->query_temp("give_change_horse_money"))
		return notify_fail(ob->name()+"叫道：你还没给钱呢！\n");

	horse = present("my horse",me);

	if(!horse)
		return notify_fail(ob->name() +"说道：你的马匹呢？\n");

	if(!arg || arg =="")
		return notify_fail(ob->name() +"说道：请输入：改 马匹的中文名字。\n");

	if( strlen(arg) > 40 )
		return notify_fail("你取的名字太长了，想一个短一点的吧。\n");

	if(!PNAME_D->check_name(arg)){
		message_vision("$N摇了摇头，笑道：拿人家的名字来为你的坐骑命名？这可不行。\n",ob);
		return 1;
	}

	if(!CHECK_D->check_obj_name(arg))
		return notify_fail(ob->query("name")+"摇了摇头道：抱歉！你不能使用这种名字！\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);


	me->set("make_horse/name",arg+NOR);
	me->delete_temp("ask_change_horse_name");
	me->delete_temp("give_change_horse_money");
	me->save();
	horse->set("name",arg+NOR);
	horse->set_up();
	tell_object(me,"你把你的马匹的名字改为“"+ arg +NOR"”了。\n");
	return 1;
}
