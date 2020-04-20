//Roon: lianpath1.c 莲花峰小路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","莲花峰小路");
	set("long",@LONG
小路通往莲花峰，周围静静悄悄，微闻蝉鸣。四望密林幽谷，让人胆
寒。
LONG
);
	set("outdoors", "xx");
	set("exits",([ /* sizeof() == 1 */
		"westup"   : __DIR__"lianpath2",
		"northeast": __DIR__"zhenyue",
	]));
	setup();
	replace_program(ROOM);
}

