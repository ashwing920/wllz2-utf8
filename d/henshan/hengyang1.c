// Room: /d/henshan/hengyang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "衡阳西街");
	set("long", @LONG
你走在碎石铺就的狭小恐道上。街上时常有人持剑疾行，似乎这里出
了啥事了。南边是一家小店，北面一座大宇巍峨，重檐叠瓦，门口彩灯高
悬，管家家丁好象都是武林中人。
LONG
);
	set("outdoors", "henshan");
	set("exits", ([
		"east"   : __DIR__"hengyang",
		"west"   : __DIR__"hsroad4",
		"south"  : __DIR__"shop",
		"north"  : __DIR__"liufugate",
	]));
	setup();
	replace_program(ROOM);
}

