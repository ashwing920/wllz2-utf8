// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","草丛");
	set("long",@LONG
这里是乱草丛。北边是青竹林。其余三面都是齐腰高的蒿草，常有蛇
出没。
LONG
);
	set("exits",([
		"west" : __FILE__,
		"north" :__DIR__"zhulin",
		"east" : __DIR__"cao1",
		"south" : __DIR__"cao1",
	]));
	set("objects",([
		__DIR__"npc/qingshe" : random(2),
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	setup();

}


