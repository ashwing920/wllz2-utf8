// inn_2f7.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "桃源客栈客房");
        set("long", @LONG
这里是客栈的客房，门牌上写着“单七”的字样。客房里面显得很宽
敞，靠近窗边是一张桌子，桌面上有两支红烛。另一边是一张单人床，床
上罗帐低垂，使人忍不住想躺下去(sleep)。
LONG
	);
	set("exits", ([
		"out" : __DIR__"inn_2f" 
	]) );
	set("sleep_room",1);
	set("hotel",1);
	setup();
	replace_program(ROOM);
}
