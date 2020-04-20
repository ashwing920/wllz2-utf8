// chanshi.c - 超渡禅师
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("超渡禅师", ({ "chan shi" }));
        set("title",HIY"普"HIW"渡"HIG"慈"NOR+CYN"航"NOR);
        set("long", @LONG
他就是法场超渡禅师。
LONG
);

        set("rank_info/respect", "大师");
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 40);

        set("combat_exp",20000+random(20000));

        set("env/wimpy", 30);
        setup();

        carry_object("/clone/cloth/dahong-jiasha")->wear();
}

void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( this_object()->query("name") + "叹了一口气，说道：江湖上的仇杀太多了。\n");
                        break;
                case 1:
                        say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)+"，做些好事吧。\n");
                        break;
        }
}
int accept_object(object who, object ob)
{
        int n, m;
        if(ob->is_corpse()){
                command( "pat " + who->query("id") );
                message_vision("$n对$N说道：你做得很好，这是积德行善的第一步。\n",who, this_object());
                m = random(10) + 2;
                n = random(10) + 2;
                who->add("potential", m);
                who->add("combat_exp", n);
                who->add("shen",m);
                tell_object(who,sprintf("你的潜能增加了%d点！\n", m));
                tell_object(who,sprintf("你的经验增加了%d点！\n", n));
                tell_object(who,sprintf("你的正气增加了%d点！\n",m));
                return 1;
        }
        command( "hehe" );
        message_vision("$n笑咪咪地对$N说：这位施主心地真好！好心一定会有好报的！\n", who, this_object());
        return 1;
}
