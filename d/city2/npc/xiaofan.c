// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小贩", ({ "xiao fan", "seller", "fan" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("vendor_goods", ([
                "/d/city2/obj/tanghulu": 2,
                "/d/village/npc/obj/stick": 2,
                "/d/village/npc/obj/shoes": 2,
                "/d/village/npc/obj/bottle": 2,
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        add_action("do_vendor_list", "list");
}
