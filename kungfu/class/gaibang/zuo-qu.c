// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("左全", ({"zuo quan", "zuo", "quan"}));
        set("title", "丐帮七袋弟子");
        set("gender", "男性");
        set("age", 35);
        set("long",@LONG
这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。
LONG
);
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);

        set("jing",2000);
        set("max_jing",2000);
        set("neili",3000);
        set("max_neili",3000);
        set("jiali",150);
        set("combat_exp",800000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "regenerate" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: exert_function, "shengang" :),
                (: perform_action, "unarmed.slzy" :),
                (: perform_action, "unarmed.jingtian" :),
                (: perform_action, "unarmed.jingtian" :),
                (: perform_action, "hand.suo" :),
        }) );

        set_skill("force", 200);
        set_skill("huntian-qigong", 200);
        set_skill("unarmed", 200);
        set_skill("xianglong-zhang", 200);
        set_skill("dodge", 200);
        set_skill("xiaoyaoyou", 200);
        set_skill("parry", 200);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("training",200);
        set_skill("hand",200);
        set_skill("shexing-diaoshou",200);
        map_skill("hand","shexing-diaoshou");
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry","xianglong-zhang");
        create_family("丐帮", 19, "弟子");
        setup();
}

void attempt_apprentice(object ob)
{
        if((int)ob->query("shen") < 0 ) {
                command("say 丐帮在江湖中一向行侠仗义，从不和邪魔歪道之人打交道！");
                return;
        }
        if((int)ob->query("str") < 26) {
                command("say 我们丐帮的武艺一向以刚猛为主，" +
                RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
                return;
        }
        if((int)ob->query("con") < 23) {
                command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
                return;
        }

        command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！");
        command("recruit " + ob->query("id"));
        ob->set("class","beggar");
}
