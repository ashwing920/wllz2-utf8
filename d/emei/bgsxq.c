//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: bgsxq.c 报国寺西墙

inherit ROOM;

void create()
{
	set("short","报国寺西墙");
	set("long",@LONG
这里是峨眉山报国寺的西墙。寺院里的钟声从墙那边飘来，在空气中
回响。一条山溪从西面山上的解脱桥下流经这里，向山下淌去。
LONG
);
	set("outdoors", "emei");
	set("exits",([
		"east"	  : __DIR__"bgs",
	]));

	setup();
	replace_program(ROOM);
}
