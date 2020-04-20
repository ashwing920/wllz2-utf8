
inherit ROOM;

void create()
{
	set("short","小厅");
	set("long",@LONG
你走进这间小小的厅室, 看到里面放着一张紫檀木茶几和几张湘妃竹
椅子，紫檀木的茶几上摆放着茶壶和几只白玉杯，专供客人饮用。你忍不
住想坐在竹椅上，让疲惫的身心得到充分的休息。
LONG);
	set("exits",([
		"east" : __DIR__"xiangfang",
		"north" : __DIR__"chufang",
		"south" : __DIR__"houtang",
		"west" : __DIR__"xiaojing4",
	]));
	set("objects",([
		__DIR__"npc/obj/xiangcha" : 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query("family/family_name") != "慕容世家"
	&& objectp(present("a bi", environment(me))))
		return notify_fail("阿碧喝道：“到慕容山庄不要乱闯呀”。\n");
	return ::valid_leave(me, dir);
} 
