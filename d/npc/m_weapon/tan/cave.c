//cave.c

inherit ROOM;

void create()
{
	set("short", "湖心小洞");
	set("long",@LONG
这里是潭中的一个小洞，里面零零落落的有几块石头。
LONG
);
	set("objects" , ([
		 __DIR__"item/stone" : random(2)+1,
	]));
	setup();
	replace_program(ROOM);
}
