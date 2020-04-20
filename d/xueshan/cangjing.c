// cangjingge.c 藏经阁
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","藏经阁");
	set("long",@LONG
这里是雪山寺的藏经之处。书架上林林总总都是梵文典籍。你一个字
也看不懂。
LONG
);
	set("exits",([
		"northwest" : __DIR__"dating",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/lingzhi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

