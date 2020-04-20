//guanwai/tianchi1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "白头山天池");
	set("long", @LONG
“天池在长白山巅中心点，群峰环抱，离地高约二十里，故名天池。
”天池碧波盈盈，清澈湛蓝。湖周围峭壁百丈，峰影云影倒映其中，湖光
山色、岚影云天十分诱人。湖岸周遭芳草茵茵，百花吐艳。古人诗云：“
周迥八十里，峭壁立池边。水满疑天池，云低别有天。江山宜漫画，鹿逐
结前缘。予卜携书隐，遨游慰晚年。”
LONG
);
	set("exits", ([
		"south"	: __DIR__"tianchi2",
		"northup"  : __DIR__"longmen",
		"westup"   : __DIR__"baiyun",
		"eastup"   : __DIR__"huagai",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
