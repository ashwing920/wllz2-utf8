#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	string msg;
	switch(random(5)){
	case 0 : 
		msg = WHT"$N突然脚下一滑，左脚踩住右脚，差点跌了个趔趄。\n"NOR;
		me->start_busy(3);
		break;
	case 1 : 
		msg = WHT"$N站都站不稳，不时“唉”的叹了一口气。\n"NOR;
		me->receive_damage("qi",200);
		me->receive_wound("qi", 150);
		break;
	case 2 : 
		msg = WHT"$N双目无神，心神不定，好像丢了什么！\n"NOR;
		if(me->query("neili") >= 250)
		me->add("neili",-250);
		break;
	default:
		msg = WHT"$N精神恍惚，心烦气燥。\n"NOR;
		me->receive_wound("jing",100);
      }
      message_vision(msg, me);      
      me->apply_condition("cuixin_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}
string query_type(object me)
{
	return "hurt";
}
