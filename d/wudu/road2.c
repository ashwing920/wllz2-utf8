// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条不宽的小路，上面以石板铺垫，路上来往的行人不多，向南
望去，隐隐可以看见群山之中围绕着一面湖水，那就是滇池了。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"south" : __DIR__"road3",
		"north" : __DIR__"road1",
	]));
	setup();
	replace_program(ROOM);
}

