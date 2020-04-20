// tygate2.c 桃园木门
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃园木门");
	set("long", @LONG
你走在一条通往桃树林深处的小道上，前面有个桃木门(door)。
LONG
);
	set("outdoors", "wudang");
	set("item_desc",([
		"door"	:@TEXT
	桃木门上有首诗：
	
	∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　去　年　狂　日　此　门　中　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　人　面　桃　花　相　映　红　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　人　面　不　知　何　处　去　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷　桃　花　依　旧　笑　春　风　∷∷∷
	∷∷∷　　　　　　　　　　　　　　　∷∷∷
	∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷
	
TEXT							
	]));
	set("exits", ([
		"north" : __DIR__"tyroad10",
	]));
	setup();
	replace_program(ROOM);
}
