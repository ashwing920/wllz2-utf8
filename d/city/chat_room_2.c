// chat_room_2.c - 二号雅间
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit CHAT_ROOM;

void create()
{
	set("short", "名士阁");
	set("long", @LONG
这是「凝香楼」的雅间「名士阁」，这里安静的连跟针掉在地上都可
以听见，是个交友结盟的好地方。
LONG
);
	set("exits", ([
		"out"	: __DIR__"chalou2",
	]) );		   

	::create();

	replace_program(ROOM);
}


