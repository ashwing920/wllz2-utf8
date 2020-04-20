// Room: /d/xiangyang/anfugate.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "安抚使衙门");
	set("long", @LONG
这是安抚使衙门的大门，铜皮包门似乎极为沉重，上面有两个明晃晃
的铜环；大门紧闭，里面却传出一阵阵嬉笑声，和门口的肃杀很不协调。
想来这个安抚使大人的日子还是过得蛮滋润的。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"anfupailou",
	]));
	setup();
	replace_program(ROOM);
}
