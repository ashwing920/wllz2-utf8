// Room: /d/songshan/dadian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "中岳大殿");
	set("long", @LONG
大殿面阔九间，进深五间，重檐庑殿式屋顶，座落在七尺高的台基上
，气势雄伟。大殿中供奉岳神天中王。
LONG
);
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
	setup();
	replace_program(ROOM);
}

