// butcher.c - 屠夫

inherit F_VENDOR_SALE;

void create()
{
        reload("butcher");
        set_name("猪肉荣", ({ "zhurou rong","rong" }) );
        set("title","屠户");
        set("long", @LONG
他是屠夫猪肉荣，一个满脸大胡子和横肉的家伙。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 35);
        set("str", 30);
        set("combat_exp",50000+random(30000));
        set("env/wimpy", 30);

        set_skill("unarmed",40); 
        set_skill("parry",40);
        set_skill("dodge",40);

        set("vendor_goods", ([
                __DIR__"obj/pig_head" :20,
                __DIR__"obj/ox_head" : 20,
        ]));
        setup();
        
        carry_object("/clone/weapon/tudao")->wield();
        carry_object("/clone/cloth/cloth")->wear();       // 装备

        add_money("silver", 10);                        // 金钱
        add_money("coin",5);
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
        switch( random(4) ) {
                case 2:
                        say( this_object()->name()+"咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
        }
}
