// seller-zqp.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("竹器铺老板", ({ "seller", "waiter" }) );
        set("long", "他就是竹器铺老板。\n");

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 50);

        set("combat_exp", 10);
        set("SEN",10);

        set("vendor_goods", ([
                "/clone/weapon/bamboo_blade" : 20,
                "/clone/weapon/bamboo_sword" : 20,
        ]) );

        setup();
}

void init()
{       
        object ob;

        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "竹器铺老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，想买竹器吗？\n");
                        break;
        }
}
