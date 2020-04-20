// transfer.c

#include <ansi.h>

int exert(object me, object target)
{
        int force;

        if( !target || target == me || !living(target) )
                return notify_fail("你要将真气传给谁？\n");

        if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
                return notify_fail(target->name() + "所使用的内功和你不同。\n");

        if( (int)me->query("neili") <= (int)me->query("max_neili") )
                return notify_fail("你的真气不足。\n");

        force = me->query("neili") - me->query("max_neili");

        if( force / 2 < 1 ) return notify_fail("你的真气不足。\n");

        me->add("neili", - force / 2 );

        message_vision("$N将手掌贴在$n背心，运气将体内真气传送过去。\n", me, target);

        if( random(force / 3) > (int)me->query_skill("force") )
                return notify_fail("你失败了。\n");

    	if(target->query("neili") > target->query("max_neili") * 20)
	{
	     tell_object(target, RED "你只觉一股内力在你体内乱窜，无法控制内息的流动！\n");
	     return notify_fail("你失败了。\n");
    	}

        target->add("neili", force / 3);
        tell_object(target, HIY "你觉得一股热气从" + me->name() + "的手掌传了过来。\n" NOR);
        write("你成功了。\n");

	// 修改：控制传内力不能超过10000
	if( target->query("neili") >= target->query("max_neili") * 2) {
		target->set("neili",target->query("max_neili") * 2);
	        tell_object(target, "你体内的内力太多啦。\n" );
	}

        return 1;
}
 
