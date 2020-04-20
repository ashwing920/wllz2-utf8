// Room: /d/xiangyang/yaopu.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
药铺不大，却异常的整洁；正面是柜台，柜台后面是个大柜子几百个
小抽屉上一一用红纸标着药材的名称；靠近屋顶的墙上悬着一块黑底金字
的匾额，写着“妙手回春”。地下几个伙计正在分拣刚刚收购来的草药。
东边一张小矮桌儿，上面放着笔墨纸砚，桌后坐着一位老郎中。一股刺鼻
药味充满了整个房间。
LONG
);
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	setup();
	replace_program(ROOM);
}
