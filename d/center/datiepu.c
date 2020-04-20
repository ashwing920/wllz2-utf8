// datiepu.c - 打铁铺

inherit ROOM;

void create()
{
	set("short", "打铁铺");
	set("long", @LONG
这是一间打铁铺。只见铺子中心摆着一个火炉，炉火把四周照得一片
通红，你一走进去就觉得浑身火热。屋子的角落里堆满了各式铁器的完成
品或者未成品，像是铁锤、锄头、铲子、长剑、单刀等物，一位铁匠满头
大汗挥舞着铁锤，专心致志地在打铁。叮叮当当的声音敲得满屋子响。
LONG
);

	set("exits", ([
		"north"	: __DIR__"roade4",
	]) );			

	set("objects", ([
		__DIR__"npc/smith": 1,
	]) );

	setup();

	replace_program(ROOM);
}
