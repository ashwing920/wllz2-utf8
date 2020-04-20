// beggar.c - 乞丐

inherit NPC;

void create()
{
        set_name("乞丐", ({ "beggar" }));
        set("long", @LONG
一个满脸风霜之色的老乞丐。
LONG
);

        set("attitude", "friendly");
        set("family/family_name","丐帮");
        set("gender", "男性" );
        set("age", 56);

        set("combat_exp",1000);
        set("shen_type",1);

        set("env/wimpy", 30);

        set_skill("unarmed",10); 
        set_skill("parry",  10);
        set_skill("dodge",  10);

        set("chat_chance",5);
        set("chat_msg", ({
                "乞丐说道：好心的大爷哪～赏我要饭的几文钱吧～\n",
                "乞丐说道：好心的大爷哪～可怜可怜我要饭的吧～\n",
                "乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬糜了。 \n",
                (: random_move :)
        }) );

        setup();
        
        carry_object("/clone/cloth/cloth")->wear();
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
        switch( random(1) ) {
                case 0:
                        command("beg all from "+ this_player()->query("id"));
                        break;
                case 1:
                        command("beg1");
                        break;
        }
}
