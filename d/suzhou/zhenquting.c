// Room: /d/suzhou/zhenquting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "真趣亭");
	set("long", @LONG
亭内高高悬挂御笔题写的“真趣”匾一块。亭内装饰精致金碧辉煌。
梁架、围屏、裙板上雕刻的人物、花鸟图案惟妙惟肖。在此可以环览全园
景色。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"east"	  : __DIR__"wenmeige",
		"northwest" : __DIR__"yanyutang",
	]));
	setup();
	replace_program(ROOM);
}

