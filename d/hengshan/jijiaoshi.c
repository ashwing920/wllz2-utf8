// Room: /d/hengshan/jijiaoshi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "鸡叫石");
	set("long", @LONG
北岳庙的西侧，有一尺许见方的石头，称鸡叫石。击之，咯咯作鸡鸣
声，故名。清晨敲击，引起山谷回声，如群鸡争鸣，就称金鸡报晓。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"beiyuemiao",
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}

