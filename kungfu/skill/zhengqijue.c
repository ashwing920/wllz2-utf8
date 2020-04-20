// zhengqijue.c

inherit SKILL;

#include <ansi.h>

string type() { return "knowledge"; }
string know() { return "shen_learn" ; }

int valid_learn(object me) 
{
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("正气诀只能靠学(learn)来提高。\n");
}
void skill_improved(object me)
{
	tell_object(me, HIR "你心里鼓荡着一股侠义之气！\n" NOR );
	me->add("shen", me->query_skill("zhengqijue",1));
	me->add("shen_learn",me->query_skill("zhengqijue",1));
}
