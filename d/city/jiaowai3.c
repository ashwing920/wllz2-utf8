// jiaowai3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤随远。林中
蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。地上落了很多树枝石块。
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai2",
		"south" : __DIR__"jiaowai4",
	]));
	set("objects", ([
		"/clone/misc/shitou": 2,
	]));

	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}