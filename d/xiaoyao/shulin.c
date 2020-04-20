// Room: /d/taohua/thmz.c
// 桃花迷阵

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
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");

	//入口与区域的连接档案名
	set_link_entry_room("/d/wudang/wdroad4");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"shulin_in");

	//入口房间短描述
	set_entry_short("树林");

	//入口房间描述
	set_entry_desc(@LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼
天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出
的声响。
LONG
);

	//出口房间短描述
	set_exit_short("树林");

	//出口房间描述
	set_exit_desc(@LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼
天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出
的声响。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("树林");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼
天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出
的声响。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
