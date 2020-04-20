// pour.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item, poison;
	object obj, dest;
	int poisontime;
	
	if(!arg) return notify_fail("你要下什么毒？\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(me->is_fighting())
		return notify_fail("你正在战斗，等打完了再说吧？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 
	&&  sscanf(arg, "%s on %s", item, target)!=2 )
		return notify_fail("你要往哪里下毒？\n");

	dest = present(target, me);
	if( !dest) return notify_fail("这里没有这样东西。\n");

	if( !objectp(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if( !obj->query("pour_type"))
		return notify_fail("这不是毒药啊。\n");

	if( dest->query("liquid/remaining") < 1 && !dest->query("weapon_prop"))
		return notify_fail("里面一点喝的都没有是不能下毒的。\n");

	if( !dest->query("weapon_prop") && !dest->query("liquid/remaining"))
		return notify_fail("你只能往兵器上抹毒！\n");
	
	poisontime = (int)(me->query_skill("poison",1)/5) + (int)(me->query_skill("pour",1)/5);

	if( !dest->query("weapon_prop")) {
	message_vision( sprintf("$N将一%s%s偷偷洒进%s。\n",obj->query("unit"),obj->name(),dest->name()),me);
	poison = obj->query("pour_type");
	dest->set("liquid/poison", poison);
	dest->set("liquid/poisontime", poisontime);
	destruct(obj);
	return 1;
	}
		else {
			message_vision(sprintf("$N往%s里搽上了一些%s！\n",dest->name(),obj->name()),me);
			dest->set("weapon_prop/damage",dest->query("weapon_prop/damage"));
			dest->set("weapon_prop/dodge",dest->query("weapon_prop/dodge"));
			dest->set("weapon_prop/poison",obj->query("pour_type"));
			dest->set("weapon_prop/poisontime",poisontime);
			destruct(obj);
		return 1;
	}
}

int help(object me)
{
write(@HELP
指令格式 : pour <毒品名称> in <某容器>
 
这个指令可以让你将某样毒品放进一个容器，当然，首先你要拥有这样物品。
容器里有喝的东西。或者你也可以将毒药抹在你的兵器上，嘿嘿。
HELP
	);
	return 1;
}
