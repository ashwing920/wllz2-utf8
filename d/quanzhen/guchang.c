// guchang.c 晒谷场
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "晒谷场");
	set("long", @LONG
这里是村庄中心的晒谷场，地方不大，不过村里也就五、六户人家，
种的谷子也够晒了。现在正是收获的季节，谷场中堆满了谷子，几个男女
童子正在场中嬉闹，不时地扬起一捧谷子相互撒去。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"southeast" : __DIR__"xiaocun",
		"north" : __DIR__"cunzhangjia",
		"northwest" : __DIR__"minju3",
		"southwest" : __DIR__"minju4",
	]));
	set("objects", ([
		"/d/center/npc/boy" : 2,
		"/d/center/npc/girl" : 1,
	]));

	setup();
	replace_program(ROOM);
}
