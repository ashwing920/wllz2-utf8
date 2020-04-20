// fengdong.c 风动岩
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "风动岩");
	set("long", @LONG
这是灵山的北麓，林木茂盛，奇石磷磷。中有一块似方而圆的天然岩
石，只要一人用手摇撼，它就能兀然而动。它甚至弱不禁风，阵风吹来，
似乎也会摆动，人称「风动岩」，又名「碧玉球」，上刻「天然机妙」。
有诗云：「动时锦水将轮转，圆处巴山作镜看」。
LONG
);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
