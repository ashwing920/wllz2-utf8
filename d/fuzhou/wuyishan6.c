// Room: /d/fuzhou/wuyishan6.c

inherit ROOM;

void create()
{
	set("short", "大王峰");
	set("long", @LONG
大王峰又称纱帽峰，山形如宦者纱帽，独具王仪而得名。四周悬崖壁
立，上丰下敛，气势雄浑。远远望去，宛若擎天巨柱，与玉女遥遥相望。
石壁上刻有“居高思危”四字。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"wuyishan2",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

