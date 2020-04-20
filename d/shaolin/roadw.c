// roadw4.c
// Design By Robert 蝴蝶君 Robert_st@263.net 

inherit ROOM;

void create()
{
	set("short","十里亭");
	set("long",@LONG
这是大官道边上的一所凉亭，上面挂着一块牌匾，写着“十里亭”三
个大字。凉亭上方铺设着一层红色的琉璃瓦，在阳光照耀下，显得十分鲜
艳。凉亭中有一张大石桌，石桌两边各有一张石凳，是提供给过路的路人
休息用的。
LONG
);
	set("exits",([
		"west": __DIR__"road",
		"east": __DIR__"roadw1",
	]));
	set("outdoors","shaolin");
	setup();
}
