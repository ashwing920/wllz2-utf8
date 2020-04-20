// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long","这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");

        set("chat_chance", 3);
        set("chat_msg", ({
                "店小二道：这江湖之中哪，北有少林寺，南有武当山，东是丐帮，西是星宿，西北还有华山派。\n",
                "店小二道：客官，如果你想知道详情的话，问我可是找对人了！ 不过， 嘻嘻嘻 ... \n",
                "店小二道：这阵子本店生意好做得很，南来北往的大爷们随便赏小的们几个钱，都有得花了！\n",
                "店小二道：嘉兴有个铁枪庙，祀奉的是五代时名将铁枪王彦章！\n",
        }) );

        set("vendor_goods", ([
                "/clone/food/jitui":1,
                "/clone/food/jiudai":1,
                __DIR__"obj/tangbao":1,
                __DIR__"obj/dianxin":1,
                __DIR__"obj/zongzi":1,
        ]));
        setup();
        carry_object("/clone/cloth/cloth");
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 400)
        {
                tell_object(who, "店小二一哈腰，说道：多谢您老，小的给您头前引路，客官这就请上楼歇息。\n");
                who->set_temp("rent_paid",1);
                set_temp("leading", 1);
                remove_call_out("do_up");
                call_out("do_up", random(5), this_object(), who);
                return 1;
        }
        else if (ob->query("money_id") && ob->value() >= 10)
        {
                tell_object(who, "店小二忙堆起笑容，说道：多谢您老，有什么话，您尽管问！\n");
                who->set_temp("ready_ask",1);
                return 1;
        }

        return 0;
}
int accept_kill(object obj)
{
        command("chat 各位客官救命啊！ " + obj->name() + "这个" + RANK_D->query_rude(obj) + "要杀了我！");
}
