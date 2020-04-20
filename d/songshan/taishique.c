// Room: /d/songshan/taishique.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "太室阙");
	set("long", @LONG
嵩山古称方外，又称崇山，为五岳中的中岳，由太室少室二山沿绵而
成。汉武帝时称嵩高，取自诗经嵩岳维高，峻极于天，道教以之为第六小
洞天。阕高丈余，南面刻$MAG$中岳太室阳城$NOR$六字，篆文古朴，苍劲有力。向西
就是去少室山少林寺的路。向北一里许便是中岳庙了。
LONG
);
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/yao" : 1,
	]));
	setup();
	replace_program(ROOM);
}

