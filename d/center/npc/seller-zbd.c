// seller-zbd.c - 珠宝店老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
        reload("seller-zbd");
        set_name("珠宝店老板", ({ "seller", "waiter" }) );
        set("nickname",HIM"唯利是图"NOR);
        set("long", @LONG
他就是珠宝店老板。非头大耳，一脸奸笑。
LONG
);

        set("rank_info/respect","老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);

        set("combat_exp",10000+random(30000));
        set("env/wimpy", 30);
        set("vendor_goods", ([
                "/clone/obj/jade1": 1,
                "/clone/obj/jade2": 1,
                "/clone/obj/jade3": 1,
                "/clone/obj/jade4": 1,
        ]) );

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
}

void init()
{       
        object ob;
        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_bid","bid");
        add_action("do_deposit","deposit");
        add_action("do_setprice", "set_price");
        add_action("do_status","status");
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，想买珠宝吗？\n");
                        break;
        }
}
