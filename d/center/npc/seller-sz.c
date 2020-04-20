// seller-sz.c - 书斋老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit NPC;
inherit F_VENDOR;

#include <ansi.h>

void create()
{
        set_name("唐鸣",({ "tang ming", "seller","tang"}));
        set("title","智慧老人");
        set("nickname",HIY"书中自有黄金屋"NOR);
        set("long", @LONG
他是书斋的老板唐鸣。据说家中世代书香门第，收藏了不少书籍。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);
        set("str", 30);
        set("combat_exp",30000+random(30000));
        set("shen_type",1);
        set("env/wimpy", 30);
        set("vendor_goods", ([
                "/clone/book/lbook1": 1,
                "/clone/book/lbook2": 1,
                "/clone/book/lbook3": 1,
                "/clone/book/lbook4": 1,
                "/clone/book/new_book/parry_a": 1,
                "/clone/book/new_book/parry_b": 1,
                "/clone/book/new_book/parry_c": 1,
                "/clone/book/new_book/parry_d": 1,
                "/clone/book/new_book/finger_a": 1,
                "/clone/book/new_book/finger_b": 1,
                "/clone/book/new_book/finger_c": 1,
                "/clone/book/new_book/finger_d": 1,
                "/clone/book/new_book/unarmed_a": 1,
                "/clone/book/new_book/unarmed_b": 1,
                "/clone/book/new_book/unarmed_c": 1,
                "/clone/book/new_book/unarmed_d": 1,
                "/clone/book/new_book/hand_a": 1,
                "/clone/book/new_book/hand_b": 1,
                "/clone/book/new_book/hand_c": 1,
                "/clone/book/new_book/hand_d": 1,
                "/clone/book/new_book/sword_a": 1,
                "/clone/book/new_book/sword_b": 1,
                "/clone/book/new_book/sword_c": 1,
                "/clone/book/new_book/sword_d": 1,
                "/clone/book/new_book/dodge_a": 1,
                "/clone/book/new_book/dodge_b": 1,
                "/clone/book/new_book/dodge_c": 1,
                "/clone/book/new_book/dodge_d": 1,
                "/clone/book/new_book/cuff_a": 1,
                "/clone/book/new_book/cuff_b": 1,
                "/clone/book/new_book/cuff_c": 1,
                "/clone/book/new_book/cuff_d": 1,
                "/clone/book/new_book/strike_a": 1,
                "/clone/book/new_book/strike_b": 1,
                "/clone/book/new_book/strike_c": 1,
                "/clone/book/new_book/strike_d": 1,
                "/clone/book/new_book/force_a": 1,
                "/clone/book/new_book/force_b": 1,
                "/clone/book/new_book/force_c": 1,
                "/clone/book/new_book/force_d": 1,
                "/clone/book/new_book/blade_a": 1,
                "/clone/book/new_book/blade_b": 1,
                "/clone/book/new_book/blade_c": 1,
                "/clone/book/new_book/blade_d": 1,
                
        ]));
        setup();

        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 10);
}
void init()
{
        add_action("do_vendor_list","list");
}
