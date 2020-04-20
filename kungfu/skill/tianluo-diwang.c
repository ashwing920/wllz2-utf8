// tianluo-diwang.c 天罗地网势

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("tianluo-diwang", 1);
        
        if( (int)me->query_dex() < 20 )
                return notify_fail("你的身法太差不能学习古墓派的武功。\n");
                
        if( (int)me->query_int() < 26 )
                return notify_fail("你的悟性太差不适合学习古墓派的武功。\n");

        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("天罗地网势只能通过练习(lianxi)来增加熟练度。\n");
}
