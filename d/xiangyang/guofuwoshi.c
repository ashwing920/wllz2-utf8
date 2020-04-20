// Room: /d/xiangyang/guofuwoshi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这里就是郭靖和黄蓉的卧室。屋子里的陈设很简单。门的左边有一张
软床。床上的被褥被叠得整整齐齐。床头正对的地方摆着一张梳妆台。桌
上摆着一个光亮的铜镜，铜镜旁边的花瓶里，有一束百合花，正在散发出
淡淡的幽香。里边放着两张木椅，中间是一茶几，上面摆着一盆山茶花。
LONG
);
	set("exits", ([
		"west" : __DIR__"guofuhuayuan",
	]));
	setup();
	replace_program(ROOM);
}

