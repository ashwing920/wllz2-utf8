// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "三无宫");
	set("long",@LONG
这里可以买香到后面参拜西方大士。几个进香客正围着一个老年僧
人讨价还价。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"doushuai",
		"north" : __DIR__"cibeiyuan",
	]));
	set("objects",([
		"/d/wudang/npc/guest" : 4,
		CLASS_D("tianlong")+"/laoniansengren" : 1,
	]));
	setup();
	replace_program(ROOM);
}
