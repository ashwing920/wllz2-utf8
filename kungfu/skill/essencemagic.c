// essencemagic.c - 八识神通

inherit SKILL;

string type() { return "martial"; }

int valid_enable(string usage) { return usage == "magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism") < 10
        ||  (int)me->query_skill("lamaism") <= (int)me->query_skill("essencemagic") )
                return notify_fail("你的密宗心法修为还不够高深，无法学习八识神通。\n");
	
	if((string)me->query("family/family_name") != "雪山寺")
		return notify_fail("非雪山寺弟子，不能学习八识神通。\n");
        return 1;
}

string conjure_magic_file(string spell)
{
        return __DIR__"essencemagic/" + spell;
}

int enable_factor() { return 200; }

int learn_factor(int n) { 
   if (n<100) return 100;
   else return 80;
 }
int learn_bonus()  { return 1; }

int study_factor() { return 100; }
int study_bonus()  { return 1; }

int practice_factor() { return 90; }
int practice_bonus()  { return 1; }
