// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "桃花山庄正厅");
	set("long", @LONG
这里是桃花山庄的正厅。整个大厅十分宽阔。厅中挂满了各种名家的
书法真迹。但最显眼的则是正中挂的一幅对联：
   
$HIB$	桃花影落飞神剑		碧海潮生按玉箫$NOR$

字体遒劲挺拔，气势宏伟。
LONG
);
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"houyuan",
		"east"  : __DIR__"daojufang",
		"west"  : __DIR__"wofang" ,
	]));
	set("objects", ([
		CLASS_D("taohua") +"/huang" : 1,
	]) );	
	set("valid_startroom", 1);
	set("no_beg",1);
	setup();
	"/clone/board/taohua_b"->foo();	
	replace_program(ROOM);
}
