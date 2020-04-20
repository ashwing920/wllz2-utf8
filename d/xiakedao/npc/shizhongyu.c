// shizhongyu.c 石中玉

inherit NPC;

void create()
{
        set_name("石中玉", ({ "shi zhongyu", "shi", "zhongyu" }));
        set("gender", "男性");
        set("age", 20);
        set("str", 15);
        set("int", 45);
        set("con", 18);
        set("dex", 20);
        set("per", 30);
        set("long",@LONG
这是一个年轻公子，大约二十左右岁，面若中秋之月，色如春晓之花，鬓
若刀裁，眉如墨画，鼻如悬胆，情若秋波，虽怒而时笑，即视而有情。
LONG
);
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 30);
        set_skill("force", 30);
        set_skill("blade", 20);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate",100);

        set_skill("wuhu-duanmendao", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 10);
        map_skill("blade", "wuhu-duanmendao");

        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        set("inquiry", ([
                "侠客岛" : "在泉州附近的一个小岛。\n",
                "石破天" : "他是我的亲兄弟，他现在在侠客岛。你见了他可别忘了带玄冰碧火酒呀。\n",
                "叮当"   : "我好久没见到她了，不知道她现在怎么样了。\n",
                "赏善罚恶令" : "有了它，你可以到侠客岛学武功呀。\n",
        ]) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "\n石中玉说道: 叮当，你在哪呀，我好想你呀。\n",
                "\n石中玉叹道: 也不知道我的叮当怎么样了。\n",
                "\n石中玉说道: 腊八粥可是好东西...\n",
                "\n石中玉说道: 唉，谁能帮我杀了外面的老头，兄弟我谢谢你了！\n",

        }) );
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision( "\n石中玉哈哈大笑道：我终于看见救我的人来了。\n",this_object());
}
void die()
{
        say("\n石中玉说道：我还有个心愿没了，希望你能帮我照顾叮当！\n");
        message_vision("石中玉喊着叮当的名字，死了！\n", this_object());
        ::die();
}
int accept_object(object who, object ob)
{
        object obn;

        if((string)ob->query("id") == "shou pa")
        {
                message_vision("\n石中玉感动的热泪迎眶：终于知道了她的消息了！\n",who);
                obn = new("/d/xiakedao/obj/shane-bu");
                CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s拿到%s了。",who->query("name"),obn->query("name")));
                obn->move(who);
                return 1;
        }
}
