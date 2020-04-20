// yuhuangsd.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "玉皇山顶");
	set("long", @LONG
登上玉皇山，俯瞰山下，可以看到“八卦田”。据说这是皇帝祭先农
时亲耕的籍田。山顶有福星观，建於唐朝。廊宇旁有天一池和白石井，并
建有望湖亭。东西两边各有一条下山的路。
LONG
);
	set("exits", ([
		"eastdown"  : __DIR__"shanlu7",
		"westdown"  : __DIR__"shanlu6",
	]));
	set("objects", ([
		__DIR__"honghua/yu" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
