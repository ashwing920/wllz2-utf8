// suoming.c 五毒索命掌
#include <ansi.h>

inherit F_SSERVER;
int check_armor(object target);

int perform(object me, object target)
{
	string msg;
	int damage,i;
	object *inv;

	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character()	||  !me->is_fighting(target) )
		return notify_fail("五毒索命掌只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用五毒索命掌！\n");

	if( me->query("jiali") <= 0)
		return notify_fail("你的加力太弱，无法使用五毒索命掌！\n");

	if( (int)me->query_skill("wudu-zhang", 1) < 150)
		return notify_fail("你的五毒掌法还不够娴熟，无法五毒索命掌。\n");

	if( (int)me->query_skill("wudu-xinfa", 1) < 150)
		return notify_fail("你的五毒心法还不够娴熟，无法五毒索命掌。\n");

	if( (int)me->query_skill("wudu-shengong", 1) < 150)
		return notify_fail("你的五毒神功还不够娴熟，无法五毒索命掌。\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法使用五毒索命掌。\n");

	if( (int)me->query("neili", 1) < me->query("jiali"))
		return notify_fail("以你的目前的内力没有办法发出五毒索命掌。\n");

	if((string)me->query_skill_mapped("force") != "wudu-shengong")
		return notify_fail("你没有激发五毒神功，五毒索命掌将毫无威力。\n");

	msg = MAG"\n$N运起五毒神功，将全身内力逼于掌中，双掌顿时泛起一道紫气，猛的向$n的胸口拍去！\n";

	if ((random(me->query_skill("force")) > target->query_skill("force")/3)){
		me->add("neili",- (int)me->query("jiali") * 3);
		damage = (int)me->query_skill("wudu-zhang", 1);
		damage += random(damage) + ((int)me->query("jiali") * 3);

	if(check_armor(target) >= 1
	&& random(damage) > target->query("apply/armor")
	&& me->query("neili") > target->query("neili")*2
	&& me->query_str() > random(target->query_str())){
		inv = all_inventory(target);
			me->start_busy(3);
			msg += HIY"\n猛烈间“砰”的一阵剧响，$P掌心正中$p的胸口，震碎了$p的护具！\n\n" NOR;
			for(i=0; i<sizeof(inv); i++)
			if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
			inv[i]->unequip();
			inv[i]->move(environment(target));
			inv[i]->set("name", "粉碎的" + inv[i]->query("name"));
			inv[i]->delete("value");
			inv[i]->set("no_get",1);
			inv[i]->set("armor_prop", 0);
		}
	}
		else {
			me->start_busy(4);
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi", damage / 2,me);
			msg += RED"\n$n闪躲不及，被$N的掌风击中，「哇」的吐出一口鲜血！胸口留下了一双熏黑的掌印！\n\n"NOR;
		}
	}
	else
		{
			me->start_busy(5);
			target->start_busy(1);
			msg += HIW"$n强运内功，掌心与$N碰在一起，发出“砰”的一声巨响！\n"NOR;
			if( target->query("neili") >= 300) target->add("neili",-300);
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target);
	return 1;
}
int check_armor(object target)
{
	object *inv;
	int i, j;
	inv = all_inventory(target);
	j=0;
	for(i=0; i<sizeof(inv); i++)
	if( (string)inv[i]->query("equipped")=="worn" ) j++;
	return j;
}