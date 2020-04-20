// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: fuheqiaoe.c

inherit ROOM;

void create()
{
	set("short","府河桥");
	set("long",@LONG
这里是成都东门外府河桥。成都自古就是川中首府，府河和南河夹城
而过，成为天然的护城河。由于四川外有峡江，秦岭之险，内仗绵渝坚城
之固，成都却因之自来无坐守成功之绩。往往兵到城下，降旗高扯了。
LONG
);
	set("outdoors", "chengdu");
	set("exits",([
		"east"  : __DIR__"road2",
		"west"  : __DIR__"eastgate",
	]));
	
	setup();
	replace_program(ROOM);
}

