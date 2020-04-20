// cien.c 赐恩岩
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "赐恩岩");
	set("long", @LONG
这里巨石绵绵，相连成片。寺宇成排，有佛殿、功德堂、许氏宗祠等
。巨石群中有两块大岩石昂然伸出，使底下形成一个天然石室，上刻「高
山仰止」。据称是唐中叶泉州的进士与韩愈、陆贽等同登「龙虎榜」的欧
阳詹的读书的书室。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu4",
		"southdown" : __DIR__"shanlu5",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
