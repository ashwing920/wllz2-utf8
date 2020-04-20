//Room: /d/dali/road2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","官道");
	set("long",@LONG
脚下崎岖的土路穿越川南的山区连接南北，这里已经进入云贵，横断
山脉延绵耸立，乃是一道天然屏障隔绝南昭和蜀中。继续向西南穿过山区
，可达大理，北去下山即是天府之国。道路两旁都是一望无际的崇山峻岭
(mountain)，和联绵不绝的大森林(forest)。
LONG
);
	set("outdoors", "dali");
	set("item_desc",([
		"mountain" :"中国大西南的横断山脉，山势陡峭，延绵千里，实乃壮哉！\n",
		"forest"   :"横断山脉最有名的就是这大原始森林了。由于地形太崎岖，难以采伐，千年的参天古木覆盖了整片山区。\n",
	]));
	set("exits",([ /* sizeof() == 1 */
		"northeast"  : __DIR__"road1",
		"southwest"  : __DIR__"road3",
	]));

	setup();
	replace_program(ROOM);
}

