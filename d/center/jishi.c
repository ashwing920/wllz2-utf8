// jishi.c - 集  市
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>
inherit ROOM;
int cot;
void create()
{
	set("short", "集市");
	set("long", @LONG
这里是扬州城集市。满街的店铺都挂着一团团、一簇簇的羊角风灯。
一声接一声的叫卖声在各个街口、小巷深处此呼彼应，连绵不绝。集市的
入口处，挂着一块牌子(sign)。
LONG
);
	set("exits", ([
		"south"  : __DIR__"roade3",
		"north"  : __DIR__"shambles", 
	]) );                   
	setup();
	replace_program(ROOM);
}
