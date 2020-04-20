// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
你走进了一间卧房。一股若有若无的甜香扑鼻而来。琴剑书画，挂在
墙上。锦笼纱罩，金彩珠光。小靖上汝窑美人瓶内的桃花正自盛开。右首
一张床，床头放着五彩鸾纹被。
LONG
);
	set("exits", ([
		"east" :__DIR__"dating",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/rong" : 1,
		__DIR__"npc/binu" : 2,
	]) );
	setup();
	replace_program(ROOM);
}
