// Room: /d/xiangyang/eastroad2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东内大街");
	set("long", @LONG
这是一条青石铺就的大街。西面是一堵盖着红色琉璃瓦的高墙，里面
是襄阳守城大将王坚的府邸大院。东面是忠烈祠，因为十余年来，为保卫
襄阳、抵抗蒙古军的侵略而牺牲的人特别多，前往上香祭奠的人络绎不绝
。北面是一个十字街道，只见人来人往，非常热闹，南面是用青石铺的街
道。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"zhonglie",
		"south" : __DIR__"eastroad1",
		"north" : __DIR__"jiekou2",
	]));
	setup();
	replace_program(ROOM);
}

