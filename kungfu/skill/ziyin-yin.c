// zhengqijue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( me->query("gender") != "女性" )
		return notify_fail("女人才适合修炼这种功夫。\n");
	return 1;
}

int practice_skill(object me)
{	
	 return notify_fail("紫氤氤只能靠学(learn)来提高。\n");
}
void skill_improved(object me)
{
	tell_object(me, HIR "你心里鼓荡着一股侠义之气！\n" NOR );
	me->add("shen",(int)me->query_skill("ziyin-yin",1));
}
