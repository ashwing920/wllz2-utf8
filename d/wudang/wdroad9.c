// wdroad9.c 黄土路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北
境界，据说经常有土匪出没，不可久留。向东南去可至湖南。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"northwest" : __DIR__"sanbuguan",
		"south"	 : __DIR__"wdroad10",
		"southeast" : "/d/henshan/hsroad8",
	]));
	setup();
	replace_program(ROOM);
}

