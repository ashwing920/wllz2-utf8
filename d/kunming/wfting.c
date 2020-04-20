// /d/kunming/shilin

inherit ROOM;

void create()
{
	set("short","望峰亭");
	set("long", @LONG
这里是石林最高的一座峰，峰上有一小亭，真不知道是如何建造出来
的，放眼看去，只见四面石峰(feng)林立,一时间眼睛都看花了。
LONG
);
	set("outdoors", "kunming");
	setup();
	replace_program(ROOM);
}
