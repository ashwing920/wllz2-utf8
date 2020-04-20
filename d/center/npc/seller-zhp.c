// seller-zhp.c - 杂货铺老板

inherit NPC;
inherit F_VENDOR;
string ask_tu();
void create()
{
        set_name("吴用", ({ "wu yong","wu" }) );
        set("title","杂货店老板");
        set("long", @LONG
他就是杂货铺老板。一副老气横秋的样子，脸上布满了皱纹。
LONG
);

        set("rank_info/respect", "老板");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 35);

        set("combat_exp",20000+random(20000));
        set("shen_type",1);
        set("inquiry",([
              "藏宝图": (: ask_tu() :),
        ]));
        set("env/wimpy", 30);
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
        add_money("silver",10);
}

void init()
{
        object ob;


        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( this_object()->name()+"笑咪咪地说道：这位" + RANK_D->query_respect(ob)+ "，想买点什么吗？\n");
                        break;
        }
}
string ask_tu()
{
        object me;

        me = this_player();

        if(me->query("combat_exp") < 100000)
                return "这位" + RANK_D->query_respect(me) + "涉世未深，寻宝的事情还是以后再说吧！";

        if(present("cangbao tu", me) )
                return "你不是已经有藏宝图了吗？";
        if(!present("cangbao tu", me) ) {
                command( "nod " + me->query("id") );
                new("/d/obj/quest/tu")->move(this_player());
                return "这就是藏宝图，你拿去吧。";
        }
        else {
                command( "? " + me->query("id") );
                return "这位" + RANK_D->query_respect(me) + "，你身上不是有藏宝图了吗？";
        }
}

