// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "磨捱狱");
	set("long", @LONG
一进来，满鼻的血腥味，几只大磨盘不停的转动着，推磨的赤发鬼累
得满头大汗，不时擦拭着。这里是“皮开肉绽，抹嘴呲牙，乃是瞒心昧己
不公道，巧语花言暗伤人”的人犯受刑之地，人犯轮流被推上磨盘，榨为
肉酱，然后再由黑面鬼放入陶盆，拼凑起来，重塑人形后继续受刑。想来
下面的椎捣狱也不会舒服到哪里。
LONG
);
	set("exits", ([
		"up" : __DIR__"bopi",
		"down" : __DIR__"zhuidao",
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

