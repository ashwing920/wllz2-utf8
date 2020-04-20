// roadw4.c
// Design By Robert 蝴蝶君 Robert_st@263.net 

inherit ROOM;

void create()
{
	set("short","大官道");
	set("long",@LONG
你走在尘土飞扬的大官道上，许多来往于扬州和桃源城的游客商人都
由此地经过，留下了不知多少脚印和车痕。官道两边松树林立，远远望去
，十分壮观。远处有一座凉亭，站在这里，隐约可以看见凉亭上方挂着一
块牌匾，上面写着：十里亭。
LONG
);
	set("exits",([
		"west": __DIR__"roadw",
		"east": __DIR__"roadw2",
	]));
	set("outdoors","shaolin");
	setup();
}
