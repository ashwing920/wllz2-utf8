// yuzhengong.c 遇真宫
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "遇真宫");
	set("long", @LONG
这里是重阳宫以前的旧址，是王重阳王真人参悟大道之前清修的地方
。后来手创全真教后，此地的布局实在太小，就将重阳宫迁到东面山上，
将此地重新改名为遇真宫，以纪念得道之意。这里很久没有人来过了，桌
椅上都积满了灰尘。
LONG
);
	set("exits", ([
		"south" : __DIR__"fangzhenqiao",
	]));
	setup();
	replace_program(ROOM);
}
