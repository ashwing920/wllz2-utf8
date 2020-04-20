// Room: /d/taishan/taishanjiao.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "泰山脚下");
	set("long", @LONG
泰山古称岱山，为五岳的东岳，为道教第二小洞天，向有五岳独尊之
称誉，以泰山天下雄名闻域内。往北就到岱宗坊了。
LONG
);
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yidao3",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

