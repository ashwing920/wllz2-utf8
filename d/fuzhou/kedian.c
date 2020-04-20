// Room: /d/fuzhou/kedian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
山野客店十分简陋。一个小二临台买卖，一片破门扇扑在地上，显得
相当忙乱。柜台上贴着个牌子(paizi)。
LONG
);
	set("exits", ([
		"east" : __DIR__"erbapu",
	]));
	set("item_desc", ([
		"paizi" : "即日起只供应吃喝，不留宿。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

