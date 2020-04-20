//Room: shibapan.c 十八盘
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","十八盘");
	set("long",@LONG
这是一个很大的斜坡，俗称十八盘，大石阶一级一级笔直而上，颇费
脚力。这里坡坡有神，拐拐有祠，往上十里之后即是灵霄宫。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown"  : __DIR__"shiliang",
		"southup"	: __DIR__"shijie2",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
