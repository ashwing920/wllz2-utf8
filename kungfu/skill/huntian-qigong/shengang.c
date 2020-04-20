// shengang.c 混天气功混天神罡

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        string msg;
        int d_count, count, qi, maxqi, skill;

        if(target != me) 
                return notify_fail("你只能对自己运用「混天神罡」。\n");

        if( (int)me->query_temp("shengang") ) 
                return notify_fail("你已经在运混天神罡了。\n");

        if( !me->is_fighting() )
                return notify_fail("「混天神罡」只能在战斗中使用。\n");

        if( (int)me->query("neili") < 200)
                return notify_fail("你的内力不够！\n");

        if( (int)me->query_skill("force",1) < 100)
                return notify_fail("你的基本内功的修为不够，不能使用混天神罡！\n");

        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("huntian-qigong",1) / 3);
        count = me->query_str();
        d_count = (int)me->query_dex() / 2;

        if(qi > (maxqi * 0.4))
        {       
                msg = HIY "$N使出混天气功「混天神罡」，将真气贯注到手心！\n" NOR;
                me->add_temp("apply/damage", skill*2);
                me->set_temp("shengang", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);
                me->add("neili", -(int)me->query("max_neili")/ 20);
        }
        else{
                msg = HIR "$N拼尽毕生功力想提起混天神罡，但自己受伤太重，没能成功！\n" NOR;
        }
        
        message_vision(msg, me);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        if((int)me->query_temp("shengang") ){
        me->add_temp("apply/damage", - amount);
        me->delete_temp("shengang");
        tell_object(me, HIY "你的混天神罡运行完毕，将内力收回丹田。\n" NOR);
        me->start_busy(random(4));
        }
}
int clean_up()
{
        return 1;
}
void reset()
{
}
