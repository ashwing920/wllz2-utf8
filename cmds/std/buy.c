//buy.c
// Design By Robert 蝴蝶君 email:robert_st@sina.com

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string item, targ = "";
	object owner;
	int i, price;
	object* inv;

	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(!environment(me))
		return notify_fail("你要跟谁买东西？\n");

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 ) {
		inv = all_inventory(environment(me));
		i = sizeof (inv);
		while (i--) {
		if(inv[i]->is_vendor()) {
		item = arg;
		targ = inv[i]->query("id");
		break;
		}

	}
	if (targ == "")
		return notify_fail("指令格式：buy <某物> from <某人>\n");

	}

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("你要跟谁买东西？\n");

	if( sizeof(all_inventory(me)) >= 50 )
		return notify_fail("你身上的东西已经太多了。\n");

	if( userp(owner) ) {
		message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
		notify_fail("对方好像不愿意跟你交易。\n");
		return 1;
	}

	reset_eval_cost();
	notify_fail("对方好像不愿意跟你交易。\n");

	if( (price = owner->buy_object(me, item)) < 1 ) return 0;

	if( MONEY_D->can_afford( me,price ) ) {
		MONEY_D->player_pay(me,price);
		owner->compelete_trade(me, item);
		return 1;
	} else
		return notify_fail("你的钱不够。\n");
}

int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
