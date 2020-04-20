// wield.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) 
		return notify_fail("你要装备什么武器？\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if((int)ob->query("wield_str") > (int)me->query_str())
		return notify_fail(ob->name()+"对你而言太重了，你拿不起来。\n");

	if( (int)ob->query("man_only") && (string)me->query("gender") != "男性")
		return notify_fail(ob->name()+"是男人家的东西，你怎么能装备起来呢？\n");

	if( (int)ob->query("woman_only") && (string)me->query("gender") != "女性")
		return notify_fail(ob->name()+"是女人家的东西，你怎么能装备起来呢？\n");

	if( (int)ob->query("zongshi_only") && !(int)me->query("is_zongshi"))
		return notify_fail(ob->name()+"是宗师类武器，你目前还无法装备。\n");
	
	if((string)ob->query("weapon_master")
	&& (string)ob->query("weapon_master") != (string)me->query("id"))
		return notify_fail("你握起"+ ob->name()+ NOR"，心中一阵震憾，你又把它放了下来。\n");

	if( ob->wield() ) {
		if(userp(me) && me->is_fightting() && !me->is_busy()) me->start_busy(1);
		if( !stringp(str = (string)ob->query("wield_msg")))
		str = "$N装备$n作武器。\n";
		message_vision(str + NOR, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
	);
	return 1;
}
