// /d/xiakedao/shiroom05.c 侠客岛 石室5

inherit ROOM;

int do_study(string arg);
void create()
{
	set("short", "石室");
	set("long", @LONG
一位仙风道骨的老者正和一位高大的西域人切磋武功，两人均是虚持
空剑，招式忽快忽慢，阵阵劲风将室内的火把激荡得明暗不定，火光闪闪
，石壁(wall)上图案亦是班驳陆离。
LONG );
	set("exits", ([
		"south" : __DIR__"shihole2",
	]));
	set("item_desc", ([
		"wall" : @WALL
墙的正上方刻着「十步杀一人」几个大字。其下的图案却是一副工笔山水
，画的是山边密林，那树木的枝条长短不一，前后纵横，倒也笔力雄健，
栩栩如生。图旁有无数小注。
WALL
	]));
	set("objects", ([
		__DIR__"master/ouyangfeng" : 1,
		__DIR__"master/ding"       : 1,
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
