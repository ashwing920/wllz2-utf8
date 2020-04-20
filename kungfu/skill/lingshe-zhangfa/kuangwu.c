  //kuangwu.c 魔蛇狂舞

#include <ansi.h>

inherit F_SSERVER;

string *per_msg=({
	HIR"\n魔\n"NOR,
	HIY"\n蛇\n"NOR,
	HIB"\n狂\n"NOR,
	MAG"\n舞\n"NOR,
	HIR"\n魔\n"NOR,
	HIY"\n蛇\n"NOR,
	HIB"\n狂\n"NOR,
	MAG"\n舞\n"NOR,
});
int perform(object me, object target)
{
        object weapon;
        int i;
        string msg;

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character()|| !me->is_fighting(target))
              return notify_fail("「魔蛇狂舞」只能在战斗中使用！\n");

        if(!me->is_fighting())
              return notify_fail("「魔蛇狂舞」只能在战斗中使用！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa"
        || me->query_skill_mapped("force") !="hamagong")
                return notify_fail("你现在无法使用魔蛇狂舞。\n");

        if((int)me->query_skill("lingshe-zhangfa", 1) < 150)
                return notify_fail("你的灵蛇杖法等级不够，无法使用魔蛇狂舞！\n");

        if((int)me->query_skill("hamagong", 1) < 150)
                return notify_fail("你的蛤蟆功等级不够，无法使用魔蛇狂舞！\n");

        me->clean_up_enemy();

        weapon=me->query_temp("weapon");
        message_vision(HIY"\n$N将蛤蟆功凝于气海穴，口中发出「咕、咕」的声音......\n"NOR, me);
        message_vision(HIB"\n突然只见$N使出灵蛇杖法最后一招魔蛇狂舞！\n"NOR, me);
	for(i = 0; i < 4; i++)
	if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		msg = per_msg[random(sizeof(per_msg))];
		message_vision(msg + NOR, me,target);
        	if (!weapon->query("equipped")) break;
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        	me->set_temp("action_flag",0);
        }else break;
        message_vision(HIW"\n$N趁内力回归丹田之前奋力又发数招！\n"NOR, me, weapon);
	for(i = 0; i < 4; i++)
	if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("action_flag",0);
	}else break;

        message_vision(HIC"\n$N无法控制内息流动，只好后跃收招。\n"NOR, me, weapon);
        me->add("neili", -300);
        me->start_busy(4);
        return 1;
}
