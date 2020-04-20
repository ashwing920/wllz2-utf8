// Room: /huanghe/shulin4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密
的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的
啸声使人不觉犹豫了前进的脚步。
LONG
);
	set("exits", ([
		"northwest"  : __DIR__"shulin5",
		"east"	   : __DIR__"shulin3",
		"south"	  : __DIR__"shulin2",
	]));
	set("objects", ([
		"/d/baituo/npc/fox" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

