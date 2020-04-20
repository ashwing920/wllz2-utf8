// Room: /d/suzhou/hanshidian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "寒拾殿");
	set("long", @LONG
这里供奉着相传为“和合二仙”化身的寒山，拾得金身塑像，形态生
动，逗人喜爱。寒山寺每年除夕半夜，撞钟一百零八响，其含义是除旧迎
新和纪念佛门一百零八位高僧。
LONG
);
	set("exits", ([
		"out"   : __DIR__"fengqiao",
		"west"  : __DIR__"zhengdian",
	]));
	setup();
	replace_program(ROOM);
}

