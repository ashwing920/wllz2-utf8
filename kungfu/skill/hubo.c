// hubo.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_research() { return 101; }
int valid_learn(object me) 
{
	if( (int)me->query("int") > 25 ) 
		return  notify_fail("你的天性不适合学习双手互博之术！\n" ) ;
	return 1;
}
