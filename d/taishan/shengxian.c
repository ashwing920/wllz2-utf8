// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "升仙坊");
	set("long", @LONG
这里是十八盘的中间，从龙门至此的一段称为缓十八，从这里直上南
天门的一段称为紧十八。由此刻攀石而上，后面的人可以看到前面的人的
鞋底，前面的人回头则可见到后面的人的发顶。在这里一般人每走十来步
便要稍一休息。
LONG
);
	set("exits", ([
		"northup" : __DIR__"nantian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

