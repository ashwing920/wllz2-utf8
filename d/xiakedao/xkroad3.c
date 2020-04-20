// Room: /d/xiakedao/xkroad3.c
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "平原小路");
	set("long", @LONG
你走在珠江三角洲的平原小路上。此处向称鱼米之乡，有花果之都美
誉，物产丰饶，民风淳朴。
LONG );
	set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : "/d/foshan/southgate",
		"south"   : __DIR__"xkroad4",
	]));
	setup();
	replace_program(ROOM);
}

