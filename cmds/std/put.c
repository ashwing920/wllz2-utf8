// put.c
inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest,obj2;
	int amount;

	if(!arg) 
		return notify_fail("你要将什么东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什么东西？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");

	if(!dest->is_container())
		return notify_fail("你无法将东西放进"+ dest->name() +"里面。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_put(me, obj2, dest)) 
				return 1;
			else{
				obj->set_amount((int)obj->query_amount() + amount);
				destruct(obj2);
				return 0;
			}
		}
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");

	if((obj->is_character() || obj->is_container()) && !obj->is_corpse())
		return notify_fail(obj->name() +"怎么能够放到"+ dest->name() +"里面呢？\n");

	if((present(item, me))->query("no_put") )
		return notify_fail("这样东西不能乱放。\n");

	if( obj == dest )
		return notify_fail("你不能把东西放进它自己里面。\n");

	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if( obj->move(dest) )
	{
		if ( wizardp(me) || wizhood(me) == "(immortal)" )
		{
			log_file("static/wizput", sprintf("%s%s put %d %s %s in %s (%s)\n",
				me->query("name"),
				"(" + me->query("id") + ")" ,
				!obj->query_amount()?1:(int)obj->query_amount(),
				obj->query("unit"),
				base_name(obj) + ".c",
				base_name(dest) + ".c",
				ctime(time())
				) );
		}

		message_vision( sprintf("$N将一%s%s放进%s。\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		return 1;
	}
	else return 0;
}

int help(object me)
{
write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP
	);
	return 1;
}
