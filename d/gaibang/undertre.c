// Room: /d/gaibang/undertre.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "树洞下");
	set("long", @LONG
这是老槐树底部，四周光线昏暗，人影晃晃，似乎有几个黑暗的洞口
在你身边，通向四面八方。  一位老乞丐大咧咧地坐在正中的地上。不经
意中你发现墙壁上画着幅粗糙的路线草图（map）。
LONG
);
	set("exits", ([
		"up"   : __DIR__"inhole",
		"down" : __DIR__"chuchang",
		"1"	: __DIR__"xcandao1",
		"2"	: __DIR__"zlandao1",
		"3"	: __DIR__"slandao1",
		"4"	: __DIR__"xxandao1",
		"5"	: __DIR__"wdandao1",
		"6"	: __DIR__"hsandao1",
		"7"	: __DIR__"bjandao1",
		"8"	: __DIR__"qzandao1",
		"9"	: __DIR__"xsandao1",
		"a"	: __DIR__"dlandao1",
		"b"	: __DIR__"fzandao1",
	]));
	set("item_desc",([ "map" : 
		"出口一：通往小村。\n" +
		"出口二：通往竹林。\n" +
		"出口三：通往少林。\n" +
		"出口四：通往星宿。\n" +
		"出口五：通往武当。\n" +
		"出口六: 通往华山。\n" +
		"出口七：通往北京。\n" +
		"出口八：通往嘉兴。\n" +
		"出口九：通往雪山。\n" +
		"出口Ａ：通往大理。\n" +
		"出口Ｂ：通往福州。\n"
	]));
	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

