//huadian.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short","飘香花店");
	set("long",@LONG
未入此处，清新的花香已沁人心裨。店中各种名花，玲琅满目，不乏
珍奇异种。来客不分高低贵贱，这里的主人总是笑脸相迎。许多城中的年
青人都喜欢在这儿逗留，盼有一天桃花运会降临在他身上。据这里的老板
说，在飘香花店结成的良缘已不可胜数。
LONG
);
	set("exits",([
		"east": __DIR__"roads3",
	]));
	set("objects",([
		__DIR__"npc/seller-hd": 1,
	]));
 	setup();
	replace_program(ROOM);
} 	