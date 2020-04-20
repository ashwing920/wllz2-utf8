// Room: /d/suzhou/tingyu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "听雨轩");
	set("long", @LONG
听雨轩是苏州城内的一处唯一的一家书店了。这里有着各种各样的书
籍，什么小说啦、风光旅游啦、手艺制作啦、基本武功啦，等等等等。只
须花几两银子就可买到你想要的书。
LONG
);
	set("exits", ([
		"west"  : __DIR__"nandajie2",
	]));
	setup();
	replace_program(ROOM);
}

