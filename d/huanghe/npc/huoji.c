// huoji. 药铺伙计

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("伙计", ({ "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("per", 18);
        set("age", 18);
        set("long", "他是这儿的伙计，正在店里忙里忙外。\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/clone/yaowu/jinchuang": 20,
                "/clone/yaowu/yangjing": 20,
                "/clone/yaowu/wuchangdan": 20,
                "/clone/yaowu/zhujingchan": 20,
                "/clone/misc/dust": 20,
                "/d/shenlong/obj/xionghuang": 20,
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
         
}
