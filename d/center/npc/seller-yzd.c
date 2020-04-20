// seller-yzd.c - 胭脂店老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("胭脂店老板", ({ "seller", "waiter" }) );
        set("long", @LONG
他就是胭脂店老板。
LONG
        );

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);

        set("combat_exp",20000+random(30000));
        set("env/wimpy", 30);

        setup();
        
        carry_object("/clone/cloth/green-pao")->wear();
        add_money("silver",10);
}

void init()
{       
        object ob;

        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，想买胭脂吗？\n");
                        break;
        }
}
