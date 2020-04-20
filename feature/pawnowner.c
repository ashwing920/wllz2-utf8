// pawnowner.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <dbase.h>

int is_pawn() { return 1;}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什么物品给当铺估价？\n");

	if(ob->query("money_id"))
		return notify_fail(this_object()->name()+"疑道：这是「钱」，你没见过吗？\n");

	if(ob->query("base_unit"))
		return notify_fail(this_object()->name()+"摇了摇头，说道：这些小东西本典当不收！\n");

	value = (int)ob->query("value");

	if( ob->is_food() || ob->is_liquid())
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"我们是不收的。\n");

	if( value <= 1 || ob->query("no_sell") || ob->query("no_pawn"))
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"不能卖断。\n");

	if( ob->query("shaolin") )
		return notify_fail(this_object()->name()+"笑道：少林的东西是不能卖掉的！\n");

	if( ob->query("consistence"))
		return notify_fail(this_object()->name()+"说道："+ ob->name() +"已经损坏，一文不值。\n");

	if( !value )
		write(sprintf("本店不收%s。\n", ob->query("name")));
	else
		write(sprintf("%s价值%s。\n如果你要典当（pawn），可以拿到%s及一张当票。\n"
			"如果卖断（sell），可以拿到%s。\n",
			ob->query("name"),
			MONEY_D->price_str(value),
			MONEY_D->price_str( (value >20000000) ? value /100*40 : value *40/100),
			MONEY_D->price_str( (value >20000000) ? value /100*80 : value * 80 / 100)));
	return 1;
}

int do_pawn(string arg)
{
	object ob;
	mapping pawn;
	string *base_name, str_temp, str_path, str_name, str_id, str_unit;
	int value, num;

	if(this_player()->is_busy()) 
		return notify_fail("你正忙着呢！\n");

	this_player()->start_busy(1);

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要典当什麽物品？\n");

	if( ob->query("money_id") )
		return notify_fail("你要当「钱」？\n");

	if( ob->query("base_unit"))
		return notify_fail(this_object()->name()+"摇了摇头，说道：这些小东西本典当不收！\n");

	if( ob->is_food() || ob->is_liquid())
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"我们是不收的。\n");

	if( ob->query("no_sell") || ob->query("no_pawn"))
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"不能卖断。\n");

	if( ob->query("shaolin") )
		return notify_fail(this_object()->name()+"笑道：少林的东西是不能卖掉的！\n");

	if( ob->query("equipped"))
		return notify_fail("你正使用这种物品，无法典当！\n");

	if( ob->query("consistence"))
		return notify_fail(ob->name()+"已经损坏，不能进行典当。\n");

	value = (int)ob->query("value");
	if( value <= 1 ) return notify_fail("这样东西不能典当。\n");

	if(mapp(pawn = this_player()->query("pawn")) )
		base_name = keys(pawn);

	if( ( str_temp = this_player()->query("pawn/" + ob->query("name") + ob->query("id")) ) ) {
		// pawn的格式：物品文件名~物品中文名~物品英文ID~物品个数~物品单位
		sscanf(str_temp, "%s~%s~%s~%d~%s", str_path, str_name, str_id, num, str_unit);
		num ++;
	}
	else
		num = 1;

	if(sizeof(base_name) > 40)              // 物品种类限制
		return notify_fail("你典当的种类太多了，先赎走一些吧？\n");

	if(num > 20)                            // 物品个数限制
		return notify_fail("你典当的数量太多，这种物品不能再当了。\n");

	message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ MONEY_D->price_str((value>20000000) ? value/100*40:value * 40 / 100) + "。\n", this_player());

	MONEY_D->pay_player(this_player(), (value>20000000) ? value/100* 40 : value * 40 / 100);

	// pawn的格式：物品文件名~物品中文名~物品英文ID~物品个数~物品单位
	str_temp = sprintf("%d", num);
	this_player()->set("pawn/" + ob->query("name") + ob->query("id"),
			base_name(ob) + "~" + ob->query("name") + "~" + ob->query("id") +
			"~" + str_temp + "~" + ob->query("unit") );

	if(!present("pawn ticket", this_player()) ) {
		tell_object(this_player(),this_object()->name()+"递给你一张当票，说道：好好保存，别丢了。\n");
		new("/clone/misc/pawn_ticket")->move(this_player(),1);
	}

	destruct(ob);
	return 1;
}

int do_sell(string arg)
{
	object ob;
	mapping vendor_goods;
	string *base_name;
	int value, old;

	if(this_player()->is_busy())
		return notify_fail("你正忙着呢！\n");
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");
	if( ob->query("money_id") )
		return notify_fail("你要卖「钱」？\n");

	if( ob->query("base_unit"))
		return notify_fail(this_object()->name()+"摇了摇头，说道：这些小东西本典当不收！\n");

	value = (int)ob->query("value");

	if( ob->is_food() || ob->is_liquid())
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"我们是不收的。\n");

	if( value <= 1 || ob->query("no_sell") || ob->query("no_pawn"))
		return notify_fail(this_object()->name()+"笑道："+ ob->name() +"不能卖断。\n");

	if( ob->query("shaolin") )
		return notify_fail(this_object()->name()+"笑道：少林的东西是不能卖掉的！\n");

	if( ob->query("equipped"))
		return notify_fail("你正使用这种物品，无法卖掉！\n");

	if( ob->query("consistence"))
		return notify_fail(ob->name()+"已经损坏，当铺可不收这些破烂。\n");

	if(mapp(vendor_goods = this_object()->query("vendor_goods")) )
		base_name = keys(vendor_goods);

	message_vision("$N把身上的" + ob->query("name") + "卖给了$n。\n", this_player(),this_object());
	tell_object(this_player(),this_object()->name()+"找给你"+MONEY_D->price_str( (value >20000000) ? value /100*80 : value * 80 / 100)+"。\n");

	old = this_object()->query_with_slash("vendor_goods." + base_name(ob));
	this_object()->set_with_slash("vendor_goods." + base_name(ob), old + 1);

	MONEY_D->pay_player(this_player(), (value>20000000) ? value/100*80 : value * 80 / 100);
	destruct(ob);
	this_player()->start_busy(1);
	return 1;
}

int do_redeem(string arg)
{
	object ob, me;
	mapping pawn;
	string *base_name, str_temp, str_path, str_name, str_id, str_unit;
	int value, i, num, no;

	me = this_player();

	seteuid(geteuid(me));

	if(this_player()->is_busy()) 
		return notify_fail("你正忙着呢！\n");

	this_player()->start_busy(1);

	if( !arg ) return notify_fail("格式：ransom <物品>\n"
				      "或    redeem <物品>\n");

	if(mapp(pawn = this_player()->query("pawn")) )
		base_name = keys(pawn);

	if(!sizeof(base_name))  return notify_fail("你想要赎回什么物品？\n");

	no = 0;
	if( arg >= "00" && arg <= "99" ) sscanf( arg, "%d", no );

	for(i = 0;i < sizeof(base_name); i++) {
		// pawn的格式：物品文件名~物品中文名~物品英文ID~物品个数~物品单位
		sscanf(pawn[base_name[i]], "%s~%s~%s~%d~%s", str_path, str_name, str_id, num, str_unit);
		if(arg != str_name && arg != str_id && no != i + 1 )  continue;
		ob = new(str_path);
		value = ob->query("value");
		destruct(ob);
		break;
	}

	if(i >= sizeof(base_name) )
		return notify_fail("你想要赎回什么物品？\n");

	if( MONEY_D->player_pay(me, value) ) {
		ob = new(str_path);
		ob->move(me);
/*
		message_vision("$N从当铺赎回了一"+
			(sprintf("%s%s。\n",    ob->query("unit"),ob->query("name"))), this_player() );
*/
		message_vision("$N从当铺赎回了一"+
			(sprintf("%s%s。\n",    ob->query("unit"),str_name)), this_player() );
		num --;
		if( num > 0 ) {
			// pawn的格式：物品文件名~物品中文名~物品英文ID~物品个数~物品单位
			str_temp = sprintf("%d", num);
/*
			this_player()->set("pawn/" + ob->query("name") + ob->query("id"),
				base_name(ob) + "~" + ob->query("name") + "~" + ob->query("id") +
				"~" + str_temp + "~" + ob->query("unit") );
*/
			this_player()->set("pawn/" + str_name + str_id,
				base_name(ob) + "~" + str_name + "~" + str_id +
				"~" + str_temp + "~" + ob->query("unit") );
		}
		else
//                        me->delete("pawn/"+ob->query("name")+ob->query("id"));
			me->delete("pawn/"+str_name+str_id);

		if(mapp(pawn = me->query("pawn")) ) base_name = keys(pawn);
		if(sizeof(pawn) == 0) {
			if(objectp(ob = present("pawn ticket", me)) ){
				tell_object(me,"你把当票还给了"+ this_object()->name() +"。\n");
				destruct(ob);
			}
			me->delete("pawn");
		}

		return 1;
	} else
		write("你的钱不够。\n");

		return 1;
}
