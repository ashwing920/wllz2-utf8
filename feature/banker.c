// banker.c

int do_check(string arg)
{
	int value;

	value = (int) this_player()->query("balance");
	if(value == 0) return notify_fail(this_object()->name() +"告诉你：你目前并没有存款。\n");
	if(value > 0)
		tell_object(this_player(), this_object()->name()+"告诉你：你现在共有存款" );
	else {
		tell_object(this_player(), this_object()->name()+"告诉你：你欠下弊钱庄共" );
		value = -value;
	}
	tell_object(this_player(), MONEY_D->price_str(value) + "\n" );

	return 1;
}
int do_convert(string arg)
{
	string from, to;
	int amount, total, bv1, bv2;
	object me,from_ob, to_ob;
	
	me = this_player();

	if(me->is_busy()) return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3 )
		return notify_fail("指令格式：convert <数量> <货币种类> to <货币种类>\n");

	me->start_busy(1);

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);
	if( !to_ob && file_size("/clone/money/" + to + ".c") < 0 )
		return notify_fail("你想兑换哪一种钱？\n");

	if( !from_ob ) return notify_fail("你身上没有这种货币。\n");
	if( amount < 1 ) return notify_fail("兑换货币一次至少要兑换一个。\n");

	if( (int)from_ob->query_amount() < amount )
		return notify_fail("你身上没有那么多" + from_ob->query("name") + "。\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("这种东西不值钱。\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	if( bv1 == bv2 ) return notify_fail("你无聊不无聊啊？\n");
	if (bv1>1000000 && amount>100) amount=100;
	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 ) return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");

	total = from_ob->query_amount() - amount;
	from_ob->add_amount(-amount);
	if( !to_ob ) {
		to_ob = new("/clone/money/" + to);
		to_ob->move(me,1);
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
		CHINESE_D->chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		CHINESE_D->chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		me);

	me->save();

	// 加入Total变量的原因是：如果用query_amount()还没有反应过来，就成了ＢＵＧ！
	if(total <= 0) destruct(from_ob);
	return 1;
}
int do_deposit(string arg)
{
	int amount, total;
	string money;
	object me,money_ob;

	me = this_player();

	if(me->is_busy()) return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%d %s", amount, money) != 2 )
		return notify_fail("指令格式：deposit <数量> <货币种类>\n");

	if( amount < 1 ) return notify_fail("储存货币一次至少要储存一个。\n");

	me->start_busy(1);

	money_ob = present(money + "_money", me);
	if( !money_ob ) return notify_fail("你身上没有这种货币。\n");

	if( (int)money_ob->query_amount() < amount )
		return notify_fail("你身上没有那麽多" + money_ob->query("name") + "。\n");

	if( amount * (int)money_ob->query("base_value") < 0)
		return notify_fail("钱庄算不了这么大笔款。\n");
	if(me->query("balance") >= 2000000000)
		return notify_fail("您的存款度已经用满了。\n");

	total = money_ob->query_amount() - amount;
	money_ob->add_amount( -amount );
	me->add("balance", amount * (int)money_ob->query("base_value") );
	message_vision( sprintf("$N从身上取出%s%s%s，存入了钱庄。\n",
		CHINESE_D->chinese_number(amount), money_ob->query("base_unit"), money_ob->query("name") ),
		me );

	me->save();

	// 加入Total变量的原因是：如果用query_amount()还没有反应过来，就成了ＢＵＧ！
	if(total <= 0) destruct(money_ob);

/*      if(this_player()->query("balance") < 0) {
		tell_object(this_player(), "由于钱庄资金周转出现了问题，你的存款被钱庄老板私吞了。\n");
		this_player()->delete("balance");
	}
*/
	return 1;
}

int do_withdraw(string arg)
{
	int amount;
	string money;
	object me,money_ob;

	me = this_player();
	
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%d %s", amount, money) != 2 )
		return notify_fail("指令格式：withdraw <数量> <货币种类> \n");

	me->start_busy(1);

	money_ob = present(money + "_money", me);
	if( !money_ob && file_size("/clone/money/" + money + ".c") < 0 )
		return notify_fail("没有这种货币。\n");

	if( !money_ob) money_ob = new("/clone/money/" + money);

	amount = ( amount * (int)money_ob->query("base_value") );

	if( amount < 1 ) return notify_fail("本店没有这么多现金。\n");

	if( (int)me->query("balance") < amount )
		return notify_fail("你没有那麽多存款。\n");
	me->add("balance", - amount );

/*      // Micro: 由于可以向钱庄借钱，所以取消存款的合法性判断
	if(me->query("balance") < 0) {
		tell_object(me, "由于钱庄资金周转出现了问题，你的存款被钱庄老板私吞了。\n");
		me->delete("balance");
	}
*/
	MONEY_D->pay_player(me, amount);
	message_vision( sprintf("$N从钱庄取出%s。\n",MONEY_D->price_str(amount)), me);
	me->save();


	return 1;
}
/*
int do_loan(string arg)
{
	int amount;
	string money;
	object money_ob;

	if(this_player()->is_busy()) return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%d %s", amount, money) != 2 )
		return notify_fail("指令格式：loan <数量> <货币种类> \n");

	this_player()->start_busy(1);

	money_ob = present(money + "_money", this_player());
	if( !money_ob && file_size("/clone/money/" + money + ".c") < 0 )
		return notify_fail("没有这种货币。\n");

	if( !money_ob) money_ob = new("/clone/money/" + money);

	amount = ( amount * (int)money_ob->query("base_value") );

	if( amount < 1 ) return notify_fail("本店没有这么多现金。\n");

	if( (int)this_player()->query("balance") > 0 ) return notify_fail("你还有存款！\n");

	// Micro: 每一点经验可以欠钱庄10文钱
	if( (int)this_player()->query("combat_exp") <
		( amount - this_player()->query("balance") ) / 10 )
			return notify_fail("你借不到这么多钱！\n");

	message_vision( sprintf("$N从钱庄取出%s。\n",
		MONEY_D->price_str( amount ) ), this_player() );

	this_player()->add("balance", - amount );

      // Micro: 由于可以向钱庄借钱，所以取消存款的合法性判断
	if(this_player()->query("balance") < 0) {
		tell_object(this_player(), "由于钱庄资金周转出现了问题，你的存款被钱庄老板私吞了。\n");
		this_player()->delete("balance");
	}

	MONEY_D->pay_player(this_player(), amount);

	return 1;
}

*/
