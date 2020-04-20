// qhpo.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "奇槐坡");
	set("long", @LONG
这里就是奇槐坡了，这里种着大大小小，千奇百怪的槐树，有的槐树
一直向天，有的又曲折盘绕，你从这里隐隐约约听到一阵阵的琴声，似有
似无，若隐若现。
LONG
);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xiaodao",
		"north"  : __DIR__"senlin1",
	]));
	setup();
	replace_program(ROOM);
}

