// 巡城附带人物。

inherit NPC;

void create()
{
        string *my_name = ({ "恶棍", "恶霸", "流氓","地痞","小流氓"});
        string *ob_name = ({ "小男孩", "小女孩", "年轻人", "小姑娘", "姑娘", 
                             "老头子", "老太太" });

        set_name(my_name[ random( sizeof(my_name) ) ], ({ "rascal" }) );
        set("help_ob_name", ob_name[ random( sizeof(ob_name) ) ]);
        set("long", sprintf("这是一名%s，样子很凶狠。\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);

        set("str", 20 + random(11));
        set("cps", 20 + random(11));
        set("cor", 20 + random(11));
        set("per", 20 + random(11));
        set("int", 20 + random(11));
        set("con", 20 + random(11));
        set("spi", 20 + random(11));
        set("kar", 20 + random(11));

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：多管闲事，你活得不耐烦了吧！\n", name()),
                sprintf("%s喝道：呸！大爷的事也管，去死吧！\n", name()),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("neili", 500);      set("max_neili", 500);          set("jiali",60);

        set_skill("force", random(40) + 10 );
        set_skill("unarmed", random(40) + 10 );
        set_skill("parry", random(40) + 10 );
        set_skill("dodge", random(40) + 10 );
        set("combat_exp", random(4000) + 1000);
        
        setup();

        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
        call_out("back",30,this_object());
}
void afterdie_func(object killer)
{
        object me;
        me = this_object();
        if( killer->query_temp("xuncheng")){
                message_vision( sprintf("$N打败了%s，帮助了可怜的%s，维护了当地的治安。\n", 
me->name(), me->query("help_ob_name") ), killer);
                killer->set_temp("xuncheng_path/"+ time(),1);
                killer->set_temp("xuncheng_kill",1);
        }
}
void back()
{
        if(!this_object()) return 0;
        if(this_object()->is_fighting())
                call_out("back",30,this_object());
        else
                destruct(this_object());
}
