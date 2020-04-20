//  yufeng-shu.c 御蜂术

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("御蜂术只能靠学(learn)来提高。\n");
}
