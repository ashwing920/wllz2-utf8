// literate.c - 读书识字

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s;

        s = me->query_skill("literate", 1);
        if( s % 10 == 0 && (int)me->query("int") < 50 
        &&      (s / 10) > (int)me->query("int_increase")) {
                tell_object(me, HIW "由於你的勤学苦读，你的悟性提高了。\n" NOR);
        }
}
