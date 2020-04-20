// sanjue.c  达摩剑 [达摩三绝剑]

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i;
 
	if( !me->is_fighting() )
		return notify_fail("「达摩三绝剑」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_dex() < 30)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技！\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("你的混元一气功的修为不够, 不能使用这一绝技 !\n");

	if((int)me->query_skill("dodge",1) < 120)
		return notify_fail("你的轻功修为不够, 不能使用达摩三绝剑！\n");
 
	if((int)me->query_skill("sword",1) < 120)
		return notify_fail("你的剑法修为不够， 目前不能使用达摩三绝剑！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");


	msg = HIG "$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	for(i = 0; i < 3; i++)
		if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);
	}else break;
	
	me->add("neili", - 200);
	me->start_busy(3);

	return 1;
}
