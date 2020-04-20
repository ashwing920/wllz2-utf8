// yang.c 杨老板 

inherit F_VENDOR_SALE;

void create()
{
        reload("yang");
        set_name("杨永福", ({ "yang yongfu", "yang","seller" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long","杨老板是土生土长的扬州人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/clone/misc/mabudai": 1,
                "/clone/cloth/beixin": 1,
                "/clone/cloth/toukui": 1,
                "/clone/cloth/cycle": 1,
                "/clone/cloth/surcoat": 1,
                "/clone/cloth/shield": 1,
                "/clone/cloth/huwan": 1,
                "/clone/cloth/zhitao": 1,
                "/clone/cloth/huyao": 1,
                "/clone/cloth/caoxie": 1,
                "/clone/cloth/pixue": 1,
                "/clone/cloth/shoutao": 1,
                "/clone/cloth/tieshou": 1,
                "/clone/cloth/jinsijia": 1,
                "/clone/misc/sleepbag": 1,
                "/clone/misc/fire": 1,
        ]));
        
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_bid","bid");
        add_action("do_deposit","deposit");
        add_action("do_setprice", "set_price");
        add_action("do_status","status");
        add_action("do_vendor_list", "list");
}
