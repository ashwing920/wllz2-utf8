// duanyu.c 段誉

inherit NPC;

void create()
{
        set_name("段誉", ({"duan yu", "duan", "yu"}));
        set("nickname","大理王子");
        set("gender", "男性");
        set("age", 20);
        set("long","他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
        set("attitude", "peaceful");
        set("str", 12);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("chat_chance",5);
        set("chat_msg", ({
                "段誉叹了口气道：“唉……何时能再见到语嫣啊……”\n",
                (: random_move :),
        }));
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "register" :),
                (: perform_action, "finger.liumai" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.tan" :),
                (: perform_action, "finger.feng":),
        }));
        set("inquiry", ([
                "大理" : "大理是个好地方，山清水秀，风景宜人。\n",
                "王语嫣" : "唉，她心里只有她表哥，从来就没把我放在眼里。\n",
                "拜师" : "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。\n",
        ]));
        set("max_neili",4000);
        set("neili",4000);
        set("max_jing",2000);
        set("jiali",150);
        set("combat_exp",2000000);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("staff", 200);
        set_skill("finger", 200);
        set_skill("kurong-changong", 200);
        set_skill("tiannan-step", 200);
        set_skill("jinyu-quan", 200);
        set_skill("wuluo-zhang", 200);
        set_skill("duanjia-sword", 200);
        set_skill("sun-finger", 200);
        set_skill("literate", 200);
        set_skill("liumai-shenjian",200);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("finger", "liumai-shenjian");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "sun-finger");
        map_skill("sword", "duanjia-sword");
        map_skill("staff", "duanjia-sword");

        prepare_skill("strike", "wuluo-zhang");
        prepare_skill("finger","liumai-shenjian");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/misc/shoe")->wear();
        add_money("silver",50);
}
