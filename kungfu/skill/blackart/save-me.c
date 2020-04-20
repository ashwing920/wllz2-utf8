// save-me.c

#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_GUARD 6
int scribe(object me, object sheet)
{
        object newsheet;
        int t;

        if((int)me->query_skill("blackart") < 90 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" ) 
                return notify_fail("天师符要画在桃符纸上！\n");

        if( (int)me->query("jingli") < 75 ) 
                return notify_fail("你的法力不够了！\n");

        t = (int)sheet->query_amount();
        if( t == 1 ) destruct(sheet);
        else sheet->set_amount(t - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/clone/misc/magic_seal");
        newsheet->set_name(YEL "天师符" NOR, ({ "save-me sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("jingli", -75);
        me->receive_damage("jing", 10);
        me->save();
        message_vision("$N写了一道天师符。\n" NOR, me);
        return 1;
}

int do_burn(object sheet)
{ 
        object soldier, me;
        int spells;

        me = this_player();
        if( !me->is_fighting() )
                return notify_fail("没有人要杀你！\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("你已经召唤太多天兵鬼卒了！\n");
        message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() +
                "着了起来！\n", this_player());
        me->receive_damage("jing", 20);
        if( random(me->query("jingli")) < 200 ) {
                message("vision", "但是什麽也没有发生。\n", environment(me));
                return 1;
        }
        spells = me->query_skill("scratching");
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/clone/npc/heaven_soldier");
        else
                soldier = new("/clone/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        me->remove_all_killer();
        message_vision(HIB "\n$N躲在$n的背后喊道：给我杀！\n" NOR, me, soldier );
        message_vision(HIB "\n$n替$N挡住了所有敌人的攻击！\n" NOR, me, soldier );
        return 1;
}
