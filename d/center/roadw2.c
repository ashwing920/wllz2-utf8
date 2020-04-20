// roadw2.c - 西大街
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","桃源西街");
        set("long", @LONG
这里是桃源城的西大街，你脚踩着坚实的青石板地面。北边有一家珠
宝店，出售一些十分珍贵的珠宝，吸引了不少古玩收藏家们前去鉴赏，生
意还算不错。南面有一家胭脂店，出售的多数是一些来自关外的胭脂水粉
，站在这里，隐约可以闻到些许芳香扑鼻而来。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"roadw1",
                "south" : __DIR__"yanzhidian",
                "west"  : __DIR__"roadw3",
                "north" : __DIR__"zhubaodian",
        ]));
        set("objects",([
        	__DIR__"npc/xiaofan": 1,
        	__DIR__"npc/kid": 2,
	]));
        setup();

	replace_program(ROOM);
}
