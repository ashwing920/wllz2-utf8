// wu-shi1.c 盟主卫士

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("白衣武士", ({ "wei shi", "shi", "guard" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","这是位白衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("combat_exp", 100000);
        set("attitude", "heroism");

        set("str", 30);
        set("con", 25);
        set("int", 20);
        set("dex", 30);

        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 200);
        set("jing", 200);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("shen_type", 0);
        set("join",0);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);

        set_skill("sword", 100);
        set_skill("unarmed", 80);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;

        if( interactive(ob = this_player()) 
        && !is_fighting() 
        && ob = this_object()->query("guard/master")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_kill","kill");
        add_action("do_kill","hit");
        add_action("do_kill","ansuan");
}
void greeting(object ob)
{
        object obj;
        obj = this_object();
        
        if( !ob || environment(ob) != environment() ) return;
        if(obj->query("join")) return;
        obj->set("join",ob);
        message_vision(HIW"$N上前对$n一拜道：属下"+ obj->query("name")+"愿誓死跟随"+ ob->query("name")+"英雄，保护"+ ob->query("name")+"的安危！\n"NOR,obj,ob);
        ob->add_team_member(obj);
        message_vision(HIW"$N决定加入$n的队伍。\n"NOR,obj,ob);
        obj->set_leader(ob);
        return;
}
int do_kill(string arg)
{
        object ob;
        ob = this_object();

        if(arg != ob->query("guard/id") || this_player() == ob->query("guard/master")) return 0;
        message_vision("$N立刻冲上前去，对$n发起猛烈的攻击！\n",ob,this_player());
        ob->kill_ob(this_player());
        return 1;
}
