// feilaifeng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "飞来峰");
	set("long", @LONG
飞来峰又名灵鹫峰。延着盘山小道往上走，只见溪盘岩石壁间雕着一
尊袒腹露胸，喜笑自若的弭勒佛。旁边是一座气魄胸伟的多闻天王。北边
是下山的路。小路往上延伸向东西两边。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"road1",
		"eastup"	: __DIR__"qinglindong",
		"westup"	: __DIR__"longhongdong",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
