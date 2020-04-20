// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: southroad3.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在南大街坚实的青石板地面上，各色人等往来其中，很是喧闹。
有时你可能会见到一些江湖装束的人物，他们口音各异，服饰也五花八门
，可是中气都很足，可不是好惹的。往东长长的大道就是南大街。西南方
是个很巍峨的建筑群，人进人出，十分热闹。西北通往西大街。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"northwest"  : __DIR__"westroad1",
		"southwest"  : __DIR__"wuhoucigate",
		"east"	   : __DIR__"southroad2",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 2,
		"/d/taishan/npc/dao-ke" : 1,
	]));
	
	setup();
	replace_program(ROOM);
}
