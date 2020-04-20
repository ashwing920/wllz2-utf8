//room: huayuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","花园");
	set("long",@LONG
这是个美丽的大花园，园子里面种着鲜艳的红玫瑰。白衣少女常来这
里嬉戏。沿着弯弯曲曲的花径，可以通到山庄的许多地方。东边是厨房。
西边是白驼山少主欧阳克的内室，门虚掩着，不知主人在不在。
LONG
);
	set("exits",([
		"west" : __DIR__"neishi",
		"north" : __DIR__"zhuyuan",
		"east" : __DIR__"chufang",
		"south" : __DIR__"menlang",
	]));
	set("outdoors", "baituo");

	set("objects",([
		__DIR__"npc/whitelady" : 2,
	]));
	setup();
	replace_program(ROOM);
}






