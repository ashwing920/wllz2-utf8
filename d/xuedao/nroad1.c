// nroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
山路越走越窄，能隐隐望见前方又分出了几条叉路。
LONG
);
	set("exits",([
		"westup": __DIR__"nroad2",
		"southup": __DIR__"sroad3",
		"northdown"  : __DIR__"nroad5",
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}

