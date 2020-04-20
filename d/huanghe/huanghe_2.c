// Room: /huanghe/huanghe_2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河");
	set("long", @LONG
黄河出了青海，经甘肃之后，向东受到黄土高原的阻挡，转而向东北
流去。在流经黄土高原的过程中泥沙含量猛增，水色澄黄，就被称为黄河。
LONG
);
	set("exits", ([
		"west"	  : __DIR__"huanghe_3",
		"northeast" : __DIR__"huangtu",
	]));

	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

