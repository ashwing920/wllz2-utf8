//Room: fuzhenguan.c 复真观五层楼
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","复真观五层楼");
	set("long",@LONG
复真观五层楼构造奇特，其间有十二根梁枋交叉重叠，下面仅用一柱
支撑，即有名的“一柱十二梁”。在这里俯瞰群山，烟云迷离，远望金顶
，一柱擎天，为观景胜地。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"west"	 : __DIR__"taizipo",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
