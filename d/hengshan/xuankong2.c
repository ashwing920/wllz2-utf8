// Room: /d/hengshan/xuankong2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "悬空寺南楼");
	set("long", @LONG
这里是悬空寺的南门楼，也是南碑亭。悬空寺于陡崖上凿石穴插悬梁
为基，楼宇间栈桥相连。全寺面东座西，南北危楼对望，断崖分断，很是
艰险。
LONG
);
	set("exits", ([
		"north"   : __DIR__"zhanqiao",
		"southup" : __DIR__"zhandao",
	]));
	setup();
	replace_program(ROOM);
}

