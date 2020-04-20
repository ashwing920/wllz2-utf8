// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long", @LONG
这是一很安静的走廊，西边是五毒神教第子休息的地方，南边不时可
以听到练武的声音，原来那是间练功房。
LONG
);
	set("exits", ([
		"east" : __DIR__"xiuxishi",
		"south" :__DIR__"liangongfang",
		"west"  :__DIR__"qianting",
	]));
	setup();
	replace_program(ROOM);
}



	