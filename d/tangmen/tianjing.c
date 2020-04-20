
inherit ROOM;

void create()
{
	set("short","天井");
	set("long",@LONG
这里是天井，一大片开阔的空旷地，有几个练功用的竹人。往北走是
留剑堂，往南是心意堂。
LONG
);
	set("outdoors", "tangmen");
	set("exits",([
		   "north" : __DIR__"liujiantang",
		   "south" : __DIR__"xinyitang",
	]));
	set("objects", ([
		__DIR__"npc/zhuren" : 4,
	]) );
	setup();
	replace_program(ROOM);
}




