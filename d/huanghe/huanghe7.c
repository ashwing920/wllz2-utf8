// Room: /huanghe/huanghe7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在静静地
向东流去，使人忘记它发洪水时的狂威。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"huanghe8",
		"southwest" : __DIR__"huanghe6",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

