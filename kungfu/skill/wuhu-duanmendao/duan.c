#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i,lvl,attack_time;

        lvl = (int)me->query_skill("wuhu-duanmendao",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl <= 250 && lvl > 150 ) attack_time = 6;
        if( lvl <= 350 && lvl > 250 ) attack_time = 8;
        if( lvl > 350 ) attack_time = 12;
 
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
               return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili") < 200)
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("blade",1) < 150)
                return notify_fail("你的刀法还不到火候，不能使用五虎断门刀！\n");
                
        if( (int)me->query_skill("wuhu-duanmendao",1) < 150)
                return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

        msg = HIY "$N猛然伏地，使出断魂刀断字决，顿时一片白光直向前滚去！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
        
        msg=HIY"$N吸气运功，在将把刀光缓缓收回！\n\n"NOR;
        message_vision(msg, me);
       
        me->add("neili", -200);
        me->start_busy(3);

        return 1;

}
                                                                              