// Room: /d/henshan/lingxingmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "棂星门");
	set("long", @LONG
这里是南岳大庙的第一道门，由汉白玉，花岗石打就的石牌坊。南岳
衡山是祝融游息之地，道教奉为第三小洞天。在此远望衡山，山势如飞，
如云雾中凌空的大鸟。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north"  : __DIR__"kuixingge",
		"south"  : __DIR__"hengyang",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

