#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short","花丛");
	set("long",@LONG
你信步观赏, 只见花林中除山茶花外更无别样花卉, 连最常见的牵牛花,
月月红, 蔷薇之类也是一朵都无。走出数十丈后, 只见山茶品种渐多, 偶
而也有一两本还算不错, 却也栽种不得其法。东面就是庄门了。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"north" : __DIR__"anbian",
		"east" : __DIR__"zhuangmen",
		"west" : __DIR__"hc3",
]));
	setup();
	replace_program(ROOM);
}
