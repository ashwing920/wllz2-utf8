
// bidu.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要为谁逼毒?！\n");
	if(target == me)
		return notify_fail("你要为谁逼毒?！\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功逼毒！\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为不够。\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 50)
		return notify_fail("你的先天神功修为还不够。\n");
	if( (int)me->query("neili") < 150) 
		return notify_fail("你的真气不够。\n");
	
	message_vision(HIY"$N"HIC"坐了下来运起内功，将手掌贴在$n的后背，缓缓地将真气输入$n的体内....\n" NOR,me,target);

	if ((int)target->query_condition("zm_poison") > 0 )
	{
	if ((int)target->query_condition("zm_poison") < (int)me->query_skill("xiantian-qigong",1)/20 + 1 )
	{
	target->apply_condition("zm_poison", 0);
	message_vision("$n身上的"HIR"子母飞针之毒"NOR"尽退，脸色看上去好多了。\n"NOR, me,target); 
	}
   else {
	target->apply_condition("zm_poison", (int)target->query_condition("zm_poison") -(int)me->query_skill("xiantian-qigong",1)/20 );
	message_vision("$n身上的"HIR"子母飞针之毒"NOR"清去小半脸色渐渐红润起来。\n"NOR, me,target);
	}
	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(4);   
	target->start_busy(4);
	 return 1;

   }
	if ((int)target->query_condition("ice_poison") > 0 )
	 {
	if ((int)target->query_condition("ice_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	target->apply_condition("ice_poison", 0);
	message_vision("$n身上的"HIR"寒冰绵掌"NOR"尽退，脸色看上去好多了。\n"NOR, me,target); 
	}
   else {
	target->apply_condition("ice_poison", (int)target->query_condition("ice_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision("$n身上的"HIR"寒冰绵掌"NOR"清去小半，脸色渐渐红润起来。\n"NOR, me,target);
	}
	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(4);   
	target->start_busy(4);
	return 1;

   }
	if ((int)target->query_condition("jy_poison") > 0 )
	 {
	if ((int)target->query_condition("jy_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	target->apply_condition("jy_poison", 0);
	message_vision("$n身上的"HIR"九阴白骨爪毒"NOR"尽退，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
	target->apply_condition("jy_poison", (int)target->query_condition("jy_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision("$n身上的"HIR"九阴白骨爪毒"NOR"清去小半，脸色渐渐红润起来。\n"NOR, me,target);
	}
	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(4);   
	target->start_busy(4);
	return 1;
	 }
	 
	if ((int)target->query_condition("xx_poison") > 0 )
	 {
	if ((int)target->query_condition("xx_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	target->apply_condition("xx_poison", 0);
	message_vision("$n身上的"HIR"星宿掌毒"NOR"尽退，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
	target->apply_condition("xx_poison", (int)target->query_condition("xx_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision("$n身上的"HIR"星宿掌毒"NOR"清去小半，脸色渐渐红润起来。\n"NOR, me,target);
	}
	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(4);   
	target->start_busy(4);
	 return 1;
	 }
   
	if ((int)target->query_condition("ss_poison") > 0 )
	 {
	if ((int)target->query_condition("ss_poison") < (int)me->query_skill("xiantian-qigong",1)/8+1 )
	
	{
	  target->apply_condition("ss_poison", 0);
	  message_vision("$n身上的"HIR"生死符"NOR"尽退，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("ss_poison", (int)target->query_condition("ss_poison") -(int)me->query_skill("xiantian-qigong",1)/8);
	  message_vision("$n身上的"HIR"生死符"NOR"清去小半，脸色渐渐红润起来。\n"NOR, me,target);
	}
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);   
	  target->start_busy(4);	  
	 return 1;
	 }
	  
	if ((int)target->query_condition("rose_poison") > 0 )
	 {
	if ((int)target->query_condition("rose_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("rose_poison", 0);
	  message_vision("$n身上的"HIR"火玫瑰毒"HIC"尽退，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("rose_poison", (int)target->query_condition("rose_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision("$n身上的"HIR"火玫瑰毒"HIC"清去小半，脸色渐渐红润起来。\n"NOR, me,target);
	}
	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(4);   
	target->start_busy(4);	  
	return 1;
	 }
 
	if ((int)target->query_condition("zhua_poison") > 0 )
	 {
	if ((int)target->query_condition("zhua_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("zhua_poison", 0);
	  message_vision(HIY"$n"HIY"身上的"HIR"凝血神爪"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("zhua_poison", (int)target->query_condition("zhua_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$n"HIY"身上的"HIR"凝血神爪"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me,target);
	}
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);   
	  target->start_busy(4);	  
	 return 1;
	 }
	 if ((int)target->query_condition("snake_poison") > 0 )
	 {
	if ((int)target->query_condition("snake_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("snake_poison", 0);
	  message_vision(HIY"$n"HIY"身上的"HIR"蛇毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$n"HIY"身上的"HIR"蛇毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me,target);
	}
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);   
	  target->start_busy(4);	  
	 return 1;
	 }
	if ((int)target->query_condition("wudu_poison") > 0 )
	 {
	if ((int)target->query_condition("wudu_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("wudu_poison", 0);
	  message_vision(HIY"$n"HIY"身上的"HIR"五毒气"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("wudu_poison", (int)target->query_condition("wudu_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$n"HIY"身上的"HIR"五毒气"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me,target);
	}
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);   
	  target->start_busy(4);	
	 return 1;
	}
if ((int)target->query_condition("yufeng_poison") > 0 )
	 {
	if ((int)target->query_condition("yufeng_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("yufeng_poison", 0);
	  message_vision(HIY"$n"HIY"身上的"HIR"玉蜂针毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("yufeng_poison", (int)target->query_condition("yufeng_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$n"HIY"身上的"HIR"玉蜂针毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me,target);
	}
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);   
	  target->start_busy(4);
	 return 1;
	 }
	if ((int)target->query_condition("bingpo_poison") > 0 )
	 {
	if ((int)target->query_condition("bingpo_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	  target->apply_condition("bingpo_poison", 0);
	  message_vision(HIY"$n"HIY"身上的"HIR"冰魄银针毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me,target); 
   }
   else {
   target->apply_condition("bingpo_poison", (int)target->query_condition("bingpo_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$n"HIY"身上的"HIR"冰魄银针毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me,target);
	}
	
		 me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	  me->start_busy(4);
	  target->start_busy(4);   
	 return 1;
	 }

	else tell_object(me, "他现在没有中毒。\n" NOR );
	 return 1;
}  

