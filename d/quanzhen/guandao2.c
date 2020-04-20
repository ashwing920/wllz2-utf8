// guandao2.c 官道
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条官府修建的大道，西面隐约可以看见武功镇的东门。远处好
象可以看见巍峨的城墙。往东是通往中原的路。走在这里，你似乎有了一
种‘劝君更进一杯酒，西出阳关无故人’的感觉。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"east" : __DIR__"guandao1",
		"west" : __DIR__"dongmen",
	]));
	setup();
	replace_program(ROOM);
}
