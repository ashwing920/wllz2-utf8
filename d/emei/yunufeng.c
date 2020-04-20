//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: yunufeng.c 玉女峰

inherit ROOM;

void create()
{
	set("short","玉女峰");
	set("long",@LONG
这是归云阁边的玉女峰，峰顶有一个四尺见方的小池，深亦四尺，四
季不枯，传为天女沐浴之器。古时州刺史冯楫，曾在此结茅而居，发奋诵
读《华严经》，不食人间烟火，于是玉女下凡，为他馈赠食物。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/fang" : 1,
	]));
	set("exits",([ 
		"northdown"  : __DIR__"guiyunge",
	]));

	set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}
