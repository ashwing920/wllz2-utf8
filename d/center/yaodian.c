// yaodian.c - 药  店
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "回春堂");
        set("long", @LONG
这里是桃源城的回春堂。回春堂几百个小抽屉里密密麻麻堆的都是药
材。大老远就能闻到从这里散发出来的一股浓厚的药香。药店老板坐在茶
几旁，独自喝茶，看都不看你一眼。门口有一块牌子(sign)，上面好象写
着什么。
LONG
);
        set("exits", ([
                "north" : __DIR__"roadw3",
        ]) );                   
        set("item_desc",([
                "sign": @TEXT

　　治疗伤寒，感冒，中暑等小病，每次10两白银，药到病除。

                                        回春堂
TEXT
        ]));
        set("objects", ([
                __DIR__"npc/doctor": 1,
        ]) );
        setup();
        replace_program(ROOM);
}
