// liu 刘通

#include <ansi.h>

inherit NPC;
inherit F_PAWN;
inherit F_DEALER;
string ask_me();

void create()
{
	set_name("刘通", ({ "liu tong", "liu" }));
	set("title", "当铺老板");
	set("shen_type", 0);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"一个一看就知道是个精明的人。\n");
	set("no_get_from", 1);
	set("no_get",1);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

        set("inquiry", ([
                "当票"      : (: ask_me :),
        ]));

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
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
