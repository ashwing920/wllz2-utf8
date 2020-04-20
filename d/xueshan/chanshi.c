// chanshi.c 禅室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","禅室");
	set("long",@LONG
这里是僧人门参禅打坐的地方。侧壁一列禅床让人看了就想到该想的
事。
LONG
);
	set("sleep_room",1);
	set("exits",([
		"southwest" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}
