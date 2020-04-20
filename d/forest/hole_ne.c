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
	set_maze_npcs(__DIR__"npc/bianfu");
	set_maze_npcs(__DIR__"npc/dushe");
	
	//迷宫内出现生物的随机度
	set_random_rate(50);
	
	//迷宫出现生物个数
	set_char_num(5);

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"hole08");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"hole11");

	//入口房间短描述
	set_entry_short("洞中岔路");

	//入口房间描述
	set_entry_desc(@LONG
这是一条崎岖的洞中岔道，岔道内阴冷潮湿，呼啸的阴风从洞里扑面
袭来，让人不禁全身发抖，直打冷颤。岔道的地面尽是一滩滩的积水，水
声、脚步声掺杂一起，倒也十分热闹。
LONG
);

	//出口房间短描述
	set_exit_short("洞中岔路出口");

	//出口房间描述
	set_exit_desc(@LONG
你来到岔路的深处，眼前出现了一个十分宽敞的洞庭。洞庭四周的墙
壁上，倚靠着几具已经干枯的骸骨，从骸骨上看去，想必已经是死去很久
了。有的骸骨已经残缺不齐，象是掉落，又象是被野兽所蚕食。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("洞中岔路");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一条崎岖的洞中岔道，岔道内阴冷潮湿，呼啸的阴风从洞里扑面
袭来，让人不禁全身发抖，直打冷颤。岔道的地面尽是一滩滩的积水，水
声、脚步声掺杂一起，倒也十分热闹。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
