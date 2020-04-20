// /d/xiakedao/shiroom02.c 侠客岛 石室2

inherit ROOM;

int do_study(string arg);

void create()
{
	set("short", "石室");
	set("long", @LONG
进入第二间石室，只觉眼前一花，端的是剑气纵横。数人各持长剑，
正在捉对较量，兵刃撞击，铮铮不绝。地上遗弃着几柄长短不一的断剑，
墙上也有些兵器劈砍的斑痕。旁边有两位老者正在争论着什麽。石室的石
壁(wall)上有若干字迹，好象写着什么。
LONG );
	set("exits", ([
		"north" : __DIR__"shihole1",
	]));
	set("item_desc", ([
		"wall" : @WALL
墙的正上方刻着「吴钩霜雪明」几个大字。大字的下方又密密麻麻地刻满
了数千小字，笔划各异，大小不同。第一行是：鲍照乐府：“锦带配吴钩
”。又有一行写的是：白居易诗云：“勿轻直折剑，犹胜曲全钩”。
WALL
	]));
	set("objects", ([
		__DIR__"master/zhang" : 1,
		__DIR__"master/feng"  : 1,
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
}
void init()
{
	add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
