// necromancy.c - 天师道术

#include <ansi.h>

inherit SKILL;

string type() { return "martial"; }

int valid_enable(string usage) { return usage == "spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism") < (int)me->query_skill("blackart") / 2 )
		return notify_fail("你的道家学说修为不够，无法领悟更高深的茅山术。\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return __DIR__"blackart/" + spell;
}

string scribe_spell_file(string spell)
{
	return __DIR__"blackart/" + spell;
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的" + bug->name() + "吧！\n");

	if( (int)me->query("jingli") < 10 )
		return notify_fail("你的精力不够。\n");

	if( (int)me->query("jing") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("jingli", -10);
	me->receive_damage("jing", 30);

	write("你闭目凝神，神游物外，开始修习天师道术中的法术....\n");
	if( random((int)me->query("jing")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/clone/npc/mind_bug");
		else bug = new("/clone/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail(HIY "你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n" NOR);
	}	
	else return 1;
}
