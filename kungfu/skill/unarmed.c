// unarmed.c

#include <ansi.h>

inherit SKILL;

void skill_improved(object me)
{

	if (me->query_skill("unarmed",1)%10==0) {
		tell_object(me, HIW "由於你勤练武艺，你的膂力提高了。\n" NOR);
	}
}