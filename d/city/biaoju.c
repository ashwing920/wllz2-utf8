// biaoju.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "福威镖局");
	set("long", @LONG
你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗
杆，杆上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的狮子，狮子上头
有一只蝙蝠飞翔。左首旗子上写着“福威镖局”四个黑字，银钩铁划，刚
劲非凡。入口处排着两条长凳，几名镖头坐着把守。少镖头正跟他们说笑。
LONG );

	set("exits", ([
		"south" : __DIR__"zhengting",
		"north" : __DIR__"xidajie2",
	]));
	set("objects", ([
		__DIR__"npc/linpingzhi" : 1,
		__DIR__"npc/biaotou" : 2,
	]));

	setup();
	replace_program(ROOM);
}
