
inherit ROOM;

void create()
{
	set("short","客厅");
	set("long",@LONG
你走进这间小小的厅室, 看到里面放着一张紫檀木茶几和几张湘妃竹
椅子，紫檀木的茶几上摆放着茶壶和几只白玉杯，专供客人饮用。你忍不
住想坐在竹椅上，让疲惫的身心得到充分的休息。
LONG);
	set("exits",([
		"east" : __DIR__"c14-4",
		"north" : __DIR__"c14-2",
		"west" : __DIR__"yunjinlou",
	]));
	set("objects",([
		__DIR__"npc/obj/putao" : 1,
		__DIR__"npc/obj/guiyuan" : 1,
		__DIR__"npc/obj/xiangcha" : 2,
	]));
	setup();
	replace_program(ROOM);
}
