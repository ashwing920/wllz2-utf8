
inherit ROOM;

void create()
{
	set("outdoors", "tangmen");
	set("short", "翡翠长廊");
	set("long", @LONG
你仍然身处竹林中，这一段竹林全部是高大的楠竹，青石路两旁的竹
子遮天闭日，只是偶尔有点点光亮泄在路上，青青的竹林裹着小路，犹如
翡翠做的一般，所以这儿叫做“翡翠长廊”。
LONG
);
	set("outdoors","tangmen");
	set("exits", ([
		"northwest" : __DIR__"zhulin",
		"east" : __DIR__"fufeng",
	]));
	setup();
	replace_program(ROOM);
}

