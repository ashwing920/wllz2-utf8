// Room: /d/taohua/thmz.c
// 松树林

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"songlin-end");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"changlang");

	//入口房间短描述
	set_entry_short("松树林外的空地");

	//入口房间描述
	set_entry_desc(@LONG
不知不觉，你已来到了松树林尽头，前面是一片空地，一个青年男子
正手握长剑，正在练习剑法，不时发出嗖嗖的声响，树上的松树叶儿，也
应声轻轻飘落。
LONG
);

	//出口房间短描述
	set_exit_short("松树林的尽头");

	//出口房间描述
	set_exit_desc(@LONG
这里是松林外的空地，只见北面一面密密麻麻的松树林，清风吹过，
发出沙沙的声响，偶尔从林中传来阵阵小鸟的鸣叫声。南面是一条长廊。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("松树林");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是华山上的一片松树林。几丈高的松树密密麻麻，遮得几乎不见天
日。地上落满松针，有不知名的野兔偷偷逃过。寂静的松林中，却不时间
传出一阵嗖嗖的声响，象风声，更像兵刃飞舞的声响 . . .十分怪异。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
