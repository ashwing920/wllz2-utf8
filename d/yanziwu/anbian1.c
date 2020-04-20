
#include <ansi.h>

inherit ROOM;

mapping *paizi=({
	([
		"name":"琴韵小筑",
		"id":"xiaozhu",
		"file":__DIR__"zhou6",
		"value":500
	]),
	([
		"name":"燕子坞",
		"id":"yanziwu",
		"file":__DIR__"zhou",
		"value":500
	]),
});
string look_paizi();
int do_go(string);
void create()
{
	set("short","岸边");
	set("long",@LONG
这是曼佗罗山庄的一个小码头，从这里上船可以到达慕容世家的领地
，武林中的英雄豪杰们都十分仰慕闻名天下的燕子坞，因为那里是无人不
知无人不晓的“以彼之道，还施彼身”的发源地，而慕容世家一代就是住
在那里。岸边有一位老船夫，专门载着去燕子坞的武林人士，他一见你走
过来，不敢怠慢，带着笑脸连忙迎上前去。在岸边有一块牌子(paizi)。
LONG
);
	set("outdoors","yanziwu");
	set("exits",([
		"north" : __DIR__"xiaojing1-0",
	]));
	set("item_desc",([
		"paizi" : (: look_paizi :)
	]));
}
void init()
{
	add_action("do_go", "qu");
}

string look_paizi()
{
	string str="";
	int i=sizeof(paizi);

	while (i--) {
		str += paizi[i]["name"];
		str += "(" + paizi[i]["id"] + ") ";
		str += MONEY_D->price_str(paizi[i]["value"]) + "\n";
	}
	return str;
}

void do_move(object ob, int i)
{
	ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(paizi);

	if (!arg) return notify_fail("你要去哪里？\n");
	if (ob->is_busy() || ob->is_fighting())
	return notify_fail("你正忙着呢！\n");


	while(i--) {
	if (arg == paizi[i]["id"]) {
	if(ob->query("family/family_name") != "慕容世家"){
	switch (MONEY_D->player_pay(ob, paizi[i]["value"])){
		case 0: return notify_fail("穷光蛋，一边呆着去！\n");
		case 2: return notify_fail("有零钱吗？\n");
	}
		message_vision("$N在口袋里翻来覆去地找船钱。\n", ob);
		ob->start_busy(3);
		message_vision(YEL"\n$N把钱交给船家，船家领$N上了一条小舟。\n\n"NOR,ob);
	}
		else
	{
		message_vision(YEL"\n船家对$N说道：原来是慕容家的人，快请上船。\n"NOR,ob);
		message_vision(YEL"$N走上了小船。\n"NOR,ob);
	}
	call_out("do_move", 3, ob, i);
	return 1;
	}
	}
	return notify_fail("你要去哪里？\n");
}
