//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcaguangchang.c 华藏庵广场

inherit ROOM;

void create()
{
	set("short","华藏庵广场");
	set("long",@LONG
这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往
大雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟
飘绕。广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/xu" : 1,
	]));
	set("outdoors", "emei");
	set("exits",([ 
		"north"   : __DIR__"hcazhengdian", 
		"southup" : __DIR__"hcadadian", 
		"west"	: __DIR__"hcawest1", 
		"east"	: __DIR__"hcaeast1", 
	]));
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
	"/clone/board/emei_b"->foo();
}
