// force.c

#include <ansi.h>

inherit SKILL;

string exert_function_file(string func)
{
	return "/kungfu/skill/force/" + func;
}

void skill_improved(object me)
{
	if (me->query_skill("force",1)%10==0) {
		tell_object(me, HIW "由於你勤练内功，你的根骨提高了。\n" NOR);
	}	
}
