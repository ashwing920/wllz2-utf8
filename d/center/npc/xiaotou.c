// xiaotou.c - 小偷

#include <ansi.h>

inherit NPC;

void create()
{

        set_name("小偷", ({ "xiao tou" }) );
        set("long", @LONG
这是一名小偷。
LONG
);

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 25);

        set("str", 30);                 // 膂力         
        set("cps", 30);                 // 定力
        set("cor", 30);                 // 胆识         
        set("per", 30);                 // 容貌
        set("con", 30);                 // 根骨

        set("combat_exp",30000);
        set("shen_type",-1);

        set("env/wimpy", 30);

        set("chat_chance",5);
        set("chat_msg",({
              (: random_move :),
        }));
        set_skill("unarmed",50); 
        set_skill("parry",  50);
        set_skill("dodge",  50);
        set_skill("stealing",70 + random(50));

        setup();

        carry_object("/clone/cloth/cloth")->wear();     // 装备
        add_money("silver", 5);                         // 金钱
}
 
void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("steal_it");
                call_out("steal_it", 1, ob);
        }
}
void steal_it(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        command("grin");
        command("steal all from " + ob->query("id"));
}
int accept_fight(object me)
{
        command("say 好小子，居然管起大爷的事来，看招！");
        command("grin");
        kill_ob(me);
        return 1;
}
