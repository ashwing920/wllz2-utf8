// zahuopu.c - 杂货铺

inherit ROOM;

void create()
{
	set("short","桃源百货");
	set("long", @LONG
这里是桃源城里唯一的一间杂货铺，大箱小箱堆满了一地，都是一些
日常用品。掌柜懒洋洋地躺在一张躺椅上，招呼着过往行人。据说私底下
他也卖一些贵重的东西。门边挂着一块招牌(sign)。
LONG
);
	set("exits", ([
		"south"	: __DIR__"roade4",
	]) );

	set("item_desc",([
		"sign":@TEXT
$WHT$

货真价实，童叟无欺！

应有尽有，桃源百货。

$NOR$
TEXT
	]));
		
	set("objects", ([
		__DIR__"npc/seller-zhp" : 1,
		__DIR__"npc/rat":2,
	]));

	setup();

	replace_program(ROOM);
}

