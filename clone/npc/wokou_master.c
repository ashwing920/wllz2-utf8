//wokou_master.c

#include <ansi.h>

inherit NPC;
void make_skill();
void create()
{
        int level;
        set_name("倭寇首领",({"wokou shouling","shouling"}));
        set("long", "他是这帮倭寇当中的首领。\n");
        set("gender","男性");
        set("family/family_name","云龙门");
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
        set("no_get",1);
        set("chat_chance",10);
        set("chat_msg",({
                (: random_move :)
        }));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duan" :),
        }) );
        set("neili",3000);      
        set("max_neili",3000);
        set("jiali",100);
        set("shen_type",-1);
        set("bellicosity",5000);

        level = 300 + random(200);
        set_skill("literate", level);
        set_skill("force", level);
        set_skill("dodge", level);
        set_skill("unarmed", level);
        set_skill("parry", level);
        set_skill("whip", level);
        set_skill("blade", level);
        set_skill("sword", level);
        set_skill("hand", level);
        set_skill("claw", level);
        set_skill("houquan", level);
        set_skill("yunlong-xinfa", level);
        set_skill("yunlong-shengong", level);
        set_skill("wuhu-duanmendao", level);
        set_skill("yunlong-jian", level);
        set_skill("yunlong-shenfa", level);
        set_skill("yunlong-bian", level);
        set_skill("yunlong-shou", level);
        set_skill("yunlong-zhua", level);

        map_skill("dodge", "yunlong-shenfa");
        map_skill("force", "yunlong-shengong");
        map_skill("unarmed", "houquan");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("hand", "yunlong-shou");
        map_skill("parry", "yunlong-shou");
        map_skill("claw", "yunlong-zhua");
        map_skill("sword", "yunlong-jian");
        map_skill("whip", "yunlong-bian");
        prepare_skill("hand","yunlong-shou");
        prepare_skill("claw","yunlong-zhua");
        set("combat_exp", random(1000000) + 1000000);
        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("gold",100);
        remove_call_out("back");
        call_out("back",120,this_object());
}

void init()
{
        object ob;
        if( interactive(ob = this_player()) && !this_object()->is_fighting()
        && ob->query("mud_age") > 345600 ) {
                say("倭寇抬眼大怒，牙缝里出声：八格牙路！你的，死啦死啦的！\n");
                make_skill();
        }
}
void make_skill()
{
        object ob;
        ob = this_player();
        this_object()->set("combat_exp",ob->query("combat_exp"));
        NPC_D->full_init(this_object());
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
        return;
}
void afterdie_func(object killer)
{
        object me;
        int m, n, i;

        me = this_object();
        
        i = killer->query("combat_exp") / 10000;
        if( i > 500 ) i = 500;
        m = random(300) + i / 5 + 1;
        n = random(10) + i + 1;
        killer->add("potential",n);
        killer->add("weiwang",m);
        killer->add("score",100);
        SCORE_D->set_score(killer);
        message("channel:rumor",HIM"【武林传奇】某人：听说倭寇首领被"+ killer->name() +"["+killer->query("id")+"]干掉了，"+killer->name()+"获得了江湖阅历"+ HIY+"一百"+HIM"点！\n"NOR,users());
        message_vision("$N杀死了倭寇首领，保卫了大清的江山，获得了奖励。\n",killer);
        tell_object(killer, sprintf("你的潜能增加了%s点！\n", chinese_number(n)));
        tell_object(killer,sprintf("你的经验也增加了%s点！\n",chinese_number(n)));
        tell_object(killer, sprintf("你的江湖威望增加了%s点！\n", chinese_number(m)));
        tell_object(killer,"你的江湖阅历增长了一百点。\n");

}

void back()
{
        if(!this_object()) return;
        destruct(this_object());
}
