// zoulang2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，走廊两边是四位庄主中的其他三位平时休息和
练功的地方，这里的左边是棋室，右边则是梅庄弟子感觉劳顿的时候休息
的地方，二庄主黑白子不分昼夜都在棋室里研究他那些不知道哪儿找来的
古棋谱。 
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"qishi",
		"east" : __DIR__"xiuxishi",
		"north" : __DIR__"zoulang3",
		"south" : __DIR__"zoulang1",
	]));
	setup();
	replace_program(ROOM);
}

