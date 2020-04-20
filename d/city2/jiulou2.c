//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "全聚德酒楼二楼");
	set("long", @LONG
这里全聚德酒楼二楼的雅座，文人学士经常在这里吟诗作画，富商土
豪也在这里边吃喝边作交易。这里也是城里举办喜宴的最佳场所。墙上挂
着价格牌子(paizi)。你站在楼上眺望京城，只觉得心旷神怡。
LONG
);
	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		"/d/city2/npc/cheng":1,
	]));

	setup();
	replace_program(ROOM);
}
