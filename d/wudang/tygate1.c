// tygate1.c 桃园篱笆
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃园篱笆");
	set("long", @LONG
你走在一条通往桃树林深处的小道上，前面有个篱笆门(fence)。
LONG
);
	set("outdoors", "wudang");
	set("item_desc",([
		"fence"	:@TEXT
	
	篱笆门上有首诗：
	
	∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　应　怜　屐　齿　印　苍　苔　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　小　扣　柴　扉　久　不　开　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　春　色　满　园　关　不　住　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　一　枝　红　杏　出　墙　来　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷

TEXT
	]));
	set("exits", ([
		"south" : __DIR__"tyroad10",
	]));
	setup();
	replace_program(ROOM);
}
