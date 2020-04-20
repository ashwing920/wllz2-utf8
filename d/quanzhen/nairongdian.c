// nairongdian.c 乃容殿
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "乃容殿");
	set("long", @LONG
这里是大堂旁边的一个侧殿，也是接待重要客人的地方。殿不大，只
摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆景，墙壁上挂
着一些字画。
LONG
	);
	set("exits", ([
		"south" : __DIR__"qingjing",
		"west" : __DIR__"piandian",
		"north" : __DIR__"datang3",
	]));
	set("objects", ([
		CLASS_D("quanzhen")+"/cheng" : 1,
	]));
	setup();
	replace_program(ROOM);
}
