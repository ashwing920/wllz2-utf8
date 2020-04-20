// shiwei2.c 带刀侍卫

inherit NPC;

void create()
{
        set_name("侍卫", ({ "shi wei", "shi", "wei" }));
        set("gender", "男性");
        set("age", random(20) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "他手握钢刀，目视前方，真是威风凛凛。\n");
        set("combat_exp",150000);
        set("shen_type", 1);
        set("attitude", "aggressive");

        set_skill("unarmed",80);
        set_skill("force", 80);
        set_skill("blade", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 80);
        set_temp("apply/damage", 80);

        set("neili",1000); 
        set("max_neili",1000);
        set("jiali",80);
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", random(12));
}

void init()
{
        object ob;
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
        if( interactive(ob = this_player()) && !is_fighting() ) {
        switch(random(10)){   
        case 1:
        message_vision("\n侍卫忽然对$N大喝一声：何方刁民，竟敢在此撒野！看刀！\n",this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
        break;
                      }
       }
}


