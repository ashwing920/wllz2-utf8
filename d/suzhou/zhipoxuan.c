// Room: /d/suzhou/zhipoxuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "揖峰指柏轩");
	set("long", @LONG
这里曾是为园主接待宾客和亲友的地方，有时也作为演戏说书或写诗
做画之处。轩名取朱熹“前揖庐山，一峰独绣”和高启的“笑指庭前柏”
句诗意。轩内摆设古香古色。凭轩眺望，满目石峰嶙峋，古柏虬枝盘绕，
旧有桃源“十八景”之称。
LONG 
);
	set("outdoors", "suzhou");
	set("exits", ([
		"southwest"  : __DIR__"shizilin",
	]));
	setup();
	replace_program(ROOM);
}

