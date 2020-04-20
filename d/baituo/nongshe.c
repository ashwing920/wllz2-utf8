// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//nongshe.c

inherit ROOM;

void create()
{
	set("short", "农舍");
	set("long",@LONG
这里是一间小农舍，家具很新。看来主人家还算比较富裕。
LONG
);
	set("exits", ([
		"west" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
	]));
	setup();
	replace_program(ROOM);
}
