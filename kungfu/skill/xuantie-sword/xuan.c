// xuan.c
// 玄冰剑掌

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

string *per_msg = ({
        "赵客缦胡缨，吴钩霜雪明\n",
        "银鞍照白马，飒沓如流星\n",
        "十步杀一人，千里不留行\n",
        "事了拂衣去，深藏身与名\n",
        "闲过信陵饮，脱剑膝前横\n",
        "三杯吐然诺，五岳倒为轻\n",
        "眼花耳热后，意气素霓生\n",
        "救赵挥金锤，邯郸先震惊\n",
        "千秋二壮士，洹赫大梁城\n",
        "纵死侠骨香，不惭世上英\n",
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i,lvl,attack_time;

        lvl = (int)me->query_skill("xuantie-sword",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl <= 250 && lvl > 150 ) attack_time = 6;
        if( lvl <= 350 && lvl > 250 ) attack_time = 8;
        if( lvl > 350 ) attack_time = 12;


        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「玄冰剑掌」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if((int)me->query_dex() < 30)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技！\n");
        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");
        if((int)me->query_skill("xuantie-sword",1) < 150)
                return notify_fail("你的剑法修为不够，目前不能使用玄冰剑掌！\n");
        if((int)me->query_skill("xiantian-qigong",1) < 150)
                return notify_fail("你的先天气功修为不够，目前不能使用玄冰剑掌！\n");
        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        me->clean_up_enemy();
        msg = HIW "$N使出玄铁剑法中的绝技「"HIR"玄冰剑掌"HIW"」，数道剑气与无数个掌影一并向$n袭去！\n" NOR;
        message_vision(msg, me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
                msg = CYN "结果$p被$P攻了个措手不及！\n" NOR;
                message_vision(msg, me,target);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                msg = HIY"\n\n$N默念口诀：";
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
                msg = HIC"$p轻身闪开，躲避了$P凶猛的招式。\n" NOR;
                message_vision(msg, me,target);
                me->start_busy(5);
        }
        return 1;
}
