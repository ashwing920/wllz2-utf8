// Room: /d/taohua/thmz.c
// 桃花迷阵

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/yuanhou");
	set_maze_npcs(__DIR__"npc/tuying");
	set_maze_npcs(__DIR__"npc/bird");
	set_maze_npcs(__DIR__"npc/jinshe");
	
	//迷宫内出现生物的随机度
	set_random_rate(50);
	
	//迷宫出现生物个数
	set_char_num(5);

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"path07");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"path08");

	//入口房间短描述
	set_entry_short("松树林");

	//入口房间描述
	set_entry_desc(@LONG
你来到了的松树林当中，只见松树林中有树高叶茂，每个松树至少都
有上百年的树龄了。密密麻麻的枝叶将整片树林遮挡得十分阴暗。阳光照
射进来，形成道道光束。借着微弱的光芒，你看到前方仿佛有一条出路。
LONG
);

	//出口房间短描述
	set_exit_short("松树林外");

	//出口房间描述
	set_exit_desc(@LONG
几经周则，你终于走出了那片令人发迹的松树林。眼前出现了一道泥
泞的黄土路，路面上惭留着几个深深的，足有两个脚掌般大小的脚印。林
中之大，万物更生，你不得不佩服大自然的力量。北面有一个山洞，黑漆
漆的，看不清洞里有什么。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("松树林中");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
你来到了的松树林当中，只见松树林中有树高叶茂，每个松树至少都
有上百年的树龄了。密密麻麻的枝叶将整片树林遮挡得十分阴暗。阳光照
射进来，形成道道光束。借着微弱的光芒，你看到前方仿佛有一条出路。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
