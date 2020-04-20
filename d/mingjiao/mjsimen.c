// Room: /d/mingjiao/mjsimen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石道");
	set("long", @LONG
穿过一片小松林，面前出现了一条宽广的石板道，笔直通向前方。沿
道稀稀落落地种着几棵柏树，却显得高大挺拔，蝤龙般的枝干向天空高高
伸展着。
LONG
);
	set("exits", ([
		"north" : __DIR__"tomen2",
		"south" : __DIR__"mjsimen1",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

