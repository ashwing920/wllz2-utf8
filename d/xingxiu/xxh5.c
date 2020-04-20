// Room: /d/xingxiu/xxh5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是星宿海的尽头。因为附近有野羊出没，所以星宿派弟子常常在
此烤羊肉串吃。当打不到野羊时，他们就抢山下牧人的羊。
LONG
);
	set("exits", ([
		 "southeast" : __DIR__"xxh3",
		 "southwest" : __DIR__"xxh4",
	]));
	set("objects", ([
		   "/d/xingxiu/npc/boshou"  : 1,
		   "/d/xingxiu/obj/yangrou.c" : 2,
	]));
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}


