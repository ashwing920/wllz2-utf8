// beggar.c - 乞丐

inherit NPC;

void create()
{
        set_name("乞丐", ({ "beggar" }));
        set("long", @LONG
一个满脸风霜之色的老乞丐。
LONG
);
        set("is_beggar",1);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age",56);
        set("kar",100);
        set("int",100);

        set("combat_exp",10000);
        set("env/wimpy", 30);

        set_skill("unarmed",20); 
        set_skill("parry",  20);
        set_skill("dodge",  20);
        set_skill("begging",300);
        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();
        carry_object("/clone/cloth/puo-cloth")->wear();
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
        object me;

        me = this_object();
        if( !ob || environment(ob) != environment() ) return;

        switch(random(3)){
                case 1:
                        command("say 这位好心的"+ RANK_D->query_respect(ob)+"，给点吃的我这个死要饭的吧？");
                        break;
                case 2:
                        command("beg all from "+ ob->query("id"));
                        break;
                default:
                        command("beg1 "+ ob->query("id"));
                        break;
                        
        }

}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}
