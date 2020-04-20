//TORJQ2.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这里大道平坦，地势开阔，两旁树林中鸟语花香，一片和平安祥的气
氛。此时又有谁能想到，这条大道上撒下过多少江湖中人的血，这片林中
又埋有多少惨死于武林争斗的冤魂的骨。远处，隐约传来叮叮咚咚的伐木
声，偶尔能让人追忆起刀戈铁马的沙场景象。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"tojmq3",
		"southeast" : __DIR__"tojmq1",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
