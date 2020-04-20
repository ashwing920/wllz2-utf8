// guanzho3.c

inherit NPC;

void create()
{
        set_name("观众丙", ({"bing"}));
        set("gender", "女性");
        set("age", 18);
        set("long", "这是一位小姑娘。\n");
        set("attitude", "peaceful");
        
        set("str", 18);
        set("int", 30);
        set("con", 21);
        set("dex", 26);

        set("qi", 200);
        set("max_qi", 200);
        set("jing", 100);
        set("max_jing", 100);
        
        set("combat_exp", 5000);
        set("score", 0);
        
        set_skill("force", 60);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 65);
        
        setup();
        carry_object("/clone/cloth/pink_cloth")->wear();
        carry_object("/clone/cloth/flower_shoe")->wear();
}

void init()
{

        object me, ob;

        

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) && !environment(ob)->query("no_fight") && ob->query_temp("hastryup"))
        {
                if( !ob->query_temp("warned") ) {
                        command("say 居然有人敢不让我看戏，气死我了！");
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say 我杀了你！！！\n");
                        set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                }
        }          

}
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
void leave()
{
	if (!environment()) return;
        message("vision",name() +"骂道：下次见你决不饶你。\n",environment(),this_object());
        destruct(this_object());
}

