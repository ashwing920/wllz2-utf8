// Room: /d/taohua/thmz.c

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/shanzei");
	set_maze_npcs(__DIR__"npc/shanzeitoumu");
	set_maze_npcs(__DIR__"npc/louluo");

	//迷宫内出现生物的随机度
	set_random_rate(80);

	//迷宫出现生物个数
	set_char_num(8);

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"main1");

	//出口与区域的连接方向
	set_link_exit_dir("up");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"up1");

	//入口房间短描述
	set_entry_short("盗贼山洞");

	//入口房间描述
	set_entry_desc(@LONG
一个光线昏暗的山洞，洞中两边各插着火把，火光闪烁，飘忽不定。
这里便是华山村附近一带的山贼藏匿的地点。从这里往洞里望去，火光闪
闪，却不见一个人影，只有那火把燃烧的声音，不时发出噼啪的声响。
LONG
);

	//出口房间短描述
	set_exit_short("盗贼山洞");

	//出口房间描述
	set_exit_desc(@LONG
这里已是山洞的末端，向南面望去，有一条岩石铺成的阶梯一直往上
方延伸，不时间传来阵阵脚步声。想必上面一定有人把守，你不得不提高
警惕，死死的盯着阶梯上方。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("盗贼山洞");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
一个光线昏暗的山洞，洞中两边各插着火把，火光闪烁，飘忽不定。
这里便是华山村附近一带的山贼藏匿的地点。从这里往洞里望去，火光闪
闪，却不见一个人影，只有那火把燃烧的声音，不时发出噼啪的声响。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
