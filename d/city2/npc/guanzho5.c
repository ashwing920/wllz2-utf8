// guanzho5.c

inherit NPC;

void create()
{
        set_name("观众戊", ({ "wu" }));
        set("long", @LONG
此人相貌奇丑，狮鼻阔口，一望而知不是中土人士。
LONG
);
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 5);
        set("combat_exp", 20000);
        set("score", 30000);

        set_skill("dodge", 40);
        set_skill("zhaixinggong", 30);
        set_skill("unarmed", 50);
        set_skill("xingxiu-duzhang", 40);
        set_skill("parry", 60);

        map_skill("dodge", "zhaixinggong");
        map_skill("unarmed", "xingxiu-duzhang");
        map_skill("parry", "xingxiu-duzhang");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object me, ob;

        

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) && !environment(ob)->query("no_fight") && ob->query_temp("hastryup")){
                if( !ob->query_temp("warned") ) {
                        command("say 今天看戏不成，真想让你尝尝大爷我毒掌的厉害！");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        set_leader(ob);
                        command("say 看你这次往哪儿跑！");
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

