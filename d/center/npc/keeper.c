// keeper.c - 庙祝
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("庙祝", ({ "keeper" }) );
        set("long", @LONG
这个老人看起来七十多岁了，看著他佝偻的身影，你忽然觉得心情沈
重了下来。
LONG
);

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 72);
        set("combat_exp",50000+random(10000));
        set("env/wimpy", 30);

        set("vendor_goods", ([
                "/clone/book/new_book/taoism_a": 1,
                "/clone/book/new_book/taoism_b": 1,
                "/clone/book/new_book/taoism_c": 1,
                "/clone/book/new_book/taoism_d": 1,
                "/clone/book/new_book/taoism_e": 1,
                "/clone/book/new_book/buddhism_a": 1,
                "/clone/book/new_book/buddhism_b": 1,
                "/clone/book/new_book/buddhism_c": 1,
                "/clone/book/new_book/buddhism_d": 1,
                "/clone/book/new_book/buddhism_e": 1,
        ]));

        set_skill("unarmed", 50); 
        set_skill("parry",   50);
        set_skill("dodge",   50);

        setup();
        
        carry_object("/clone/cloth/cloth")->wear();     // 装备
}

void init()
{       
        object ob;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list","list");
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "庙祝说道：这位" + RANK_D->query_respect(ob) + "，捐点香火钱积点阴德吧。\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("庙祝不收物品的捐献。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
                if( (who->query("beggar") > 0)
                &&      (random(val/1000) > (int)who->query("kar")) ) {
                        who->add("beggar", - (random((int)who->query("kar")-10) + val/10000) );
                        if(who->query("beggar")<0)      who->delete("beggar");
                }
        }
        say( "庙祝说道：多谢这位" + RANK_D->query_respect(who) + "，神明一定会保佑你的。\n");

        return 1;
}
  
