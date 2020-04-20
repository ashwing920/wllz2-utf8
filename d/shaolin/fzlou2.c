// Room: /d/shaolin/fzlou2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写着大大的
一个『禅』字。一位慈眉善目的灰衣老僧正端坐于蒲团上打坐。
LONG
);
	set("exits", ([
		"south" : __DIR__"fzlou1",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-ci" : 1,
	]));
	setup();
	replace_program(ROOM);
}

