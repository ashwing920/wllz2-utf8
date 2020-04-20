//Cracked by Kafei
// apply.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( !arg || arg=="" ) 
		return notify_fail("你要服用什么？\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("你要服用什么？\n");

	notify_fail("这样东西不能当药服用。\n");
	
	if(me->is_fighting()) me->start_busy(2);
	return ob->cure_ob(me);
}

int help (object me)
{
	write(@HELP

指令格式: apply | fu <药品>

服用药物，只有经过炼造出来的药物，才可以使用这个指令。

HELP
	);
	return 1;
}
