// xixiang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "财主西厢");
	set("long", @LONG
这是财主小裤的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂着
细纱。小裤正躺在榻上，懒洋洋地一幅思春模样。看到你突然闯进来，惊
呆了。
LONG
);
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/yingying" : 1,
	]));
	setup();
	replace_program(ROOM);
}

