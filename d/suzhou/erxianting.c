// Room: /d/suzhou/erxianting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "二仙亭");
	set("long", @LONG
二仙亭在千人石东侧，建于北宋。亭壁嵌两方石碑，分别刻着五代宋
初陈抟与唐代吕洞宾二仙像。亭柱上有两幅石刻楹联：“梦中说梦原非梦
，元里求元便是元”；“昔日岳阳曾显迹，今朝虎阜再留踪”。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"qianrenshi",
		"north" : __DIR__"bailianchi",
	]));
	setup();
	replace_program(ROOM);
}

