// time.c

inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
	string id,target,type;
	object ob;
	int value;

	if(me->ban_say()) return 0;

	if(!arg )
		return help(me);

	if(me->is_ghost())
		return notify_fail("你打算用纸钱和人家做交易嘛？\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");


	if(sscanf(arg,"%s value %d %s",target,value,type) == 3){
		if(!objectp(ob = present(target,me)))
			return notify_fail("你要拍卖什么东西？\n");

		if(!VENDOR_D->valid_sell(ob))
			return notify_fail(ob->name() +"无法进行拍卖。\n");

		if(type != "silver" && type != "gold")
			return notify_fail("你必须输入要以 gold 或者 silver 为单位。\n");

		if(ob->query_amount() || ob->query("base_unit"))
			return notify_fail("这些零散的东西不能进行拍卖。\n");

		if(!value || value < 0)
			return notify_fail("你打算把"+ ob->short()+"以多少钱拍卖出去？\n");

		switch(type){
			case "gold": value*=10000;break;
			default: value*=100;break;
		}

		if( value < 100)
			return notify_fail("拍卖师告诉你：小生意请到路边去做。\n");

		if(value > 100000000)
			return notify_fail("这桩生意数目太大，拍卖所可不敢帮你承担这个风险。\n");

		id = me->query("id");
		if(!VENDOR_D->check_vendor(id))
			return notify_fail("你已经有物品正委托拍卖呢。\n");

		VENDOR_D->add_vendor(me,ob,value);
		return 1;
	}
	else if(sscanf(arg,"value %d %s",value,type) == 2){
		if(VENDOR_D->query_times() == 0) 
			return notify_fail("目前还没有开始拍卖东西。\n");

		if(VENDOR_D->query_bid() == me->query("id"))
			return notify_fail("现在出最高价的就是你了，不用再喊价了。\n");

		if(VENDOR_D->query_times() > 3)
			return notify_fail("太迟了，这趟拍卖已经停止叫价了。\n");

		if(value <= 0 )
			return notify_fail("没钱还学人家竞标购买？\n");

		switch(type){
			case "gold": value*= 10000;break;
			default: value*=100;break;
		}

		if(value < 100)
			return notify_fail("对不起，每次叫价不得低于一两白银。\n");

		if(value > 100000000)
			return notify_fail("这桩生意数目太大，拍卖所可不敢帮你承担这个风险。\n");

		if(value <= VENDOR_D->query_now_value())
			return notify_fail("你出价必须比当前的价格高，看清楚再叫价吧！\n");

		if(value > VENDOR_D->query_now_value()
		&& value - VENDOR_D->query_now_value() < 100)
			return notify_fail("对不起，每次叫价不得低于一两白银。\n");

		if(value > (int)me->query("balance"))
			return notify_fail("你没那么多钱，就别在这里充阔佬啦！\n");

		VENDOR_D->player_call_value(me,value);
		return 1;
	}
	else if(arg == "check"){
		VENDOR_D->query_desc();
		return 1;
	}
	else return help(me);
}

int help(object me)
{
     write(@HELP

这个指令是让将自己身上的宝贝通过拍卖频道，拍卖给游戏中的玩家。
你也可以使用这个指令查阅当前正在拍卖的物品。

指令格式：

vendor <物品> value <价值> <钱币单位>	拍卖你身上的物品并定制价格。
vendor value <价值> <钱币单位>		对当前正在拍卖的物品进行叫价。
vendor check				查阅当前正在拍卖的物品信息。

HELP
);

	return 1;
}
