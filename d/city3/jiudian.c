// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: jiudian.c

inherit ROOM;

void create()
{
	set("short", "蜀都酒楼");
	set("long", @LONG
这是一座有着三开间门面的大酒楼，虽说不上雕梁画栋，却也气派不
凡。正首门梁上挂着一幅黑漆匾，上写着“蜀都酒楼”四个金漆大字。楼
中桌洁椅净，座中客人衣饰豪奢，十九是富商大贾。这是一家百年老店，
传到现在的这位掌柜已经是第四代，据说和提督大人有点不清楚，却也保
佑了这间酒楼的日进斗金。东南角有一道方梯通往楼上雅座，往西南则可
以出到东大街。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/tanghua" : 1,
		__DIR__"npc/xiaoer2" : 1,
	]) );
	
	setup();
	replace_program(ROOM);
}
