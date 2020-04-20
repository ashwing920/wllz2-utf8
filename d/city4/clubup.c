
inherit ROOM;

void create ()
{
	set("short", "长安二楼");
	set("long", @LONG 
乐坊楼上显得格外热闹，走廊里人来人往，几间屋子里人声嘈杂，牌
签骨骰钱币落盘的声音不绝。看样子，客人们赌得正欢呢。
LONG
); 
	set("exits", ([
		"up": __DIR__"clubpoem",
		"west": __DIR__"duchang1",
		"east": __DIR__"duchang2",
		"north": __DIR__"duchang3",
		"south": __DIR__"duchang4",
		"down": __DIR__"club",
	]));

	set("objects", ([
		 __DIR__"obj/tables" : 3,
	]));

	setup();
	replace_program(ROOM);
}

