// jingsng.c 金刚拳 大金刚神通

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object ob;	
	string msg;
	int d_count, count, qi, maxqi, skill;

	if(!me->is_fighting())
		return notify_fail("「大金刚神通」只能在战斗中使用。\n");
	if((int)me->query("neili") < 300)
		return notify_fail("你的内力还不够高！\n");
	if( (int)me->query_skill("hunyuan-yiqi", 1) < 120)
		return notify_fail("你的混元一气功的修为不够，不能使用大金刚神通! \n");
	if( (int)me->query_skill("cuff",1) < 120 )
		return notify_fail("你的拳法还不到家，无法使用大金刚神通！\n");
	if( me->query_skill_mapped("cuff") != "jingang-quan") 
		return notify_fail("你没有激发金刚拳，无法使用大金刚神通！\n");
	
	msg = HIY "$N使出大金刚拳的绝技「大金刚神通」，臂力陡然增加！\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("jingang-quan",1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4)){	
	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"你已经在运功中了。\n");
		message_vision(msg, me, target);
		me->add_temp("str", count * 2);	
		me->add_temp("dex", 0-d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -300);
		return 1;
	}
	else{
		msg = HIR "$N拼尽毕生功力使出了大金刚拳的终极绝技, 全身骨骼一阵爆响, 欲与敌人同归于尽！\n" NOR;
		message_vision(msg, me, target);
		me->add_temp("str", count * 9);
		me->set_temp("jingang", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);

		ob = me->select_opponent();
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		me->set("neili",0);

		msg = HIR "$N用尽了最后一点气力, 喷出一口鲜血, 一头栽倒在地!\n" NOR;
		message_vision(msg, me, target);
		me->set("jing",0);
		me->set("qi",0);
		me->unconcious();
		return 1;
	}
}

void remove_effect(object me, int aamount, int damount)
{
	
	if(!me) return;
	if((int)me->query_temp("jingang") ) {
	me->add_temp("str", -aamount);
	me->add_temp("dex", damount);
	me->delete_temp("jingang");
	tell_object(me, HIY "你的大金刚神通运行完毕，将内力收回丹田。\n" NOR);
	}
}

int clean_up()
{
	return 1;
}
void reset()
{
}
