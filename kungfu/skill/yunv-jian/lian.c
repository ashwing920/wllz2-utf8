// lian.c
// 连字诀

#include <ansi.h>

inherit F_SSERVER;

string *per_msg = ({
	"雁行斜击，白虹惊天\n",
	"浪迹天涯，花前月下\n",
	"来去何从，清饮小酌\n",
	"扫雪煮茶，抚琴按箫\n",
	"松下对弈，池边调鹤\n",
	"柳絮风飘，小园艺菊\n",
	"西窗夜话，柳荫联句\n",
	"竹帘临池，木兰射雁\n",
	"双蝶迷回，孤云出釉\n",
	"幽兰空谷，茶花满路\n",
	"陌路采桑，秋雨萧萧\n",
	"琴心剑胆，池塘秋夜\n",
	"皓腕玉镯，牡丹含泪\n",
	"芍药蕴珠，檐前飞燕\n",
	"蒹葭苍苍，玉女素心\n",
});
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i,lvl,attack_time;
	
	lvl = (int)me->query_skill("yunv-jian",1);
	if( lvl <= 150) attack_time = 6;
	if( lvl <= 250 && lvl > 150 ) attack_time = 8;
	if( lvl <= 350 && lvl > 250 ) attack_time = 10;
	if( lvl > 350 ) attack_time = 12;


	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「连字诀」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if(me->query("family/family_name") != "古墓新派")
		return notify_fail("你不是古墓派弟子，连字诀这门决计来路不明，无法使用。\n");
	if((int)me->query_per() < 30)
		return notify_fail("你的魅力还不够, 目前还不能使用这项绝技！\n");
	if((int)me->query_skill("force",1) < 150)
		return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");
	if((int)me->query_skill("yunv-jian",1) < 150)
		return notify_fail("你的剑法修为不够，目前不能使用连字诀！\n");
	if((int)me->query_skill("yunv-xinfa",1) < 150)
		return notify_fail("你的玉女心法修为不够，目前不能使用连字诀！\n");
	if( (int)me->query("neili") < 400)
		return notify_fail("你的内力不够！\n");

	me->clean_up_enemy();
	msg = HIM "$N黯然神伤，梨花带泪，瞬间剑法陡然增快，附和着一声低吟，$n只觉得数道剑气迎面而来！\n" NOR;
	message_vision(msg, me,target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
		msg = HIR "$p只觉得$P的攻势中，夹带着无限的哀愁，猛然醒悟，早已被攻了个措手不及！\n" NOR;
		message_vision(msg + NOR, me,target);       
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		msg = MAG"\n\n$N轻声低吟：";
		msg += per_msg[random(sizeof(per_msg))];
		message_vision(msg + NOR, me,target);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);
	}else break;
		me->add("neili", -400);
		me->start_busy(4);
	}
	else {
		msg = HIG"$p轻身闪开，显然早已看穿了$P的来路。\n" NOR;
		message_vision(msg, me,target);
		me->start_busy(5);
	}
	return 1;
}
