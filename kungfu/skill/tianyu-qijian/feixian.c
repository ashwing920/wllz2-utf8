// lian.c
// 天外飞仙

#include <ansi.h>

inherit F_SSERVER;

string *per_msg = ({
        "海天一线，闪电惊虹",
        "日在九天，咫尺天涯",
        "怒剑狂花，九弧震日",
        "漫天风雪，天河倒泻",
        "天外飞仙，星河鹭起",
        "歌尽桃花扇底风",
        "扫尽浮云风不定",
        "万顷江田一鹭飞",
        "流水落花春去也",
        "月轮穿沼水无痕",
        "月在青天影在波",
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i,lvl,attack_time;

        lvl = (int)me->query_skill("tianyu-qijian",1);
        if( lvl <= 150) attack_time = 8;
        if( lvl <= 250 && lvl > 150 ) attack_time = 10;
        if( lvl <= 350 && lvl > 250 ) attack_time = 12;
        if( lvl > 350 ) attack_time = 16;


        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「天外飞仙」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if(me->query("family/family_name") != "灵鹫宫")
                return notify_fail("你不是灵鹫宫弟子，天外飞仙这门绝技来路不明，无法使用。\n");

        if((int)me->query_per() < 32)
                return notify_fail("你的魅力还不够, 目前还不能使用这项绝技！\n");

        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");

        if((int)me->query_skill("tianyu-qijian",1) < 150)
                return notify_fail("你的剑法修为不够，目前不能使用天外飞仙！\n");

        if((int)me->query_skill("bahuang-gong",1) < 150)
                return notify_fail("你的八荒六合神功修为不够，目前不能使用天外飞仙！\n");

        if((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够，无法使用天外飞仙！\n");

        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        me->clean_up_enemy();
        msg = HIM "$N运起天羽奇剑中的精髓「"HIW +per_msg[random(sizeof(per_msg))]+HIM"」，手中"+ weapon->name() +HIM"即刻荡起数道剑花，顿时花瓣飞舞！\n" NOR;
        message_vision(msg, me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
                msg = HIR "$p立刻沉浸在一片飘渺，缤纷的世界，回过神来，却早已经陷入$P的攻势之中！\n" NOR;
                message_vision(msg + NOR, me,target);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                msg = MAG"\n\n$N攻势越来越快，口中低声吟唱：";
                msg += per_msg[random(sizeof(per_msg))];
                message_vision(msg +"\n"NOR, me,target);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
                me->add("neili", -400);
                me->start_busy(4);
        }
        else {
                msg = HIG"$p急速跳开数丈，显然对$P的攻势早已了解得一清二楚。\n" NOR;
                message_vision(msg, me,target);
                me->start_busy(5);
        }
        return 1;
}
