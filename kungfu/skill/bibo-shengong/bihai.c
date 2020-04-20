// 碧海潮生
// bihai

#include <ansi.h>

#include "/kungfu/skill/eff_msg.h"

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob,xiao;
	string msg;
	int i, skill, damage,p;

	if(environment(me)->query("no_fight") || environment(me)->query("fight_room"))
		return notify_fail("这里禁止战斗！\n");

	if(!objectp(xiao = present("yuxiao",me)))
		return notify_fail("你手中无萧，如何吹奏碧海潮生？\n");

	if((int)me->query("neili") < (int)me->query("max_neili") / 20)
		return notify_fail("你的内力不够。\n");
		
	if((int)me->query_skill("music",1) < 140)
		return notify_fail("你连五音十二律都没学好，更不用说吹奏碧海潮声了。\n");

	if((int)me->query_skill("bibo-shengong",1) < 140)
		return notify_fail("你的碧波神功的修为还不够，无法吹奏碧海潮生曲。\n");

	skill = (int)me->query_skill("force");

	me->add("neili", -(int)me->query("max_neili") / 20);
	me->receive_damage("qi", 10);

	if(!me->is_busy()) me->start_busy(5);

	message_vision(HIY"$N将箫凑到嘴边，幽幽咽咽的吹奏起“碧海潮生曲”来，曲调如泣如述，柔糜万端。\n"NOR,me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me )continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query_con()) continue;
		me->set_temp("first_kill/"+ob[i]->query("id"), 1);
		if( !ob[i]->is_killing(me->query("id")) ) ob[i]->fight_ob(me);
		if( !me->is_killing(ob[i])) me->fight_ob(ob[i]);
		damage = (skill + me->query_skill("music",1)) - ((int)ob[i]->query_skill("force") / 3);
		damage += random(damage);
		if( damage > 0 ) {
			msg = HIW"$n只觉得一股深厚的内劲犹如无数排山巨浪，迎面扑来 . . . . . .\n"NOR;
			if(random(me->query("max_neili")) > ob[i]->query("max_neili") / 4){
				msg += HIW"那股内劲直闯$n的体内，$n脸色一变，“哇”的一声吐出了一口鲜血。\n"NOR;
				ob[i]->receive_wound("jing",damage,me);
				p = (int)ob[i]->query("jing") * 100 / (int)ob[i]->query("max_jing");
				msg += "「$n" + eff_status_msg(p) + "」\n\n";
			}
			else {
				msg = HIC"\n哪知$n内功深厚，运气凝神，碧海潮生曲丝毫不觉任何威力。\n\n"NOR;
			}
		}
	message_vision(msg,me,ob[i]);
	}
	return 1;
}
