// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "宝藏岭");
	set("long", @LONG
这里是泰山的一个名胜。岭上有一座状似狮子的巨石，称为狮子崖。
最出名的还是要数在东北面的东岳庙，也称上岳庙，是古代封禅的地方，
那里有一块唐玄宗的纪泰山铭。
LONG
);
	set("exits", ([
		"westup" : __DIR__"bixia",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

