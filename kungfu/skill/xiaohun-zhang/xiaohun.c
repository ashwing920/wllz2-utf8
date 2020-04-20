// xiaohun.c 黯然消魂

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

string *pictures = ({
        "心惊肉跳","杞人忧天","无中生有","拖泥带水","徘徊空谷","力不从心","行尸走肉", "庸人自扰"
});
 
int perform(object me, object target)
{
        object ob;
        string msg,picture;
        int i;
        picture = pictures[random(sizeof(pictures))];

        if( !me->is_fighting())
                return notify_fail("「黯然消魂」只能在战斗中使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("你必须空手才可以使出黯然消魂！\n");
                
        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("xiaohun-zhang",1) < 120 )
                return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");

        if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("你的内功修为不够，无法使用「黯然消魂」！\n");

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = HIW"$N心想今日身陷绝境已然无幸，万念俱灰，凄意之中无意拍出了黯然消魂掌中的「"+ picture +"」！\n" NOR;
        msg += HIW"但见掌风激荡，恍恍惚惚的向$n袭去！\n"NOR;
        message_vision(msg, me,ob);
        for(i = 0; i < 5; i++)
                if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
                me->set_temp("action_flag",0);
        }else break;
        me->add("neili", -300);
        me->start_busy(random(4) +1);

        return 1;

}
