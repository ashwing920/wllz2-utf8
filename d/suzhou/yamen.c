// Room: /d/suzhou/yamen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "苏州府衙");
	set("long", @LONG
堂上东西有两根楹柱，挂着一幅对联，但是你根本无心细看。正墙上
悬挂一个横匾，上面横书“正大光明”四个金光闪闪的大字。“肃静”“
回避”的牌子分列两侧。知府正坐在文案后批阅文书，师爷随侍在后。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"south"  : __DIR__"xidajie1",
	]));
	set("objects", ([
		__DIR__"npc/feng": 1,
		__DIR__"npc/shiye": 1,
		__DIR__"npc/yayi": 4,
	]));
	setup();
	replace_program(ROOM);
}
