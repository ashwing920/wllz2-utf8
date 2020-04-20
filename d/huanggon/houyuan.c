// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "清和殿后院");
	set("long", @LONG
这里是清和殿后院。院里种着些青菜。墙角有一口水井(well)。站在
水井边往下看，只觉深不见底，井壁上满是滑溜溜的青苔。一个轱辘吊着
一根长绳，绳端系着一个木桶。东边是一条走廊，通往清和殿。
LONG
);
	set("outdoors", "huanggon");
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"zoulang1",
	]));
	setup();
	replace_program(ROOM);
}

