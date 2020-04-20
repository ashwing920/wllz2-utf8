// /d/xiakedao/shiroom21.c 侠客岛 石室21

inherit ROOM;

int do_study(string arg);
void create()
{
	set("short", "石室");
	set("long", @LONG
进门便觉精神一振，原来上方有一尺许见方的通风孔，不似其他石室
那般气闷。一抹阳光从孔中透入，投在对面的石壁(wall)上。隐隐也能听
见外面的鸟雀叽嚓飞过，令人片刻间神游物外。
LONG );
	set("exits", ([
		"south" : __DIR__"shihole6",
	]));
	set("item_desc", ([
		"wall" : @WALL
墙的正上方刻着「纵死侠骨香」几个大字。下面绘的是春秋时另一个惨烈
的故事「要离刺庆忌」。那要离身材既矮，且又独臂，但一股杀气直是摄
人魂魄。一行注云：韩昌黎诗：想当施手时，巨刃摩天扬。又注：叱咤则
风云变色。
WALL
	]));
	set("objects", ([
		__DIR__"master/miejue" : 1,
		__DIR__"master/zhou"   : 1,
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
