// kaiyuan.c 开元寺
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "开元寺");
	set("long", @LONG
这是一座规模宏大的千年古刹，莲宫桂宇，焕彩流金，刺桐掩映，古
榕垂荫。游人未抵门前，远远可见两座石塔凌空而起，矗立于千楼万舍之
上。它建于唐武则天二年，全寺占地庞大，是福建最大的佛教建筑之一。
寺外正面和西面，环立白石栏杆，并植刺桐。大门开启，接纳着络绎不绝
的虔诚香客。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"tianwang",
		"south" : __DIR__"citong_w2",
	]));
	set("objects", ([
		__DIR__"npc/guest" : 2,
	]));
	setup();
	replace_program(ROOM);
}
