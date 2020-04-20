// bidu.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中不能逼毒。\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 40)
		return notify_fail("你的先天神功修为还不够。\n");
	if( (int)me->query("neili") < 50) 
		return notify_fail("你的真气不够。\n");
	
	write(HIB"你全身放松，坐下来开始运功逼毒。\n" NOR);
	message("vision",HIB + me->name() + "坐下来运功逼毒。\n" NOR,environment(me), me);

	if ((int)me->query_condition("zm_poison") > 0 ){
	if ((int)me->query_condition("zm_poison") < (int)me->query_skill("xiantian-qigong",1)/20 + 1 ){
	  me->apply_condition("zm_poison", 0);
	  message_vision(HIY"$N"HIY"身上的"HIR"子母飞针之毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
	}
   else {
	me->apply_condition("zm_poison", (int)me->query_condition("zm_poison") -(int)me->query_skill("xiantian-qigong",1)/20 );
	message_vision(HIY"$N"HIY"身上的"HIR"子母飞针之毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);
	return 1;

   }
	if ((int)me->query_condition("ice_poison") > 0 ){
	if ((int)me->query_condition("ice_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	  me->apply_condition("ice_poison", 0);
	  message_vision(HIY"$N"HIY"身上的"HIR"寒冰绵掌"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
	}
   else {
	me->apply_condition("ice_poison", (int)me->query_condition("ice_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	  message_vision(HIY"$N"HIY"身上的"HIR"寒冰绵掌"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;

   }
	if ((int)me->query_condition("jy_poison") > 0 )
{
	if ((int)me->query_condition("jy_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )	
	{
	me->apply_condition("jy_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"九阴白骨爪毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("jy_poison", (int)me->query_condition("jy_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"九阴白骨爪毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
}
	 
	if ((int)me->query_condition("xx_poison") > 0 )
{
	if ((int)me->query_condition("xx_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )	
	{
	  me->apply_condition("xx_poison", 0);
	  message_vision(HIY"$N"HIY"身上的"HIR"星宿掌毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
	else{
	me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"星宿掌毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
}
   
	if ((int)me->query_condition("ss_poison") > 0 )
	 {
	if ((int)me->query_condition("ss_poison") < (int)me->query_skill("xiantian-qigong",1)/8+1 )
	
	{
	me->apply_condition("ss_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"生死符"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("ss_poison", (int)me->query_condition("ss_poison") -(int)me->query_skill("xiantian-qigong",1)/8);
	message_vision(HIY"$N"NOR"身上的"HIR"生死符"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);
	return 1;
	 }
	  
	if ((int)me->query_condition("rose_poison") > 0 )
	 {
	if ((int)me->query_condition("rose_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	me->apply_condition("rose_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"火玫瑰毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("rose_poison", (int)me->query_condition("rose_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"火玫瑰毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
	 }
 
	if ((int)me->query_condition("zhua_poison") > 0 )
	 {
	if ((int)me->query_condition("zhua_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	me->apply_condition("zhua_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"凝血神爪"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("zhua_poison", (int)me->query_condition("zhua_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"凝血神爪"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
}
	  
	if ((int)me->query_condition("snake_poison") > 0 )
	 {
	if ((int)me->query_condition("snake_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	me->apply_condition("snake_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"蛇毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"蛇毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
	}
	if ((int)me->query_condition("wudu_poison") > 0 )
	 {
	if ((int)me->query_condition("wudu_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	me->apply_condition("wudu_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"五毒气"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("wudu_poison", (int)me->query_condition("wudu_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"五毒气"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
	 }
	if ((int)me->query_condition("yufeng_poison") > 0 )
{
	if ((int)me->query_condition("yufeng_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	{
	me->apply_condition("yufeng_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"玉蜂针毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("yufeng_poison", (int)me->query_condition("yufeng_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"玉蜂针毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
	}
	if ((int)me->query_condition("bingpo_poison") > 0 )
	 {
	if ((int)me->query_condition("bingpo_poison") < (int)me->query_skill("xiantian-qigong",1)/20+1 )
	
	{
	me->apply_condition("bingpo_poison", 0);
	message_vision(HIY"$N"HIY"身上的"HIR"冰魄银针毒"HIC"尽退"HIY"，脸色看上去好多了。\n"NOR, me); 
   }
   else {
	me->apply_condition("bingpo_poison", (int)me->query_condition("bingpo_poison") -(int)me->query_skill("xiantian-qigong",1)/20);
	message_vision(HIY"$N"HIY"身上的"HIR"冰魄银针毒"HIC"清去小半"HIY"脸色渐渐红润起来。\n"NOR, me);
	}
	
	me->add("neili", -(int)me->query("max_neili")/15);
	me->set("jiali", 0);
	me->start_busy(4);   
	return 1;
}

	else tell_object(me, "你现在没有中毒。\n" NOR );
	return 1;
}

