
inherit ROOM;

void create()
{
	set("short","樱桃园");
	set("long",@LONG
这是一片樱桃园，树上开满了樱桃花。
LONG);
	set("exits",([
		"west" : __DIR__"ytyuan2",
		"north" : __DIR__"midao",
		"south" : __DIR__"huandong",
	]));
	setup();
	replace_program(ROOM);
}
