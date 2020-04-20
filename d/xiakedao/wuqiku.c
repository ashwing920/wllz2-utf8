// wuqiku.c

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是侠客岛的武器库，架上摆满了各种武器，任由来岛的武士们挑
选。
LONG );
	set("exits", ([
		"east" : __DIR__"dating",
	]));
	set("objects", ([
		"/clone/weapon/bamboo_sword" : 2,
		"/d/shaolin/obj/changbian" : 1,
		"/clone/weapon/duanjian" : 1,
		"/clone/weapon/gangdao" : 1,
		"/d/city2/obj/fuchen" : 1
	]));
	setup();
	replace_program(ROOM);
}
