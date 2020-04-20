//ROOM lianjianshi.c

inherit ROOM;

void create()
{
	set("short", "炼剑场");
	set("long",@LONG
这里是玄兵古洞的炼剑场。四周荒凉没有人烟，地上隐约还能看见斑
斑的血迹，偶尔能看见的几棵树似乎也成了剑的表征，一个个剑拔弩张的
。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，激烈的罡气震得你一阵晕
眩，原来这里正在以内家真气炼剑。
LONG
);
	set("exits", ([
		"south" : "/d/xingxiu/shamo3",
	]));

	set("objects",([
		__DIR__"npc/shijian" :1,
	]));

	setup();
	replace_program(ROOM);
}
