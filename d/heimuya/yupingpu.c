// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "玉屏瀑");
	set("long", @LONG
来到玉屏瀑，这里的景观真是无以比拟，一面宽宽大大晶莹如玉的瀑
布自天上泻下来，传说这是天上仙娥们在清洗天宫的玉屏风所流下地界的
天池中的圣水。
LONG
);
	set("exits",([
		"east" : __DIR__"lianhua",
		"westdown" : __DIR__"baizhang",
		"north" : __DIR__"guanpu",
	]));
	set("objects", ([
		__DIR__"npc/wolf": 1,
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
 
