//tianweitang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "天市堂");
	set("long", @LONG
你一进入明教的天市堂，顿时感到一鼓肃杀之气。教众出入都十分小
心，惟恐惊动了坐在油木桌后的堂主李天垣。见你进来李天垣抬眼看了看
你，一张很柔和的脸却立马让你心惊肉跳。
LONG
);
	set("exits", ([
		"west"  : __DIR__"tianweitang",
	]));
	set("objects",([
		 __DIR__"npc/litianyuan":1,
		 __DIR__"npc/yinwulu":1,
	]));
	setup();
	replace_program(ROOM);
}
