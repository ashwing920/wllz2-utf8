// Room: /d/shaolin/shijie9.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
眼前遽然出现一大片松林。松林长得极密，石阶上铺满了厚厚的朽黄
的松针。踩在脚下，发出察察的响声。一只小松鼠吱地在眼前闪过，消失
在林海里。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"shijie8",
		"northup" : __DIR__"shijie10",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

