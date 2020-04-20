// hupaoquan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "虎跑泉");
	set("long", @LONG
只见泉水从沙岩中渗流而出，清澈见底。相传有位名叫性空的和尚深
爱此山风景灵秀，便住了下来。後因水源奇缺，准备迁走。一夜，梦神告
诉他说“南岳衡山童子泉，当遣二虎移来。”第二天，果然看见两只老虎
跑地作穴，涌出泉水，所以定名为“虎跑泉”。
LONG
);
	set("exits", ([
		"east"	: __DIR__"road17",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
