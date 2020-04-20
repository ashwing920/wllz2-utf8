// Room: /d/shaolin/dzdian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "地藏殿");
	set("long", @LONG
这是地藏殿。供奉地藏王菩萨。地藏王主宰阴间，手下自然有不少鬼
兵鬼卒，罗列帐前。菩萨眉横煞气，手断阴阳。令人一见之下，顿觉心惊
胆战，惶恐不已。
LONG
);
	set("exits", ([
		"east" : __DIR__"guangchang5",
	]));
	setup();
	replace_program(ROOM);
}

