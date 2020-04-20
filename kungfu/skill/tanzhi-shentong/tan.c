// tan.c 弹射

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, num, lvl, p;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("你只能在战斗中对对手进行弹射。\n");

	lvl = (int)me->query_skill("tanzhi-shentong", 1);

	if(lvl < 200) 
		return notify_fail("你的弹指神通不够娴熟，无法进行弹射。\n");

	if((int)me->query_skill("bibo-shengong",1) < 200) 
		return notify_fail("你的弹指神通不够娴熟，无法进行弹射。\n");

	if(!objectp(weapon = me->query_temp("weapon"))) 
		return notify_fail("你必须装备暗器才能进行弹射。\n");

	if((num = weapon->query_amount()) < lvl / 20) 
		return notify_fail("你掏了掏背囊，发现里面的暗器已经不够了！\n");

	if((int)me->query("neili") < 450)
		return notify_fail("你的内力不够，无法进行弹射。\n");

	me->clean_up_enemy();

	msg = HIW"$N双手在背囊里一抓，抓出" + CHINESE_D->chinese_number(lvl / 20) + weapon->query("base_unit") + weapon->query("name") + HIW"来，运用指力朝$n弹了出去。\n"NOR;

	damage = lvl * 2 + (int)me->query_skill("bibo-shengong", 1);
	damage += random(damage);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
		msg += HIR"$n躲闪不及，“噗噗”地几声，被几道暗器击中！\n"NOR;
		target->receive_damage("qi",damage/3,me);
		target->receive_wound("qi",damage/2,me);
		p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += "「$n" + eff_status_msg(p) + "」\n";
	} 
	else {
		msg += HIC"$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -350);
	me->start_busy(3);
	if (num == lvl / 20) {
		weapon->unequip();
		tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n");
	}
	weapon->add_amount(-(lvl/20));
	return 1;
}
