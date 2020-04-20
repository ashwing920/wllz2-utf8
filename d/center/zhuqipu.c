// zhuqipu.c - 竹器铺
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short", "竹器铺");
        set("long", @LONG
这里是桃源城的竹器铺。货架上摆着琳琅满目的竹器。桃源城中居民
所需的竹器都是来自这里。老板从二十六岁就继承父业接过了这间竹器店
，凭着价廉物美的宗旨，已经苦心经营了二十多年了。
LONG
);
        set("exits", ([
                "west": __DIR__"roads3",
        ]));
        set("objects", ([
                __DIR__"npc/seller-zqp" : 1,
        ]) );

        setup();

        replace_program(ROOM);
}
