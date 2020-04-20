// Room: /d/taohua/thmz.c

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/renfanzi");
	set_maze_npcs(__DIR__"npc/shanzeitoumu");
	set_maze_npcs(__DIR__"npc/shanzeishouling");

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
	set_link_entry_room(__DIR__"up1");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"laolong");

	//入口房间短描述
	set_entry_short("盗贼山洞二层");

	//入口房间描述
	set_entry_desc(@LONG
你已经来到了盗贼山洞的第二层之上。只见山洞两边各间隔的插着几
把火把，火光闪闪。透过昏暗的火光，不时可以看到山洞中，仿佛有几个
人影在来回晃动，可仔细看去，又好象什么也没有。洞中诡异非常，你不
得不提高警惕。
LONG
);

	//出口房间短描述
	set_exit_short("盗贼之穴");

	//出口房间描述
	set_exit_desc(@LONG
这里盗贼山洞二层的末端，只见南面有一个牢笼，里面关押了几个妇
人和小孩，看见你走过来，一脸恐惧看着你。几个盗贼喽罗正在牢笼门前
，有的则在喝酒猜拳，视若无人；有的则来回走动，小心翼翼的观察着周
围的环境。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("盗贼山洞二层");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
你已经来到了盗贼山洞的第二层之上。只见山洞两边各间隔的插着几
把火把，火光闪闪。透过昏暗的火光，不时可以看到山洞中，仿佛有几个
人影在来回晃动，可仔细看去，又好象什么也没有。洞中诡异非常，你不
得不提高警惕。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
