// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: nanheqiaos.c

inherit ROOM;

void create()
{
	set("short","南河桥");
	set("long",@LONG
这里是成都南门外南河桥。府河和南河夹城流过，成为天然的护城河
，滋润着这个天府之国的川中首府。向北就进城了，向南又是一条小路。
LONG
);
	set("outdoors","chengdu");
	set("exits",([
		"south"  : "/d/xuedao/sroad1",
		"north"  : __DIR__"southgate",
	]));
	
	setup();
	replace_program(ROOM);
}

