
inherit ROOM;

void create()
{
	set("short","小径");
	set("long",@LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花
木点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，往西面去是
这条小径的延伸。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"east" : __DIR__"xiaoshe",
		"west" : __DIR__"xiaojing2",
	]));
	setup();
	replace_program(ROOM);
}
