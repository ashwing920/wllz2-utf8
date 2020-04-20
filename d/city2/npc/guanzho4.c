// guanzho4.c

inherit NPC;

void create()
{
        set_name("观众丁", ({ "ding" }));
        set("long", "此人身材瘦小，却是气宇暄昂, 似乎身怀惊人艺业。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        set("combat_exp", 30000);
        set("score", 3000);

        set_skill("huashan-zhangfa", 40);
        set_skill("unarmed",60);
        set_skill("force", 60);
        set_skill("zixia-shengong", 30);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("huashan-sword", 35);
        set_skill("huashan-shenfa",35);

        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-sword");
        map_skill("sword", "huashan-sword");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{

        object me, ob;

        

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) && !environment(ob)->query("no_fight") && ob->query_temp("hastryup")){
                if( !ob->query_temp("warned") ) {
                        command("say 你也不看看长自己什么样，居然到这儿来撒野！");
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        set_leader(ob);
                        command("say 你还想跑，我非宰了你不可！");
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

