// Room: /huanghe/shulin5.c
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
		"west"	  : __DIR__"shulin6",
		"southeast" : __DIR__"shulin4",
		"northeast" : __DIR__"tiandi2",
	]));
	set("objects", ([
		"/d/hangzhou/npc/maque" : 2,
		"/d/taishan/npc/tangzi" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

