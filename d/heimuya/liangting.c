// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "凉亭");
	set("long", @LONG
行到近处，只见一座小小凉亭，那是旷野中供行旅休息之用，构筑颇
为简陋。
LONG
);
	set("exits",([
		"west" : __DIR__"shidao2",
	]));
	set("objects",([
		CLASS_D("riyue")+"/xiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
