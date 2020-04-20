// /d/kunming/xiaoximen

inherit ROOM;

void create()
{
	set("short",  "小西门" );
	set("long", @LONG
这里是昆明的西城门，俗称小西门，来来往往各色人出出进进，有游
客，有做买卖的，也不乏些江湖人士。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"west" : "/d/dali/xiaolu", 
		"east"  :__DIR__"jinmafang",
	]));
	setup();
	replace_program(ROOM);
}
