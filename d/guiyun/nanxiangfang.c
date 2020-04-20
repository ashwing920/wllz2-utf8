// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /guiyun/nanxiangfang.c

inherit ROOM;

void create()
{
	set("short", "男厢房");
	set("long", @LONG
这里是归云庄男弟子的休息室，摆着几张木床。床旁都有一支高脚架
子，用来挂衣物。西首一扇小窗。外面是花园。
LONG
);
	set("sleep_room",1);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	setup();
	replace_program(ROOM);
}

