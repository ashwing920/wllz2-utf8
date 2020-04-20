// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","草丛");
	set("long",@LONG
这里是乱草丛。东边是扇拱月形小敞门。其余三面都是齐腰高的蒿草
，常有蛇出没。
LONG
);
	set("exits",([
		"west" : __FILE__,
		"north" : __DIR__"cao2",
		"east" : __DIR__"ximen",
		"south" : __FILE__,
	]));
	set("objects",([
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	setup();

}




