//htqdating.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "厚土旗大厅");
	set("long", @LONG
这里是厚土旗的大厅，厅中刀枪如林，黄旗招展，教众穿着铁甲钢盔
，腰间别着锹铲锤钻，一个个精神抖擞。正中端坐着个矮墩汉子，就是厚
土旗掌旗使颜垣。
LONG
);
	set("exits", ([
		"out" : __DIR__"htqmen",
	]));
	set("objects", ([
		__DIR__"npc/yanyuan": 1,
	]));
	setup();
	replace_program(ROOM);
}
