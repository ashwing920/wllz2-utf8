//Room: /d/dali/hudiequan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","蝴蝶泉");
	set("long",@LONG
蝴蝶泉就显得更加清凉湿润，大量的蝴蝶，从四面八方，汇集在树荫
下，花丛中，翩翩起舞，成千上万只彩蝶，欢聚一处，使这里变得花团锦
簇。特别是在蝴蝶泉上，顺着那倒垂的扬柳，无数蝴蝶，一只咬着一只的
尾部，形成千百个蝶串，人来不惊，投石不散，构成令人惊叹的奇观。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"yuxuguanqian",
		"east"   : __DIR__"xiaodao1",
	]));
	setup();
	replace_program(ROOM);
}

