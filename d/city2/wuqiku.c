//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是武器库，架上摆满了各种武器，任由武士门挑选。
LONG );
	set("exits", ([
		"east" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : random(3),
		"/clone/weapon/zhubang" : random(3),
		"/d/shaolin/obj/changbian" : random(3),
		"/clone/weapon/duanjian" : random(3),
		"/clone/weapon/gangdao" : random(3),
		"/d/city2/obj/fuchen" : random(3),
	]));

	setup();
	replace_program(ROOM);
}
