//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: wanxingan.c 万行庵

inherit ROOM;

void create()
{
	set("short","万行庵");
	set("long",@LONG
太子坪万行庵是古智禅师创建的。庵外满山长满莎椤花，花数芭合成
一朵，叶子包在花外，古人以其根坚难易而盛赞之，以喻洁身自好之高贵
品质。由此向南上便至金顶，下至接引殿。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/jia" : 1,
	]));
	set("outdoors", "emei");
	set("exits",([ 
		"eastdown"  : __DIR__"jieyindian",
		"southup"   : __DIR__"jinding",
	]));

	setup();
	replace_program(ROOM);
}
