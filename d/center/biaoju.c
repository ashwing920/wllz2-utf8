// biaoju.c - 镖  局
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "龙门镖局");
	set("long", @LONG
这里是桃源城的龙门镖局。一座结构宏伟的建筑前，左右石坛上各插
着一根两丈多高的旗杆，杆上青旗飘扬。右首旗子用金线绣着一头张牙舞
爪的狮子。左首旗子上写着“龙门镖局”四个黑字，银钩铁划，刚劲非凡
。门口处排着两条长凳，几名镖师正坐着把守。
LONG
);
	set("exits", ([
		"east"	: __DIR__"roadn2",
		"west":   __DIR__"biaoju-2",
	]) );			

	set("objects", ([
		"/d/taishan/npc/tangzi": 3,
		__DIR__"npc/biaotou":1,
	]) );
	setup();
	replace_program(ROOM);
}
