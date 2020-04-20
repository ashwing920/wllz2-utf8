// scored.c 

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

void set_score(object me)
{
	if (me->query("betrayer")){
		if (me->query("score") >=10000) {
			me->set("betrayer",0);
			me->add("weiwang",100);
			tell_object(me, sprintf(HIY"由于你对门派忠心耿耿，人们忘记了你以前叛师的历史！\n"NOR));
			tell_object(me,HIC"\n"+ me->query("family/family_name")+"奖励了你江湖威望一百点。\n\n\n"NOR);
			
		}

		if (me->query("score")==5000) {
			me->add("betrayer",-1);
			tell_object(me, sprintf(HIR"由于你对门派忠心耿耿，人们减少了对你以前叛师的疑虑！\n"NOR));                	
			tell_object(me,HIC"\n你的江湖威望也随之提高了。\n\n"NOR);			
			me->add("weiwang",10);
		}		
		
		}

	return;	
}