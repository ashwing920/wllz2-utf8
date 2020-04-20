// roads5.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short","桃源南街");
        set("long", @LONG
你走在桃源南大街上，踩着坚实的青石板地面。大街的东面有一座庙
宇，庙宇上方写着「城隍庙」三个大字，据说城隍庙里的城隍老爷非常灵
验，吸引了不少善男信女前来烧香进贡。西面则是一家棺材店，棺材店里
光线昏暗，死气沉沉的，让人感到十分恐惧。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"chenghuangmiao",
                "south" : __DIR__"roads7",
                "west"  : __DIR__"guancaidian",
                "north" : __DIR__"roads5",
        ]));
        setup();
	replace_program(ROOM);
}
