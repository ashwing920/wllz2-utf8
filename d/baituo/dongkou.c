//dongkou
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long",@LONG
这里是山贼的老窝的洞口，守备森严。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongnei",
		"south" : __DIR__"xiaolu4",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 2,
	]));
	setup();
	replace_program(ROOM);
}
