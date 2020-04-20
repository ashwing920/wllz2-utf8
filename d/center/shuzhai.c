// shuzhai.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
	set("short", "桃源书斋");
	set("long", @LONG
这里是桃源城里唯一的一家书斋，为桃源城的百姓们提供了不少书籍
。只见书斋的右边上放满了各式各样的书籍，十分整齐的排列着。一个年
过半百的老者正在书斋中来回夺步，象在思考着什么。
LONG
);
	set("exits", ([
                "west"	: __DIR__"roadn5",
        ]) );			

        set("objects", ([	
                __DIR__"npc/seller-sz": 1,
                __DIR__"npc/boy":2,
	]));
	setup();
	replace_program(ROOM);
}
