
inherit ROOM;

void create()
{
	set("short","小径");
	set("long",@LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花
木点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，往北面看去
是一片柳树林，东面是一座小水池，南面是一条长廊。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"east" : __DIR__"shuichi",
		"north" : __DIR__"liulin2",
		"west" : __DIR__"xiaojing6",
		"south" : __DIR__"c14",
	]));
	setup();
	replace_program(ROOM);
}
