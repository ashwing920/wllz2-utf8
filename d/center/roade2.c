// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "桃源东街");
        set("long", @LONG
你走在桃源之城的东大街上，踩着坚实的青石板地面。南边是通往英
雄山庄的大门。北面是桃源城的官府，一个大皮鼓陈列的官府大门的旁边
，几个身着官服，手持钢刀的衙役正威武的站在门口把守着。一片威严之
势，让人不得不肃然起敬。
LONG
);
        set("outdoors", "taoyuan");
        set("exits", ([
                "east"  : __DIR__"roade3",
                "south" : __DIR__"shanzhuang",
                "west"  : __DIR__"roade1",
                "north" : __DIR__"guanfu",
        ]));

        set("objects", ([
                "/d/city/npc/lao-heshang": 1,
 	]) );

        setup();

	replace_program(ROOM);
}
