// Room: /d/xingxiu/xxroad4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
山势在这里渐渐变得平缓，你已经可以听见西边山涧底的水声。东面
有一个山洞。
LONG
);
	set("exits", ([
		"south" : __DIR__"xxroad4",
		"enter" : __DIR__"cangku",
		"north" : __DIR__"xxroad6",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/chuchen" : 1,
	]) );
	set("outdoors", "xingxiuhai");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	if((myfam = me->query("family"))
	&&  myfam["family_name"] != "星宿派"
	&& dir != "south"
	&& present("chuchen zi", environment(me)))
		return notify_fail("出尘子一言不发，闪身拦在你面前。\n");

	return ::valid_leave(me, dir);
}
