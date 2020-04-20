// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什么？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
	if (me->is_fighting() && count) me->start_busy(1);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备着了。\n");

	count = do_wear(me, ob);
	if (me->is_fighting() && count) me->start_busy(1);
	return count;
}

int do_wear(object me, object ob)
{
	string str;

	if((string)ob->query("id") == "jinsi jia" && (int)me->query("age") >= 20)
		return notify_fail("你长大了，穿不上金丝甲了。\n");

	if((int)ob->query("female_only")
	&& (string)me->query("gender") =="男性")
		return notify_fail("这是女人的衣衫，你一个大男人也想穿，羞也不羞？\n");

	if((int)ob->query("ownermake")){
		if((string)ob->query("armor_master")
		&& (string)ob->query("armor_master") != me->query("id"))
			return notify_fail("也许是个人定制的衣服，你怎么穿也觉得不合身。\n");

		if((string)ob->query("hand_master")
		&& (string)ob->query("hand_master") != me->query("id"))
			return notify_fail(ob->name()+ NOR"好像并不适合你使用。\n");
	}
	if(ob->query("armor_prop") && (int)ob->query("armor_prop/bad")
	&& (int)ob->query("armor_prop/bad") >= (int)ob->query("armor_prop/armor"))
		return notify_fail(ob->name()+"已经不能再使用了。\n");

	notify_fail("你只能穿戴可当作护具的东西。\n");

	if( ob->wear() ) {
		if( !stringp(str = (string)ob->query("wear_msg")) )
			switch((string)ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = "$N穿上一" + ob->query("unit") + "$n。\n";
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = "$N戴上一" + ob->query("unit") + "$n。\n";
					break;
				case "waist":
					str = "$N将一" + ob->query("unit") + "$n绑在腰间。\n";
					break;
				case "shield":
					str = "$N披上一" + ob->query("unit") +"$n。\n";
					break;
				default:
					str = "$N装备上一" + ob->query("unit") + "$n。\n";
			}
		message_vision(str, me, ob);
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>

这个指令让你装备某件防具。

HELP
    );
    return 1;
}
