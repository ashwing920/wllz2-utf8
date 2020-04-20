// Room: /d/taishan/zhengqi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "正气厅");
	set("long", @LONG
这里是封禅台右边的正气厅，武林盟罚恶使者平时不下山时，通常都
是在这里处置武林公案。上首正中放着把虎皮椅，罚恶使者就坐在上面开
堂审理。左右各侍立着几位红衣武士，看上去杀气腾腾，令人凛然而生惧
意。
LONG
);
	set("exits", ([
		"east" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/fa-e" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	setup();
	replace_program(ROOM);
}

