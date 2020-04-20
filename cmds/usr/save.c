// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write("当你下次连线进来时，会从这里开始。\n");
	}
	if((time() - (int)me->query_temp("save")) < 60 )
		return notify_fail("刚刚才储存了一次，那么快又要储存了？\n");

	if(link_ob->save() && me->save()) {
		me->set_temp("save",time());
		write("档案储存完毕。\n");
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save  

把你辛苦奋斗的结果存起来，下次上线，你将会出现在上次储存的地方。

相关讯息：quit

HELP
	);
	
	return 1;
}
