//Room: /d/dali/yuhuayuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","御花园");
	set("long",@LONG
这里是大理国皇宫的御花园，两旁的花开得争奇斗艳，边上有一个小
水池，山上流下来的泉水就会集在那里，几只仙鹤在水边抓鱼，一副旁若
无人的样子，往北是花廊，往南是前殿。
LONG
);
	set("objects", ([
		__DIR__"npc/xianhe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"hualang",
		"south"  : __DIR__"qiandian",
	]));
	setup();
	replace_program(ROOM);
}

