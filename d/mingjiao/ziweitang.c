//ziweitang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "紫微堂");
	set("long", @LONG
这里就是明教的紫微堂，堂上的大匾上紫微贯日四字并不因堂主殷素
素早逝而有丝毫减色。堂中陈设一如往昔。
LONG
);
	set("exits", ([
		"east"	  : __DIR__"tianweitang",
	]));
	set("objects",([
		 __DIR__"npc/yinwushou":1,
	]));
	setup();
	replace_program(ROOM);
}
