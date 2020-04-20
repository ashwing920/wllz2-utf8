//RJQMENLOU1.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "门楼一层");
	set("long", @LONG
这里是一间大石室，石室四周整齐的码置着兵器架，十八般兵器样样
俱全。几个教众在室中巡逻，好象是守护兵器的。右面有一条石梯直通楼
上。
LONG
);
	set("exits", ([
		"up" : __DIR__"rjqmenlou2",
		"east" : __DIR__"rjqyuan",
	]));
	setup();
	replace_program(ROOM);
}
