//xijie
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long",@LONG
这里是小镇的西街。北边有个酒店，门前树立着高高的旗杆，一块青
布幌子迎风飘扬，上面印着朱红色的大字‘酒’。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"bridge",
		"east" : __DIR__"dongjie",
		"north" : __DIR__"jiudian",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
		__DIR__"npc/snaker"  :1,
	]));
	setup();
	replace_program(ROOM);
}
