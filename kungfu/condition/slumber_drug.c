// slumber_drug.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query_con() + ((int)me->query("neili") / 20)) * 2;

	if( duration > limit
	&& living(me) ) {
		me->unconcious();
		return 0;
	} else  {
		tell_object(me, "你觉得脑中昏昏沉沉，心中空荡荡的，直想躺下来睡一觉。\n");
		message("vision", me->name() + "摇头晃脑地站都站不稳，显然是蒙汗药的药力发作了。\n",environment(me),me);
		me->receive_wound("qi",me->query_con());
		me->receive_damage("jing",me->query_con());
		if( me->query("neili"))
		me->add("neili",- me->query_con() * 10);
		if(me->query("neili") <= 0) me->set("neili",0);
		
	}

	me->apply_condition("slumber_drug", duration - 1);
	if( !duration ) return 0;
	return 1;
}
