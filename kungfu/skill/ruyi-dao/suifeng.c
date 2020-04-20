#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me,int amount);

int perform(object me)
{
	object weapon;
	int skill;

	if( !me->is_fighting() )
		  return notify_fail("随风起舞式只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 300  )
		return notify_fail("你的内力不够。\n");

	if((int)me->query_temp("suifeng"))
		return notify_fail("你已经在舞动随风起舞式了。\n");

	if((int)me->query_skill("blade") < 120)
		return notify_fail("你的刀法修为不够， 目前不能舞动随风起舞式！\n");

	skill = (int)me->query_skill("ruyi-dao",1);

	if(skill < 250)
		return notify_fail("你的如意刀还不够娴熟，不能舞动随风起舞式！\n");

	if((int)me->query_skill("beiming-shengong",1) < 250)
		return notify_fail("你的北冥神功修为不够，无法舞动随风起舞式！\n");

	me->add("neili", -300);
	message_vision( HIR "只见狂风突起，$N深吸一口气，舞动随风起舞式，结果四周飘起越来越多的树叶！\n" NOR, me);
	me->set_temp("suifeng", 1);
	me->add_temp("str",skill / 20);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me,skill/20:), skill/3);
	if(me->is_fighting()) me->start_busy(2);
	return 1;
}

void remove_effect(object me,int amount)
{
	if(!me) return;
	if(me->query_temp("suifeng")){
		me->add_temp("str", - amount);
		me->delete_temp("suifeng");
		tell_object(me, CYN"你的随风起舞式舞动完毕，周围落叶撒满一地。\n"NOR);
	}
}