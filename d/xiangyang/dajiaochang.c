// Room: /d/xiangyang/daxiaochang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大校场");
	set("long", @LONG
这是襄阳守军用来校阅军士的地方。只见校场正中巍巍搭着一座高台
，台南排列着千余张椅子板凳。台前竖着两根旗杆，旗杆顶上有着硕大的
旗斗。校场里聚集着数百个四袋以上的丐帮弟子。他们都是来竞选新任丐
帮帮主的。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"north" : __DIR__"westjie3",
	]));
	setup();
	replace_program(ROOM);
}
