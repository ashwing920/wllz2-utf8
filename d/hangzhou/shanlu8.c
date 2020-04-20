// shanlu8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山上林木茂密，就是炎夏这里还是清凉依旧。朝北走便到了黄龙洞。
南边则是下山的路。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"road7",
		"north"	 : __DIR__"huanglongdong",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
