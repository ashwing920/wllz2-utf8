// tongtiandian.c 通天殿
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "通天殿");
	set("long", @LONG
这里是供奉三清之末--通天教主的大殿，殿内的香烟不甚旺盛。在通
天教主的金身旁边，塑着几位截教道友象长耳仙、归云仙、申公豹的塑像。
LONG
);
	set("exits", ([
		"north" : __DIR__"laojundian",
	]));
	setup();
	replace_program(ROOM);
}
