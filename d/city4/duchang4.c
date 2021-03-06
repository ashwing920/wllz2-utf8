// Room: /d/changan/duchang4
// by snowcat 7/5/1997
inherit ROOM;

int room_status = 0;
object nh_gui = 0;
object bh_gui = 0;
object ld_gui = 0;
int *res = allocate(3);

mapping guis = ([ 
  "nh"  : "南海龟",
  "bh"  : "北海龟",
  "ld"  : "陆地龟",
 ]); 

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

void create()
{
	set ("short", "赛龟房");
	set ("long", @LONG
一排紫色的镂空檀香靠背椅沿着屋子四周放了一圈，坐着聚精会神的
客人。中间是一雕花石座，上面放着一个长长的紫檀龟台。一位扎着青鬏
的青鬏龟童正围着龟台转来转去。龟房的墙上挂着牌子(sign)。
LONG);

	set("item_desc",([
		"sign"  : "押南海龟： ya nh <amount> <money>\n"+ 
			  "押北海龟： ya bh <amount> <money>\n"+ 
			  "押陆地龟： ya ld <amount> <money>\n", 
	])); 
	set("objects", ([
		__DIR__"npc/guitong" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"clubup",
	]));
	set("light_up", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_beg",1);
	set("no_sleep",1);
	setup();
}

void init ()
{
	add_action ("do_sai","ya");
	add_action ("do_fight","fight");
	add_action ("do_steal","steal");
	add_action ("do_kill","kill");
	add_action ("do_cast","cast");
	add_action ("do_exert","exert");
	add_action ("do_perform","perform");

	if (room_status > 0)
	return;

	remove_call_out ("gamble_prepare");
	remove_call_out ("gamble_start");
	remove_call_out ("gamble_perform");
	remove_call_out ("gamble_finish");
	call_out ("gamble_prepare",2);
	room_status = 1;
}

int do_sai (string arg)
{
	object me = this_player();
	string what;
	int amount;
	string money;
	object ob;

	if (!arg||sscanf (arg,"%s %d %s",what,amount,money) != 3)
	return notify_fail("请使用： ya <押龟种类> <数目> <货币>\n");

	if (what != "nh" &&
	what != "bh" &&
	what != "ld")
	return notify_fail("你要押什么样的龟？\n");

	ob = present (money+"_money", me);
	if(! ob)
	return notify_fail("你身上没有这种货币。\n");
	if(amount < 1)
	return notify_fail("请多押一些钱。\n");
	if(amount > ob->query_amount())
	return notify_fail("你身上的钱不够押。\n");

	if(amount * ob->query("base_value") > 1000000)
	return notify_fail("你赌疯了啊，下这么多注！\n");

	if(me->query_temp ("gamble_gui/amount") > 0)
	return notify_fail("你已经押过了。\n");

	if (room_status > 1)
	return notify_fail("现在正在赛龟呢，稍等片刻。\n");

	me->set_temp("gamble_gui/kind",what);
	me->set_temp("gamble_gui/amount",amount);
	me->set_temp("gamble_gui/money",money);
	message_vision (sprintf("$N拿出%s%s%s放在紫檀龟台上，押%s。\n",chinese_number(amount),
	ob->query("base_unit"),
	ob->query("name"),
	guis[what]),
	me);
	if (amount == ob->query_amount())
	destruct (ob);
	else
	ob->add_amount(-amount);

	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp ("gamble_gui/amount") > 0) 
	message_vision ("$N扔下押龟的钱不要了。\n",me);
	me->delete_temp("gamble_gui");

	return ::valid_leave(me,dir);
}

void gamble_prepare ()
{
	object room = this_object();
	tell_room (room,"青鬏龟童将三只龟放在紫檀龟台边。\n");
	if(! nh_gui){
	nh_gui = new(__DIR__+"npc/saigui");
	nh_gui->set("name","南海龟");
	nh_gui->move(room);
}
	if(!bh_gui){
	bh_gui = new(__DIR__+"npc/saigui");
	bh_gui->set("name","北海龟");
	bh_gui->move(room);
 }
	if(!ld_gui){
	ld_gui = new(__DIR__+"npc/saigui");
	ld_gui->set("name","陆地龟");
	ld_gui->move(room);
}
	tell_room (room,"青鬏龟童说：请各位大人赏押，一赢三。\n");
	room_status = 1;
	call_out ("gamble_start",20);
}
 
void gamble_start ()
{
	object room = this_object();
	tell_room (room,"青鬏龟童说：各位大人停押。\n");
	tell_room (room,"然后用兔毛掸将三只赛龟推入龟台内。\n");
	room_status = 2;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	call_out ("gamble_perform",1);
}

void display_gui (int i, string name, object room)
{
	string gui1 = "＼－－－／  ";
	string gui2 = "（某某龟）＞";
	string gui3 = "／－－－＼  ";
	string line1 = "｜";
	string line2 = "｜";
	string line3 = "｜";
	int j;

	gui2 = "（"+name+"）＞";
	for (j = 0; j < res[i]; j++){
	line1 = line1 + "..";
	line2 = line2 + "..";
	line3 = line3 + "..";
}
	line1 = line1 + gui1;
	line2 = line2 + gui2;
	line3 = line3 + gui3;
	for (j = res[i]; j < 30; j++){
	line1 = line1 + "  ";
	line2 = line2 + "  ";
	line3 = line3 + "  ";
}
	line1 = line1 + "｜\n";
	line2 = line2 + "｜\n";
	line3 = line3 + "｜\n";
	tell_room (room,line1);
	tell_room (room,line2);
	tell_room (room,line3);
}

int move_on (int r)
{
	r += random2(7);
	if (r > 30)
	r = 30;
	return r;
}

void boost_guis (int *res)
{
	int i, j;
	for (i = 0; i < 10; i++){
	reset_eval_cost();
	j = random2(3);
	if (res[j] >= 28){
	res[j] = 30;
	break;
		}
	}
}

void gamble_perform ()
{
	object room = this_object();

	tell_room (room,"\n\n");
	display_gui (0,"南海龟",room);
	display_gui (1,"北海龟",room);
	display_gui (2,"陆地龟",room);

	if (res[0]<30 && res[1]<30 && res[2]<30){
	res[0] = move_on(res[0]);
	res[1] = move_on(res[1]);
	res[2] = move_on(res[2]);
	boost_guis (res);
	remove_call_out ("gamble_perform");
	call_out ("gamble_perform",1);
	return;
 }

	call_out ("gamble_finish",1);
  
}

void player_wins (object who, int total)
{
	object money = new ("/clone/money/"+who->query_temp("gamble_gui/money"));
	int amount = who->query_temp("gamble_gui/amount");
	total = total * amount;
	money->set_amount(total);
	message_vision (sprintf("$N赢了%s%s%s！\n",chinese_number(total),
	money->query("base_unit"),
	money->query("name")),
	who);
	money->move(who);
}

void player_loses (object who, int total)
{
	object money = new ("/clone/money/"+who->query_temp("gamble_gui/money"));
	total = who->query_temp("gamble_gui/amount");
	message_vision (sprintf("青鬏龟童将$N放在龟台上的%s%s%s收走。\n",
	chinese_number(total),
	money->query("base_unit"),
	money->query("name")),
	who);
	destruct (money);
}

void gamble_finish ()
{
	string win;
	int total, i;
	object room = this_object();
	object *list = all_inventory(room);
	if (res[0]==30 && res[1]==30 && res[2]==30){
	total = 0;
	win = "none of them";
	tell_room (room,"青鬏龟童叹道：三龟同胜无赢家！\n");
}
	else if ((res[0]==30 && res[1]==30) ||
	(res[1]==30 && res[2]==30) ||
	(res[2]==30 && res[0]==30))
{
	total = 0;
	win = "none of them";
	tell_room (room,"青鬏龟童叹道：二龟同胜无赢家！\n");
}
	else if (res[0]==30)
{
	total = 3;
	win = "nh";
	tell_room (room,"青鬏龟童喜道："+guis[win]+"获胜！\n");
}
	else if (res[1]==30){
	total = 3;
	win = "bh";
	tell_room (room,"青鬏龟童喜道："+guis[win]+"获胜！\n");
}
  else{
	total = 3;
	win = "ld";
	tell_room (room,"青鬏龟童喜道："+guis[win]+"获胜！\n");
}
	i = sizeof(list);
	while (i--){
	if(!userp(list[i]))continue;
	if(list[i]->query_temp("gamble_gui/kind") == win)
	player_wins(list[i],total);
	else if (list[i]->query_temp("gamble_gui/kind"))
	player_loses(list[i],total);
	list[i]->delete_temp("gamble_gui");
}
	tell_room (room,"\n");
	call_out ("gamble_prepare",6+random2(7));
}

int do_bian (string arg)
{
	object who = this_player();
	object room = this_object();
	object ob;

	if (!arg)
	return 0;

	ob = present(arg,room);
	if (ob == nh_gui || ob == bh_gui || ob == ld_gui){
	message_vision ("$N挤到龟中间想把自己变成龟。\n",who);
	message_vision ("青鬏龟童对$N说道：大人，俗话说好汉不和龟赛。\n",who);
	return 1;
 }
	return 0;
}

int do_fight (string arg)
{
	object who = this_player();
	object room = this_object();
	object ob;

	if (!arg) return 0;

	ob = present(arg,room);
	if (ob == nh_gui || ob == bh_gui || ob == ld_gui){
	message_vision ("$N要与龟比武。\n",who);
	message_vision ("青鬏龟童对$N说道：大人，俗话说好汉不和龟斗。\n",who);
	return 1;
}
	return 0;
}

int do_steal (string arg)
{
	object who = this_player();

	message_vision ("$N想偷龟。\n",who);
	message_vision ("青鬏龟童对$N说道：大人窃龟也不羞脸。\n",who);
	return 1;
}

int do_kill (string arg)
{
	object who = this_player();
	object room = this_object();
	object ob;

	if (!arg) return 0;

	ob = present(arg,room);
	if(ob == nh_gui || ob == bh_gui || ob == ld_gui){
	message_vision ("$N想杀死龟。\n",who);
	message_vision ("青鬏龟童对$N说道：大人切莫杀生。\n",who);
	return 1;
}
	return 0;
}

int do_cast (string arg)
{
	object who = this_player();

	message_vision ("$N龟模龟样地念了几句咒语。\n",who);
	message_vision ("青鬏龟童对$N说道：大人，莫念莫念，切莫伤您龟寿。\n",who);
	return 1;
}

int do_exert (string arg)
{
	object who = this_player();

	message_vision ("$N想借龟施功。\n",who);
	message_vision ("青鬏龟童对$N说道：大人在这里练功会损了您的龟寿。\n",who);
	return 1;
}

int do_perform (string arg)
{
	object who = this_player();

	message_vision ("$N想借龟施功。\n",who);
	message_vision ("青鬏龟童对$N说道：大人在这里练功会损了您的龟寿。\n",who);
	return 1;
}
