// /d/beijing2/xingbu/ws-1.c

inherit ROOM;

void create()
{
	set("short", "高英明的卧室");
	set("long", @LONG
这里陈设简单，家具显得比较朴实。这里最明显的摆设，只有一个书
架(shelf)和一张书桌(desk) 
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("item_desc", ([
		"desk": @TEXT
书桌上只有几本书，一个砚台，一支笔和一个镇纸。镇纸下面压着一本
《唐诗三百首》，估计高尚书正在研究唐诗。
TEXT,
		"shelf":@TEXT
书架上的书都是法律方面的著作，古今中外的都有。什么《大清律例》，
《不列颠刑律》呀，应有尽有。
TEXT
	]) );
	setup();
	replace_program(ROOM);
}

