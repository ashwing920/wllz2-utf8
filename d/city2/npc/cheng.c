// cheng.c 程老板

inherit NPC;
inherit F_VENDOR;

string ask_me1();
string ask_me2();

void create()
{
        set_name("程老板", ({ "cheng laoban", "cheng" }));
        set("title", "全聚德老板");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 65);
        set("long", "程老板经营祖传下来的全聚德酒楼已有多年。\n");

        set("combat_exp", 50000);

        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

        set("vendor_goods", ([
                "/clone/food/jiudai": 20,
                "/clone/food/kaoya": 20,
        ]));

        set("inquiry", ([
                "谭友纪" : (: ask_me1 :),
                "谭师爷" : (: ask_me1 :),
                "叫化鸡" : (: ask_me2 :),
        ]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
         
}

string ask_me1()
{
        if ((int)this_player()->query_temp("marks/鸡2"))
        {
                this_player()->delete_temp("marks/鸡2");
                this_player()->set_temp("marks/鸡3", 1);
                return "哦，是老谭让你来的。到了这里就别见外了。你找我有什么事吗？\n";
        }
        else if((int)this_player()->query_temp("marks/鸡3"))
                return "我不是浙江人，也没有你那么罗嗦！\n";
                return "去去去。哪里来的泥腿子，这里是北京城，天子脚下！！不懂别乱问！！\n";
}

string ask_me2()
{
        if ((int)this_player()->query_temp("marks/鸡3"))
        {
                say("既然你这么喜欢吃叫化鸡，又千里迢迢地跑来找我，就卖你一只吧。\n");
                return "请先付五两黄金，咱们一手交钱、一手交货。\n";
        }
        else
                return "去去去。哪里来的泥腿子，这里是北京城，天子脚下！！懂不懂！！\n";
}

int accept_object(object who, object ob)
{
        object item;

        if ((ob->query("money_id")) && (ob->value() == 50000)
         && (who->query_temp("marks/鸡3")))
        {
        item = new("/clone/food/jiaohuaji");
        item->move(who);
        who->delete_temp("marks/鸡3");
        return 1;
        }
        else if (ob->value() < 50000)
        {
                command("say 这...这...，这我就却之不恭了。");
                return 1;
        }
        return 0;
}
