
#include <ansi.h>

inherit NPC;
inherit F_PAWN;
inherit F_DEALER;

string ask_me();

void create()
{
        set_name("当铺老板", ({ "hockman" }));

        set("long", @LONG
当铺老板，一双老奸巨滑的眼睛正笑眯眯的看着你。
LONG
        );

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 56);

        set("str", 30);                         // 膂力         
        set("cps", 30);                         // 定力
        set("cor", 30);                         // 胆识         
        set("per", 30);                         // 容貌
        set("con", 30);                         // 根骨
        set("env/important",1);

        set("env/wimpy", 30);                   //

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("no_clean_up", 1);

        set("inquiry", ([
                "当票"      : (: ask_me :),
        ]));

        setup();
        
//        carry_object("/obj/cloth/cloth")->wear();       // 装备
//        carry_object("/obj/weapon/longsword")->wield();

        // add_money("gold", 5);                        // 金钱
}

void init()
{
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", ({ "redeem", "ransom" }) );
        add_action("do_vendor_list", "list");
}

string ask_me()
{
        object me;

        me = this_player();

        if( !present("pawn ticket", me) ) {
                command( "nod " + me->query("id") );
                new("/obj/misc/pawn_ticket")->move(this_player());
                return "当票在这里，你拿去吧。";
        }
        else {
                command( "? " + me->query("id") );
                return "这位" + RANK_D->query_respect(me) + "，你身上不是有当票了吗？";
        }
}

