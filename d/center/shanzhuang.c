// shanzhuang.c - 英雄山庄

inherit ROOM;

void create()
{
	set("short", "桃源山庄");
	set("long", @LONG
这里是桃源城里最为壮丽的桃源山庄。这是众多侠客们远离凡尘的另
一个世界，景色优美，林木葱绿，碧水环绕，鸟语花香，宛如仙境一般。
来到这里，你就忘却了一切江湖恩怨，许多大侠就常常隐居在这里，享受
田园之乐。
LONG
);
	set("outdoors", "center");
	set("exits", ([
		"north" : __DIR__"roade2",
		"west": "/d/room/tuoersuo",
		"south" :"/d/room/road",
		"east": "/d/room/xiaoyuan",
	]));
	setup();
	replace_program(ROOM);
}
