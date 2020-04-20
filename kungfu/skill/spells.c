// spells.c - 基本咒术

#include <ansi.h>

inherit SKILL;

void skill_improved(object me)
{
	if (me->query_skill("spells",1)%10==0) {
		tell_object(me, HIW "由於你勤练仙术，你的福缘提高了。\n" NOR);
	}
}

