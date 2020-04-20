inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("张掌柜", ({ "zhang zhanggui", "zhang" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",@LONG
别看张掌柜整天懒洋洋的，他心里可盘算得精着呢。在这边陲之地，再怎
么也得有几分本事。
LONG
);
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_temp("apply/damage", 25);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/clone/misc/sleepbag": 20,
                "/clone/food/jiudai": 20,
                "/clone/food/kaoya": 20,
        ]));
                
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        add_action("do_vendor_list", "list");
}
