// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

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
	set("outdoors", "guiyun");
	set("exits", ([
		"east"	  : __DIR__"shulin4",
		"northwest" : __DIR__"shulin2",
	]));
	set("objects", ([
		__DIR__"npc/fanyifei" : 1,
		__DIR__"npc/luzhengping" : 1,
	]));
	setup();

}
