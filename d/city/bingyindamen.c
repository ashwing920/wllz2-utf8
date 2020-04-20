// bingyindamen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "兵营大门");
	set("long", @LONG
你正站在兵营的门口，面对着一排简陋的营房，可以看到穿着制服的
官兵正在操练，不时地传来呐喊声。老百姓是不允许在此观看的，你最好
赶快走开。
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"xidajie1",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

