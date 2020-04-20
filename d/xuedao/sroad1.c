// sroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
川西多是崇山峻岭，交通不便。一条山路蜿蜒在山间，连接着藏边和
中原。
LONG
);
	set("exits",([
		"north"  : "/d/city3/nanheqiaos",
		"westup" : __DIR__"sroad2",
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}

