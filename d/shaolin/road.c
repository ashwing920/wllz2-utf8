// road.c
// Design By Robert 蝴蝶君 Robert_st@263.net 

inherit ROOM;

void create()
{
	set("short","大官道");
	set("long",@LONG
你走在尘土飞扬的大官道上，许多来往于扬州和桃源城的游客商人都
由此地经过，留下了不知多少脚印和车痕。官道两边松树林立，远远望去
，十分壮观。再往西边走就是桃源城了，站在这里，可以看见桃源城的城
门。
LONG
);
	set("exits",([
		"west": "/d/center/gatee",
		"east": __DIR__"roadw",
	]));
	set("outdoors","shaolin");
	setup();
}
