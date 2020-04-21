// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
这是一条小径，弯弯曲曲向远方延伸。小径两边种植了一些桃花树。
你只一瞥就发现：这些桃花全是白色的。
LONG
);
	set("exits", ([
		"west"  : __DIR__"road1",
		"north" : __DIR__"road3",
		"south" : __DIR__"road4",
	]));
	set("outdoors", "taohua");
	setup();
	replace_program(ROOM);
}