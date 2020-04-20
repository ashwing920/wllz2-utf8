// thunderbolt.c

#include <ansi.h>

inherit F_SSERVER;

int thunderbolt(object me, object obj)
{
        int kar,damage,spells;

        message_vision(YEL "\n一个闪电向$N的头上打来，\n" NOR, obj);
        obj->receive_damage("jing", 0, me);
        
        if(obj->is_ghost()==1) {
                message_vision(RED "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()==1) {
                message_vision(RED "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
                obj->die();
                return 1;
        }

        spells = me->query_skill("spells");

        if(obj->query("race")=="野兽") {
                kar = obj->query("kar");
                damage = (31 - kar)*(spells/4)*(random(31-kar)+1)+100;
                if(damage <= 20) damage = 0;
                if(damage > 7500) damage = 7500;
                if(damage != 0) {
                        message_vision(RED "正打在了$N的头上！\n" NOR, obj);
                        obj->receive_damage("qi", damage, me);
                        COMBAT_D->report_status(obj);
                        if( !obj->is_fighting(me) ) {
                                me->kill_ob(obj);
                                if( living(obj) ) {
                                        if( userp(obj) ) 
                                                obj->fight_ob(me);
                                        else
                                                obj->kill_ob(me);
                                }
                        }
                } else 
                        message_vision(RED "但被$N躲过了！\n" NOR, obj);
                return 1;
        }

        kar = obj->query("kar");
        damage = (31 - kar)*(spells/4)*(random(30-kar)+1);
        if(damage <= 20) damage = 0;
        if(damage > 5000) damage = 5000;
        if(damage != 0 && random(kar) < 20) {
                message_vision(RED "正打在了$N的头上！\n" NOR, obj);
                obj->receive_damage("qi", damage, me);
                COMBAT_D->report_status(obj);
                if( !obj->is_fighting(me) ) {
                        me->kill_ob(obj);
                        if( living(obj) ) {
                                if( userp(obj) ) 
                                        obj->fight_ob(me);
                                else
                                        obj->kill_ob(me);
                        }
                }
        } else 
                        message_vision(RED "但被$N躲过了！\n" NOR, obj);
        return 1;
        
}

int cast(object me)
{
        string  msg;
        object  env;
        object  *inv;
        int     i;

        if((int)me->query_skill("spells") < 200 )
                return notify_fail("你的法术不够高！\n");

        if((int)me->query("jingli") < 200 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("qi") < 100 )
                return notify_fail("你的体力不够！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("jingli", -200);
        me->receive_damage("jing", 90);

        msg = YEL "$N脚踩天罡步，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
        msg = msg + RED "猛地双手一挥，天上打下无数闪电！\n\n" NOR;
        message_vision(msg, me);
        env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
                thunderbolt(me, inv[i]);
        }
        me->start_busy(5);
        return 1;
}

