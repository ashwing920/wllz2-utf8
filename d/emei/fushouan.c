//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: fushouan.c 福寿庵

inherit ROOM;

void create()
{
	set("short","福寿庵");
	set("long",@LONG
福寿庵在神水庵南，是一个名叫天性的僧人建造的。庵前有九曲渠、
流杯池，古人曾据在此饮酒流杯，观景赋诗，歌咏兴叹，不知夕日。庵旁
有株大海棠树，数百苍龄，高达十余丈。
LONG
);
	set("outdoors", "emei");
	set("objects", ([
		CLASS_D("emei") + "/zhen" : 1,
		__DIR__"npc/girldizi" : 1,
	]));
	set("exits",([
		"enter"	 : __DIR__"lingwenge",
		"north"	 : __DIR__"shenshuian",
	]));

	setup();
	replace_program(ROOM);
}
