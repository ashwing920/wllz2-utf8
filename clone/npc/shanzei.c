// rascal.c

#include <ansi.h>

inherit NPC;

void create()
{
        int level;
        set_name(npc_name("男性"),({"shan zei","zei"}));
        set("title","黑山寨山贼");
        set("long",@LONG
这是黑山寨的一名喽罗，腰配单刀，样子看起来很凶狠。
LONG
);

        set("attitude", "heroism");
        set("age", random(20) + 30);
        set("str", 20 + random(11));
        set("cps", 20 + random(11));
        set("cor", 20 + random(11));
        set("per", 20 + random(11));
        set("int", 20 + random(11));
        set("con", 20 + random(11));
        set("spi", 20 + random(11));
        set("kar", 20 + random(11));

        set("chat_chance_combat",5);
        set("chat_msg_combat", ({
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：挡我大爷发财就是死路一条。\n", name()),
                sprintf("%s喝道：呸！大爷的事也敢管，去死吧！\n", name()),
        }) );
        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("jing",2000);
        set("max_jing",2000);
        set("max_qi",4000);
        set("qi",4000);
        set("neili",5000);
        set("max_neili",5000);          
        set("jiali",200);
        set("shen_type",-1);
        set("bellicosity",8000);

        level = 100 + random(100);
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
        set_skill("perception",level);

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

        set("combat_exp",500000 + (100000 * random(10)));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/misc/shoe")->wear();
        carry_object("/clone/cloth/shield")->wear();
        add_money("silver",50);
        remove_call_out("back");
        call_out("back",300,this_object());
}
void init()
{
        object ob;
        if( interactive(ob = this_player()) && !is_fighting()) {
                say(sprintf("%s喝道：嘿！让大爷我撞见了就是死路一条，纳命来！\n",this_object()->query("name")));
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
                this_object()->set_leader(ob);
        }
        add_action("do_halt","halt");
}
void afterdie_func(object killer)
{
        object me;
        int m, n;

        me = this_object();
        
        if(!killer) return;

        message("channel:chat",HIM"【江湖风云】"+ sprintf(NOR + WHT"%s把黑山寨来的%s杀死了，解救了当地的百姓。\n"NOR,
        killer->query("name"),me->query("name")),users());

        message_vision(sprintf( "$N杀死了%s，拯救了当地的百姓。\n", me->name()), killer);
        message_vision("由于$N的侠义表现，$N得到了奖励。\n", killer);

        m = 100 + random(50);
        n = 150 + random(100);
        killer->add("potential",m);
        killer->add("combat_exp",n);
        tell_object(killer, sprintf("你的潜能增加了%s点！\n", chinese_number(m)));
        tell_object(killer, sprintf("你的经验增加了%s点！\n", chinese_number(n)));

}
void back()
{
        if(!this_object() || !environment(this_object())) return;
        message_vision("$N见没得手，骂骂咧咧的离开了。\n",this_object());
        destruct(this_object());
}
int do_halt(string arg)
{
        object ob,me;
        ob = this_player();
        me = this_object();
        if( ob->is_fighting(me) && me->is_fighting(ob)){
        message_vision("$N想跳出战圈不打了，$n喝道：想逃？没那么容易！\n",ob,me);
        return 1;
        }
}
