// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
		else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if( who->query("env/no_accept"))
		return notify_fail("人家不要你的东西。\n");

	if( me == who ) return notify_fail("自己给自己东西？不嫌累吗？\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") )
			return notify_fail("这样东西不能随便给人。\n");
		if( obj->query("equipped") == "horse")
			return notify_fail(obj->name(1)+"目前你正在使用，不能给人。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else
		{
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else
			{
				obj->set_amount((int)obj->query_amount() + amount);
				destruct(obj2);
				return 0;
			}
		}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");

	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	mapping quest;
	object *inv;

	if( obj->query("no_drop") && userp(who))
		return notify_fail("这样东西不能随便给人。\n");

	if(!userp(who)){
		if(obj->query("owner_name") == who->query("name")
		&& obj->query("owner_id") == who->query("id")){
			if(TASK_D->quest_reward(me,who,obj))
			return 1;
		}
		if(mapp(quest = me->query("quest"))
		&& who->is_master() && quest["from"] == "门派"
		&& (string)me->query("family/family_name") 
		== (string)who->query("family/family_name")) {
			if(MQUEST_D->quest_reward(me,who,obj))
			return 1;
		}
		if(mapp(quest = me->query("quest")) 
		&& who->name() == quest["owner_name"]
		&& obj->short() == quest["quest"]
		&& quest["from"] == "江湖"){
			if(RQUEST_D->accept_ob(me,who,obj))
			return 1;
		}

		if( me->query("quest/must_ask")
		&& who->is_vendor()
		&& obj->query("money_id")
		&& me->query_temp("ask_quest")){
			if( obj->value() < 1000){
				message_vision("$N对$n喝道：就这点钱就想找我买消息啊？没门！哼！\n",who,me);
				return 1;
			}
			else {
				message_vision("$N笑咪咪的对$n点了点头，连忙把"+ obj->query("name")+"往怀里塞了进去！\n",who,me);
				me->set_temp("ask_quest_money",1);
				me->delete_temp("ask_quest");
				destruct(obj);
				return 1;
			}
		}
	}
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("你只能把东西送给其他玩家操纵的人物。\n");
	if( who->query("env/no_accept") )
		return notify_fail("人家不要你的东西。\n");
	if( !userp(who) && obj->value() || !userp(who) && (!who->query("player_baby")))
	{
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
		return 1;
	}
	else
	{
		// add by hello 1996.12.05
		// 检查玩家身上是不是已有太东西
		inv = all_inventory(who);
		if (inv && sizeof(inv)>40)
			return notify_fail(who->name()+"身上都那么多东西了，你还想给他啊！\n");
		if((int)who->query_encumbrance() + obj->weight() > (int)who->query_max_encumbrance() )
			return notify_fail(obj->name() +"对"+ who->name() +"来说太重了。\n");

		if( obj->move(who) )
		{
			if( ( wizardp(me) || wizhood(me) == "(immortal)" )
			&& !wizardp(who) && wizhood(who) != "(immortal)" )
			{
				log_file("static/wizgive", sprintf("%s%s give %s%s %d %s %s (%s)\n",
					me->query("name"),"(" + me->query("id") + ")" ,
					who->query("name"),"(" + who->query("id") + ")" ,
					!obj->query_amount()?1:(int)obj->query_amount(),obj->query("unit"),
					base_name(obj) + ".c",ctime(time())));
					CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s[%s]给了%s[%s]%d%s[%s]",
					me->query("name"),me->query("id"),who->query("name"),who->query("id"),
					!obj->query_amount()?1:(int)obj->query_amount(),obj->query("unit"),
					base_name(obj) + ".c"));

			}
			write(sprintf("你给%s一%s%s。\n", who->name(), obj->query("unit"), obj->name()));
			message("vision", sprintf("%s给你一%s%s。\n", me->name(),
				obj->query("unit"), obj->name()), who );
			message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
				obj->query("unit"), obj->name()), environment(me), ({me, who}) );
			me->save();
			who->save();
			return 1;
		}
		else return 0;
	}
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
	  或 : give <某人> <物品名称>

这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.

HELP
	);
	return 1;
}

