// roadw4.c
// Design By Robert 蝴蝶君 Robert_st@263.net 

inherit ROOM;

void create()
{
	set("short","大官道");
	set("long",@LONG
你走在汉水岸边的大官道上，官道上尘土飞扬，许多来往于扬州和桃
源城的游客商人都由此地经过，留下了不知多少脚印和车痕。官道两边松
树林立，远远望去，十分壮观。
LONG
);
	set("exits",([
		"west": __DIR__"roadw2",
		"east": __DIR__"roadw4",
	]));
	set("outdoors","shaolin");
	set("objects",([
		"/d/taishan/npc/jian-ke": 2,
	]));

	setup();
}
