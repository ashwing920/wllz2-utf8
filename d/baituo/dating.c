//ROM dating
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long",@LONG
这是『白驼山庄』的大厅，内部摆设极尽豪华，当中一张黑色檀木条
案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名家的字画。
LONG
);
	set("valid_startroom",1);
	set("exits", ([
		"north" : __DIR__"liangong",
		"southdown" : __DIR__"yuanzi",
	]));
	set("objects",([
		CLASS_D("btshan") + "/ouyangfeng" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	setup();

	"/clone/board/baituo_b"->foo();
	replace_program(ROOM);
}
