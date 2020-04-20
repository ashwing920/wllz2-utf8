//westroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条直通西方的山路，向西远望，群山巍峨，云雾飘渺，再往前
不远，就要进入深山之中了。东面就是去中原的路。
LONG
);
	set("exits",([
		  "west" : __DIR__"westroad2",
		  "east" : "/d/xingxiu/silk2",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
	
