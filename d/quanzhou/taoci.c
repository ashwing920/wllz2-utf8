// taoci.c 陶瓷铺

inherit ROOM;

void create()
{
	set("short", "陶瓷铺");
	set("long", @LONG
这里烧制各式各样的陶瓷制品。柜台上摆着花色各异的碗碟瓶罐，白
皙透明，巧夺天工。动物瓷器，细腻圆润，栩栩如生。由于它的特殊地位
，因此生意和技术从来都是传子不传女。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"xmqiao",
	]));
	setup();
	replace_program(ROOM);
}
