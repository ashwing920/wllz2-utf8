// /d/xiakedao/shiroom19.c 侠客岛 石室19

inherit ROOM;

int do_study(string arg);
void create()
{
	set("short", "石室");
	set("long", @LONG
这里极为低矮，身材稍高之人便要低头。室内仅余西北角一支火把，
其余的均已燃为灰烬，在昏暗的光线之中，仅有一人盘膝而坐，对照石壁
(wall)比划着。只见掌指交替，繁杂无比。
LONG );
	set("exits", ([
		"west"  : __DIR__"shihole5",
	]));
	set("item_desc", ([
		"wall" : @WALL
墙的正上方刻着「千秋二壮士」几个大字。下方绘出侯嬴与朱亥二人携手
而行，正是古风“侠客行”原意。侧面一行小楷：子曰：知者乐水，仁者
乐山。知者动，仁者静。又注：庄子秋水篇：不知何时止而不盈，尾闾泻
之。
WALL
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
