// Room: /d/fuzhou/zhongzhou.c

inherit ROOM;

void create()
{
	set("short", "中洲桥");
	set("long", @LONG
中洲桥横越闽江，桥面平整，桥下水花喧闹。中洲为一小岛，尽是水
上人家。
LONG );
	set("exits", ([
		"north" : __DIR__"nanmen",
		"south" : __DIR__"puxian",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

