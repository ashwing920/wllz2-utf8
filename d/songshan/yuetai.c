// Room: /d/songshan/yuetai.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "月台");
	set("long", @LONG
这里是法王寺的月台。从月台东望，太室山峦高耸入云，寺东有双峰
插云，中间阙如。因名嵩门。中秋佳节，明月自峰中升起，正当嵩门
之中，银光洒满山谷，这就是登封八景之一的嵩门待月。
LONG );
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("objects", ([
		__DIR__"npc/fei" : 1,
	]));

	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

