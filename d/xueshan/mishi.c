// mishi.c 密室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","密室");
	set("long",@LONG
这是一条小房间。什么东西都没有。
LONG
);
	set("exits",([
		"south" : __DIR__"midao",
		"down" : "/d/city/guangchang" ,
	]));
	setup();
	replace_program(ROOM);
}
