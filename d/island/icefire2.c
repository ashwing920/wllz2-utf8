//Cracked by Kafei
// kane: 98/3/025

inherit ROOM;

void create()
{
	set("short", "冰火岛");
	set("long", @LONG
这里是岛上的一大片树林，除了低丘高树之外，尽是青草奇花。草丛
之中，偶而惊起一些叫不出名目的大鸟小兽，看来也皆无害于人。西北角
上有一座石山，山脚下露出一个石洞。
LONG
);
	set("exits", ([
		"south" : __DIR__"icefire1",
		"northwest" : __DIR__"icefire3",
	]));
	set("outdoors", "island");
	setup();
	replace_program(ROOM);
}

