// Room: /d/fuzhou/yamen.c

inherit ROOM;

void create()
{
	set("short", "提督衙门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌
子分放两头石狮子的旁边。前面有一个大鼓，几名戈什哈站在门前。
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/geshiha" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("geshiha", environment(me))) && dir != "east")
		return notify_fail("戈什哈喝道：“施大人已去校场阅兵，你来核干？”\n");
	return ::valid_leave(me, dir);
}
