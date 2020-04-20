// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "牢房入口");
	set("long", @LONG
东面一道紧闭着的铁门，门上开了个尺许见方的洞孔，从洞孔望进去
，有个狱卒模样的人在走动着。
LONG
);
	set("exits", ([
		"west" : __DIR__"houdian",
	]));

	set("objects",([
		CLASS_D("riyue")+"/da" : 1,
	]));
	setup();
	replace_program(ROOM);
}
