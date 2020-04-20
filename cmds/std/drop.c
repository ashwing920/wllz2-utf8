// drop.c
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg) return notify_fail("你要丢下什么东西？\n");
	if(environment(me)->query("fight_room") || environment(me)->query("force_room"))
		return notify_fail("这里不能乱丢东西。\n");
	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else
			if( amount == (int)obj->query_amount() )
				return do_drop(me, obj);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if(do_drop(me, obj2)) 
					return 1;
				else{
					obj->set_amount((int)obj->query_amount() + amount);
					destruct(obj2);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++){
			if(inv[i]->query("no_drop")
			|| inv[i]->query("no_get")) continue;
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	object obj2, * inv;

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
	// add by hello 1996.12.02
	// to fix the bug: drop a object like coin many times then the system down.

	if (obj->query_amount() && objectp(obj2=present(obj->query("id"),environment(me))) ){
		obj2->set_amount( (int)obj2->query_amount() + (int)obj->query_amount() );
		message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),me, obj );
		if( (!obj->query("value") && !obj->value())){
			write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
		}
		if ( wizardp(me) || wizhood(me) == "(immortal)" ){
			if(obj->query("value"))
			log_file("static/wizdrop", sprintf("%s%s drop %d %s %s (%s)\n",
				me->query("name"),
				"(" + me->query("id") + ")" ,
				!obj->query_amount()?1:(int)obj->query_amount(),
				obj->query("unit"),
				base_name(obj) + ".c",
				ctime(time())
				) );
		}
		destruct(obj);
		return 1;
	}
	else
	{
		// add by hello 1996.12.3
		// Donnot let the user drop more than 50 things to room.
		inv = all_inventory(environment(me));  
		if (sizeof(inv)>49)
		{
			return notify_fail("地上已经那么多东西了，你想干嘛？\n");
		}

		if (obj->move(environment(me)))
		{
			if ( wizardp(me) || wizhood(me) == "(immortal)" ){
				if(obj->query("value"))
				log_file("static/wizdrop", sprintf("%s%s drop %d %s %s (%s)\n",
					me->query("name"),
					"(" + me->query("id") + ")" ,
					!obj->query_amount()?1:(int)obj->query_amount(),
					obj->query("unit"),
					base_name(obj) + ".c",
					ctime(time())
				) );
			}
			if( obj->is_character() )
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
			else
			{
				message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")), me, obj );
				if( (!obj->query("value") && !obj->value()))
				{
					write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
					destruct(obj);
				}
			}
			return 1;
		}
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>
 
这个指令可以让你丢下你所携带的物品.
 
HELP
	);
	return 1;
}

