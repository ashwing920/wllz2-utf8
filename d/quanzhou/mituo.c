// mituo.c 弥陀岩
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "弥陀岩");
	set("long", @LONG
这里古木参天，巨石峭立。多雨时节，有飞瀑如练，从岩上垂挂下来
，溅起千堆细沫，诗云：虹雨千层吹不断，琉璃万盅涌还多。瀑边两大巨
石夹峙，岩壁小松攀生，仰望天空细如一线，即为「一线天」之所在。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"qianshou",
		"southeast" : __DIR__"liandan",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
