//fushe.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("腹蛇", ({ "fu she", "she", "fu" }) );
        set("race", "蛇类");
        set("age",10);
        set("long", "只见它全身血红，头呈三角，长蛇吞吐，嗤嗤做响。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("cor", 20);
        set("eatable",1);
        set("afterdie","/d/shenlong/obj/shedan");
        set("combat_exp", 30000+random(50000));
        set_temp("apply/attack", 20+random(10));
        set_temp("apply/damage", 10+random(10));
        set_temp("apply/armor", 15+random(10));
        set_temp("apply/defence",20+random(10));
        setup();
}
void init()
{
        object me,ob;
        if (interactive(me = this_player())){
        if( me->query("mud_age") < 345600) return;
        if (!(ob = present("xionghuang", this_player())))
                   {
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 1, me);
                }
        }
}

int hit_ob(object me, object ob, int damage)
{
        if ((int)ob->query("combat_exp") > 100000) return 1 ;
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 20 ) {
                ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
        }
}