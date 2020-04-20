// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "丈人峰");
	set("long", @LONG
这里位于玉皇顶以西里许的地方，形状有如一个伛偻的老人。靠西有
黄华洞，因洞路极为危险，后人在进路处写上「回车岩」。从这里往北走
便是岱顶的北天门。
LONG
);
	set("exits", ([
		"east" : __DIR__"yuhuang",
		"northup" : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

