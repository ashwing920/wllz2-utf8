// mishi.c 密室
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是全真教弟子闭关修炼所用的密室，这里的光线非常昏暗，密室
中空空如也，只有一张可容纳几个人坐的大石板，孤零零的摆设在密室的
正中。
LONG
);
	set("exits", ([
		"up" : __DIR__"diziju",
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}

