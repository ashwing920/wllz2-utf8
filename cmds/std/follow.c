// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg )
		return notify_fail("指令格式：follow <某人>|none。\n");

	if( arg=="none")
		if( me->query_leader() ) {
			me->set_leader(0);
			write("Ok.\n");
			return 1;
		} else {
			write("你现在并没有跟随任何人。\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me)))
	|| !me->visible(ob))
		return notify_fail("这里没有 " + arg + "。\n");

	if( !ob->is_character() )
		return notify_fail("什么？跟随...." + ob->name() + "。\n");

	if( ob==me)
		return notify_fail("跟随自己？\n");

	if( me->query_leader() == ob )
		return notify_fail("你已经跟着"+ ob->query("name")+"了。\n");

	me->clean_up_enemy();
	me->dismiss_team();
	me->set_leader(ob);
	message_vision("$N决定开始跟随$n一起行动。\n", me, ob);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : follow [<生物>|none]

这个指令让你能跟随某人或生物。
如果输入 follow none 则停止跟随。

HELP
);
	return 1;
}
