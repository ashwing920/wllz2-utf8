// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石峡子");
	set("long", @LONG
石峡子是以前的黄河故道，现在遍地是大大小小的鹅卵石，两边是数
丈高的高坡，千沟万壑，向你诉说着世事的沧桑。要是运气好的话你可以
在这里拣到非常漂亮、非常珍贵的雨花石。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"tumenzi",
		"northeast" : __DIR__"bingcao",
	]));
	set("objects", ([
		"/d/hangzhou/obj/eluanshi" :1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

