//TOJMQ1.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这里是通往巨木旗的大道。道路开阔，大概可容十人并肩而行。现在
巨木旗是明教五旗中人数最多，机关构筑最杂的。除了守护明教外围，还
负责明教中所有房屋和栈桥的建造。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"tojmq2",
		"southeast" : __DIR__"lhqpaifang",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
