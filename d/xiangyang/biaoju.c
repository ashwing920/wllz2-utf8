// Room: /d/xiangyang/biaoju.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "福威镖局");
	set("long", @LONG
你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗
杆，杆上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的狮子，狮子上头
有一只蝙蝠飞翔。左首旗子上写着“福威镖局襄阳分号”八个黑字，银钩
铁划，刚劲非凡。入口排着两条长凳，几名镖头坐着把守。
LONG
);
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
	setup();
	replace_program(ROOM);
}

