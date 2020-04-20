// hockman.c - 当铺老板
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


#include <ansi.h>

inherit NPC;
inherit F_PAWN;
inherit F_DEALER;

string ask_me();

void create()
{
        set_name("铁算盘", ({ "tie suanpan","tie","laoban" }));
        set("title","当铺老板");
        set("long", @LONG
他是这间当铺老板，一双老奸巨滑的眼睛正笑眯眯的看着你。
LONG
);

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 56);

        set("combat_exp", random(30000)+10000);
        set("shen_type",1);

        set("env/wimpy", 30);

        set("inquiry", ([
                "当票"      : (: ask_me :),
        ]));

        setup();
        
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

        add_money("gold", 1);
}
void init()
{
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", ({ "redeem", "ransom" }) );
        add_action("do_vendor_list","list");
}
string ask_me()
{
        object me;

        me = this_player();

        if(!me->query("pawn"))
                return "你没当过东西，要当票有什么用？";
        if( !present("pawn ticket", me) ) {
                command( "nod " + me->query("id") );
                new("/clone/misc/pawn_ticket")->move(this_player());
                return "当票在这里，你拿去吧。";
        }
        else {
                command( "? " + me->query("id") );
                return "这位" + RANK_D->query_respect(me) + "，你身上不是有当票了吗？";
        }
}

