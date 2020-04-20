//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小路上，小路泥泞不堪，隐约留下几个路人的脚印。前面
的道路更为崎岖，行人十分稀少，据说这里经常有盗贼出没，你还是快点
离开的好。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"southwest" : __DIR__"road1",
		"north"	 : __DIR__"zhuang2",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	setup();
	replace_program(ROOM);
}



