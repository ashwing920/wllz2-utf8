// Room: /d/shaolin/shijie2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
长长的石阶往上依然看不到尽头。身边的山壁受着长年风雨的浸润，
长出了薄薄的青苔。上面依稀有些刻凿的痕迹。有一行字特别清晰：“金
刚伏邪魔，宝塔镇群妖”
LONG
);
	set("exits", ([
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

