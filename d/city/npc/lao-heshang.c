// lao-heshang.c - 老和尚

#include <ansi.h>

inherit NPC;

#define SET_SKILL       60                      // 定义基本武功的值（随机），自动生成经验
#define SET_SEN         5                       // 定义正气的值

string ask_me1();
string ask_me2();

void create()
{
        int n;

        set_name("老和尚", ({ "he shang" }) );

        set("long", @LONG
他是一个来传播佛法的老和尚。
LONG
        );

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 30);

        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
        set("shen_type",1);
        set("env/wimpy", 30);                   //

        n = SET_SKILL + random(10) - 5;         set_skill("unarmed", (n <= 0) ? 1 : n); 
        n = SET_SKILL + random(10) - 5;         set_skill("parry",   (n <= 0) ? 1 : n);
        n = SET_SKILL + random(10) - 5;         set_skill("dodge",   (n <= 0) ? 1 : n);

        set("chat_chance_combat", 30 );
        set("chat_msg_combat", ({
                (: command, "say 阿弥陀佛，善哉善哉。" :),
                (: command, "say 施主，放下屠刀，立地成佛。" :),
        }) );

        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("inquiry", ([
                "悔过"      : (: ask_me1 :),
                "放下屠刀"  : (: ask_me2 :),
        ]));

        setup();
        
        carry_object("/clone/cloth/dahong-jiasha")->wear();
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
        switch( random(2) ) {
                case 0:
                        if( ob->query( "bellicosity" ) > 0 ) 
                                say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                        + "脸上杀气太重，可要日诵佛经三百遍，好好悔过才是。\n");
                        break;
                case 1:
                        if( sizeof( ob->query_killer())) 
                                say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                        + "杀孽太重，可要日诵佛经三千遍，放下屠刀才是。\n");
                        break;
        }
}

string ask_me1()
{
        object me;

        me = this_player();

        message_vision("老和尚开始向$N讲解佛法的道理....\n", me);
        if((int)me->query("bellicosity") > 0 ) {
                me->add("bellicosity",-(int)me->query("bellicosity") / 10);
                me->start_busy(1);
                tell_object(me, "你听完老和尚的讲解，心中似乎一片祥和。\n");
                tell_object(me, "你的杀气降低了！\n");
                command( "nod " + me->query("id") );
                return "阿弥陀佛，善哉，善哉！";
        }
        else {
                command( "hehe" );
                return "这位" + RANK_D->query_respect(me) + "一心向善，好人终有好报。";
        }
}

string ask_me2()
{
        object me;

        me = this_player();

        message_vision("老和尚开始向$N讲解佛法的道理....\n", me);
        if( sizeof( me->query_killer() ) ) {
                tell_object(me, "你听完老和尚的讲解，心中似乎一片祥和。\n");
                tell_object(me, "你忘记了所有的仇家！\n");
                me->remove_all_killer();
                command( "nod " + me->query("id") );
                return "阿弥陀佛，善哉，善哉！";
        }
        else {
                command( "hehe" );
                return "杀人是空，屠刀亦是空。";
        }
}
