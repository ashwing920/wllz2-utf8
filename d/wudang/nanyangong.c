//Room: nanyangong.c 南岩宫
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>
inherit ROOM;
string look_xiang();

void create()
{
	set("short","南岩宫");
	set("long",@LONG
这里是就是南岩宫。此宫半卧悬崖之下。殿内三清坐像金光闪闪，气
宇轩昂。殿内天井处芳草迷径，百卉争妍。有几个装束醒目的武当三代弟
子从这匆匆走过。南面高台就是真武剑阵。叛师或半路投师者珍重。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"out"	: __DIR__"shizhu",
		"southup": __DIR__"gaotai",
	]));
	set("item_desc",([
		"三清坐像" :	 (: look_xiang :),
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	if( dir == "southup"){
		if((int)me->query("combat_exp",1) < 100000)
			return notify_fail("外面的真武剑阵威力太大，你被内力鼓荡，不能上去。\n");
		if(!mapp(myfam = me->query("family")) || myfam["family_name"] != "武当派")
			return notify_fail("非武当弟子，不能试演真武剑阵。\n");
	}
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_move", "move");
}

string look_xiang()
{
	return"三清坐像纯铜打就，镀以纯金，光照满殿。只是好象三个坐像摆得并不很整齐。\n";
}
int do_move(string arg)
{
	object room, ob;

	ob = this_player();
	if( !arg || arg!="xiang" ) return notify_fail("这里的摆设不能乱动！\n");
	message_vision(HIC
	"$N走到三清坐像背后，用力使劲推移老君像，慢慢的推着，终于推动了……\n"
	"像下露出一个大洞，几排石阶往下伸去，从这里分明通向一个暗道。\n"NOR, ob);
	set("exits/down", __DIR__"nanyan0");
	if( room = find_object(__DIR__"nanyan0") ){
	 room->set("exits/up", __FILE__);
	 message("vision", "天花板忽然发出轧轧的声音，露出一个向上的楼梯。\n",room );
	}
	remove_call_out("close_andao");
	call_out("close_andao", 3);
	return 1;
}

void close_andao()
{
	object room;

	if (!query("exits/down")) return;
	message("vision","只听乒地一声响，老君像自动移回原处。\n", this_object() );
	if( room = find_object(__DIR__"nanyan0") )
	{
	message("vision","只听乒地一声响，向上的洞口自动严严实实地关了起来。\n",room);
	}
	delete("exits/down");
}
