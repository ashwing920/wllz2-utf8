// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: fuheqiaon.c

inherit ROOM;

void create()
{
	set("short","府河桥");
	set("long",@LONG
这里是成都北门外府河桥。成都虽是川中首府，却无险可守，一旦敌
方兵至成都平原，即使府南两河水涨，也就只有祷告对方慈悲的选择了。
LONG
);
	set("outdoors", "chengdu");
	set("exits",([
		"north"  : "/d/qingcheng/qcroad1",
		"south"  : __DIR__"northgate",
	]));
	
	setup();
	replace_program(ROOM);
}

