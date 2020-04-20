// Room: /d/xiangyang/guofuting.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "郭府客厅");
	set("long", @LONG
这里是郭府的客厅。厅虽不大，却布置的挺雅致。东壁悬挂着四幅屏
条，绘的是梅兰菊竹四种花卉；西壁悬挂的是春夏秋冬。内厅居中的是一
张八仙桌。桌上端放着一套茶具，两旁摆放着四张檀香椅，显得极为古朴
。厅角各摆放着一盆牡丹花，似乎给这里带来一丝暖意。北壁内墙的神龛
供奉岳飞的画像，上面是一条横幅，上书“还我河山”。
LONG
);
	set("exits", ([
		"south" : __DIR__"guofuyuan",
		"north" : __DIR__"guofuhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/guo" : 1,
	]));
	setup();
	replace_program(ROOM);
}

