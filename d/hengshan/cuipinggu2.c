// Room: /d/hengshan/cuipinggu2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "翠屏谷");
	set("long", @LONG
这里峡谷幽深，石壁陡直，两崖壁立，一涧中流。就在这地势绝险的
恒山山谷中，却有数十殿堂悬挂在翠屏山腰。它们上载危岩，下临深谷，
错落有致，如玉宇琼楼自空中冉冉降落。那就是悬空寺了。
LONG
);
	set("exits", ([
		"up"	 : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));
	set("outdoors", "hengshan");
	setup();
	replace_program(ROOM);
}

