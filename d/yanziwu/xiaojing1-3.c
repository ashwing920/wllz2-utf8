
inherit ROOM;
void create()
{
	 set("short","小径");
	 set("long",@LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，东面是小径的延
伸。
LONG);
	 set("outdoors","yanziwu");
	 set("exits",([
	     "west" : __DIR__"c15-4",
	     "east" : __DIR__"xiaojing1-4",
	]));
	setup();
	replace_program(ROOM);
}
