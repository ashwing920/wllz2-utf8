// Room: /d/xiangyang/zhonglie.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short", "忠烈祠");
	set("long", @LONG
这里是襄阳城的忠烈祠，十余年来为保卫襄阳而牺牲的烈士遗骨都安
葬在这里，每个有爱国心的好汉到这都会来祭奠一下忠魂。
LONG
);
	set("exits", ([
		"west" : __DIR__"eastroad2",
	]));
	setup();
	replace_program(ROOM);
}
