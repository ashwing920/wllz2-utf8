// Room: /d/suzhou/beimen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是苏州府的北城门。出门远远可见西面的虎丘山。放眼望去尽是绿
的田，翠的草和清清的小河。门边官兵身后贴着一份告示(gaoshi)。南北
一条笔直的官道。
LONG
);
	set("outdoors", "suzhou");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"north" : __DIR__"road1",
		"south" : __DIR__"beidajie2",
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
