// Room: /huanghe/shidong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是沙漠中天然形成的一个石洞，洞中光线昏暗，但却十分干燥，地
下铺者几堆稻草，似乎是供人睡卧之用，静心凝听，洞中仿佛有阵阵水声
。洞的一角放着数堆人头骨(skulls)。
LONG
);
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "一堆整整齐齐的骷髅头，上一中三下五，不多不少，恰是九颗白骨骷髅头。\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
	setup();
	replace_program(ROOM);
}

