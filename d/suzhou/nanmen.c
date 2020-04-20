// Room: /d/suzhou/nanmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是苏州府的南城门。进进出出的吴侬软语，听来特让人舒服。门口
的官兵开口喝骂，也是这种软绵声气。门上贴着一份告示(gaoshi)。南北
一条笔直的官道。
LONG
);
	set("outdoors", "suzhou");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"road5",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n苏州知府\n冯正东\n";
}

