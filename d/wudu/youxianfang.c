
inherit ROOM;

void create()
{
	set("short","右厢房");
	set("long", @LONG
这是一间厢房，一面墙上立着一个兵器架，上面挂满了许多上好的兵
器。一些普通的兵器散乱的放在墙角，供弟子们取用。
LONG
);
	set("exits", ([
		"west" : __DIR__"jinshetang",
	]));
	set("objects" , ([
		__DIR__"obj/tengjia" : 1,
		__DIR__"obj/changbian" : 1,
		__DIR__"obj/gangjian" : 1,
	]));
	setup();
	replace_program(ROOM);
}



	