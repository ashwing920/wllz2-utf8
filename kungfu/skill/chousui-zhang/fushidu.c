// 腐尸毒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{

	object co;

	if( !target ) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !target->is_fighting(me))
		return notify_fail("「腐尸毒」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「腐尸毒」！\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 220 )
		return notify_fail("你的星宿毒掌还不够娴熟，使不出「腐尸毒」绝技。\n");

	if( (int)me->query_skill("huagong-dafa",1) < 120 )
		return notify_fail("你的化功大法修为不够，不能使用「腐尸毒」。\n");

	if((int)me->query_skill("poison",1)<120)
		return notify_fail("你积毒不够无法使用腐尸毒。\n");

	co=present("corpse",me);
	if (!objectp(co))
		return notify_fail("你身上没有尸体，如何使用腐尸毒！\n");

	if((string)me->query_skill_mapped("strike") != "chousui-zhang")
		return notify_fail("你现在无法使用「腐尸毒」！\n");

	if((int)me->query("max_neili") < 1200)
		return notify_fail("你内力太弱，使不出「腐尸毒」。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你现在真气太弱，使不出「腐尸毒」。\n");

	me->clean_up_enemy();
	message_vision(BLU"\n$N一声阴笑，右手突出，挟起一具尸体掷出，一股死鱼烂肉的臭气弥漫四周，闻者欲呕！\n"NOR,me);
	call_out("destroying", 1, co);
	me->add("neili", -250);
	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/ 2
	&& random((int)me->query_str()) > (int)target->query_str()/3*2 ) {
		message_vision(HIB"\n$n见此怪异的招数，手足无措，躲闪无及，只见散发着恶臭的尸体，正击在自己身上。\n"NOR, me, target);
		target->set_temp("die_for","腐尸毒入脑而死了！");
		target->set_temp("last_damage_from",me);
		target->unconcious();
		return 1;
	}
	else if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/4
	&& (int)me->query_str() > (int)target->query_str()/2) {
		message_vision(HIB"\n$n见事不好，连忙纵身直起，腐尸从身下掠过，没有打中。\n"NOR,me,target);
		tell_object(target,HIB"\n 你虽然及时避开了毒尸，但一股腥臭气入鼻，你已中了剧毒了。\n"NOR);
		target->apply_condition("fs_poison", random(3) + ((int)me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
		me->start_busy(5);
		target->start_busy(1);
		return 1;
	}
	message_vision(HIB"\n$n 胸有成竹，一声长啸，双掌连环劈出，把毒尸毒气荡向来路。\n"NOR,me,target);
	tell_object(me,HIB"\n不好，毒尸反弹向你,你虽然躲开，但毒气也侵入你的身体。\n"NOR);
		me->apply_condition("fs_poison", random(3) + ((int)me->query_skill("poison", 1)/10) + me->query_condition("xx_poison"));
		return 1;
	}

void destroying(object obj)
{
	destruct(obj);
	return;
}
