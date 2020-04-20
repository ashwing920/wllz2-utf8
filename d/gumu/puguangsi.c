// puguangsi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "普光寺");
	set("long", @LONG
这是一个位於终南山下的小寺庙，庙门横额写着$HIW$普光寺$NOR$三个大字。由
於此庙是上终南山的必经之路，大多数的游客都会在此落脚休息，也因此
此处香火也颇为鼎盛。庙前的几株松树下，立着一块石碑(shibei)，几乎
快被周围的长草给遮掩了。往西走是一条小路.
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"west" : __DIR__"shanlu13",
	]));

	setup();
	replace_program(ROOM);
}
