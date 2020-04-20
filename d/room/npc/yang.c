// yang.c 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("杨老板",({"yang laoban","seller","boss"}));
        set("title","桃源山庄杂货店老板");
        set("gender","男性");
        set("age",20);
        set("per",30);
        set("attitude", "friendly");
        set("long",@LONG
一个皮肤黝黑的中年人。在此地开店足有树十载，深受邻里们的欢迎。
LONG
);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("sword", 150);
        set("combat_exp", 70000);
        set("vendor_goods", ([
                "/clone/misc/mabudai": 20,
                "/clone/cloth/beixin": 20,
                "/clone/cloth/toukui": 20,
                "/clone/cloth/cycle": 20,
                "/clone/cloth/surcoat": 20,
                "/clone/cloth/shield": 20,
                "/clone/cloth/huwan": 20,
                "/clone/cloth/zhitao": 20,
                "/clone/cloth/huyao": 20,
                "/clone/cloth/caoxie": 20,
                "/clone/cloth/pixue": 20,
                "/clone/cloth/shoutao": 20,
                "/clone/cloth/tieshou": 20,
                "/clone/cloth/jinsijia": 20,
                "/clone/misc/sleepbag": 20,
                "/clone/misc/fire": 20,
        ]));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        object ob;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"忙说：请进，请进！\n");
                        break;
        }
}
