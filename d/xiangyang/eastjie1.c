// Room: /d/xiangyang/eastjie1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边是一个大十字街
口。西面是襄阳的中央广场，北边是襄阳守城大将王坚的府邸大门，只见
那儿守备森严，闲杂人等一般是不能接近的。南面飘来一缕缕的药香，噢
，原来是一家药铺。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"eastjie2",
		"west"  : __DIR__"guangchang",
		"south" : __DIR__"yaopu",
		"north" : __DIR__"jiangjungate",
	]));
	setup();
	replace_program(ROOM);
}

