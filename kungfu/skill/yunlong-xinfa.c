// yunlong-xinfa.c 云龙心法

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage == "force"; }

int practice_skill(object me)
{	
	return notify_fail("云龙心法只能靠学(learn)来提高。\n");
}
