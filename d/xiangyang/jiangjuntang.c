// Room: /d/xiangyang/jiangjuntang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "将军府大堂");
	set("long", @LONG
这里是将军府的大堂，公案后端坐着一个威猛的将军，但一脸疲惫，
看来征战刚归的模样。大堂两边摆着兵器架，架上锋刃仍留血迹，映着架
后的战旗，分外耀眼。两班将佐，虽征尘未洗，但斗志昂扬，甚是雄壮。
LONG
);
	set("exits", ([
		"south" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
		__DIR__"npc/zuo" : 1,
		__DIR__"npc/pian" : 1,
		__DIR__"npc/ya" : 1,
		__DIR__"npc/pi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

