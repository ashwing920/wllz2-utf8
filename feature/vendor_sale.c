// /feature/vendor_sale.c
// modify by ronger 99/02

#include <dbase.h>
#include <ansi.h>

inherit SELLER_SAVE;

#define PERIOD 86400

int price_ratio = 10;

string owner_id, owner_name;
string owner_long;
string bidder, bidder_name;
string bidder_long;
int bid;
int minimum_bid = 10000;
int deposit;
int close_time;
int profit;
int last_profit;

int take_money(int paid, int price);
void set_new_owner(string id, string name, string long);
void set_default_owner();
int query_price() {return price_ratio;}
int pay_back(string id, int amount);
void new_owner();

void set_time(int tim) {close_time = time() + tim;}

int is_vendor() { return 1;}

int buy_object(object me, string what)
{
	mapping goods;
	string *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	name = keys(goods);
	for(i = 0; i < sizeof(name); i ++) {
		if(what == name[i]->name() || what == name[i]->query("id"))
			return (int)(name[i]->query("value")) * price_ratio/10;
	}
	return 0;
}
void compelete_trade(object me, string what)
{
	mapping goods;
	object ob;
	string ob_file;
	string *name, last = "";
	int i,price;

	if( !mapp(goods = query("vendor_goods")) ) return;
	name = keys(goods);
	for(i = 0; i < sizeof(name); i ++) {
	if(what == name[i]->name() || what == (name[i]->query("id")))
	{
		if( stringp(ob_file = name[i]) ) {
			int sale_price = price_ratio;
			ob = new(ob_file);
			price = ob->query("value");
			if (sale_price > 5)
			sale_price = 5;
			ob->set_temp("sale_price", price*sale_price/10);
			if (!take_money(price*price_ratio/10, price)) {
				destruct(ob);
				return;
			}
			save();
			ob->set("value", price*price_ratio/10);
			ob->set("no_sell", 1);
			ob->set("no_pawn", 1);
			if( ob->move(me,1) ) {
				write(sprintf("你向%s买下%s一%s%s。\n", this_object()->name(),
					last, ob->query("unit"), ob->name()));
				switch(random(3)) {
				case 0:
				tell_object(me,this_object()->name()+"说道：谢谢，盛惠"+ MONEY_D->price_str(ob->query("value"))+ NOR"，欢迎下次再来。\n");
				break;
				case 1:
				tell_object(me,this_object()->name()+"连连点头，笑道：客倌，盛惠"+ MONEY_D->price_str(ob->query("value"))+"。\n",this_object());
				break;
				case 2:
				tell_object(me,"你从怀里拿出"+ MONEY_D->price_str(ob->query("value"))+"还给"+ this_object()->name() +"。\n");
				break;
				}

			}
			else
				destruct(ob);
			return;
		}
	}
	}
}



int take_money(int paid, int price)
{
	int earn;
	earn = paid-price/2;

	if (earn >= 0)
	profit += earn;
	else
	{
		if (deposit + earn < 0)
		{
			message_vision("\n" + name() + "破产了！\n\n",this_object());
			new_owner();
			return notify_fail("the owner bankrupted\n");
		}
		deposit += earn;
	}
	return 1;
}

string price_string(int v)
{
	string str="";
	int val;
	val = v/10000;

	if (val) str += chinese_number(val) + "两黄金";
	val = (v%10000)/100;
	if (val) str += chinese_number(val) + "两银子";
	val = (v%100);
	if (val) str += chinese_number(val)  + "文钱";
	if (str=="") str = "零文钱";

	return str;
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, s, *name;
	int i, j, temp;

	if( !mapp(goods = query("vendor_goods")) )
		return notify_fail(this_object()->name()+"目前没有任何物品出售。\n");
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	if( !sizeof(name) )
		return notify_fail(this_object()->name() +"说道：对不起，今天这儿的东西全卖光了，明日请早。\n");
	list = "\n你可以在"+ this_object()->name()+"这里购买下列这些物品：\n\n";

	for( i = 0; i < sizeof(name); i ++ ) {
		s = name[i]->name();
		for(j = 0, temp = 0; j < strlen(s) ; j++, temp++)
			if( (int)s[j] == 27 )
				for(temp--; j < strlen(s) && s[j] != 'm'; j++ );
		for(j = temp; j < 20; j++ ) s += " ";
		list += s + sprintf("%-16s 每%s%s"CYN"(现货大量供应)\n"NOR,capitalize(name[i]->query("id")),
		name[i]->query("unit"),MONEY_D->price_str(name[i]->query("value")  * price_ratio/10));
	}
	write(list);

	return 1;
}
int heal_up()
{
	if (close_time<time() + 60) {
		new_owner();
	}
	return ::heal_up() + 1;
}
int do_bid(string arg)
{
	int minimum, amount;
	string money;
	object who, who1, env;
	string roomname;
	who = this_player();

	notify_fail("指令格式：bid <amount> < gold | silver > \n");

	if (!arg) return 0;
	if (sscanf(arg,"%d %s", amount, money)!=2) return 0;

	if (money=="gold") amount*=10000;
	else if (money=="silver") amount*=100;
	else return 0;

	if (amount<1) return 0;

	if (!bid) minimum = minimum_bid;
	else {
		minimum = bid;
		if (minimum > 10000) minimum += minimum/10;
		else minimum += 1000;
	}

	minimum = (minimum/100) * 100;

	if (amount < minimum)
		return notify_fail("你至少需要出" + price_string(minimum) + "。\n");

	if (who->query("balance") < amount)
		return notify_fail("你的存款里没有这么多钱。\n");

	env = environment(this_object());
	if (base_name(env) != this_object()->query("startroom"))
	roomname = this_object()->query("name");
	else
	roomname = env->query("short");

	if (bidder)
	{
		pay_back(bidder, bid);
		if (getuid(who) != bidder)
		{
			who1 = find_player(bidder);
			if (who1)
			tell_object(who1, "你计划购买" + roomname + "失败了！\n");
		}
	}

	if (close_time < time() + 120) close_time += 60;

	who->add("balance",-amount);
	who->save();

	bidder = who->query("id");
	bidder_name = who->query("name");
	bidder_long = who->long();
	bid = amount;
	save();
	seteuid(getuid());
	message_vision("$N出价"+price_string(amount)+"收购" + roomname + "！\n",who);
	return 1;
}

int pay_back(string id, int amount)
{
	object who;

	who = find_player(id);
	if (who)
	{
		who->add("balance",amount);
		if (!who->save())
		{
			log_file("shop_log","Failed to return " + amount +
				" coin to " + id + "\n");
			return 0;
		}
		log_file("shop_log","pay " + amount + " to " + id + "\n");
		return 1;
	}
	else
	{
		who = UPDATE_D->load_player(id);
		if (!who->restore())
		{
			log_file("shop_log","因读取资料档失败而无法将 " + amount +
				" 文钱存入 " + id + " 这个帐号。\n");
			destruct(who);
			return 0;
		}
		else
		{
			who->add("balance",amount);
			if (!who->save(1))
			{
				log_file("shop_log","因存档失败而无法将 " + amount +
					" 文钱存入 " + id + " 这个帐号。\n");
				destruct(who);
				return 0;
			}
			log_file("shop_log","成功付出 " + amount + " 文钱给 " + id + "。\n");
			UPDATE_D->global_destruct_player(who,1);
			//if(who) destruct(who);
			return 1;
		}
	}
}

int do_deposit(string arg)
{
	object who = this_player();
	string money;
	int amount;

	if (getuid(who) != owner_id)
		return notify_fail("只有店主才能用这个命令。\n");

	notify_fail("指令格式：deposit <amount> < gold | silver >\n");

	if (!arg) return 0;
	if (sscanf(arg,"%d %s", amount, money) != 2) return 0;

	if (money=="gold") amount*=10000;
	else if (money=="silver") amount*=100;
	else return 0;

	if (amount < 10000) return notify_fail("一次至少要一两金子。\n");

	if (who->query("balance") < amount)
		return notify_fail("你的存款里没有这么多钱。\n");

	who->add("balance",-amount);
	who->save();

	deposit += amount;
	save();

	write("现在共有"+price_string(deposit)+"预付金。\n");

	return 1;
}

int do_setprice(string arg)
{
	object who=this_player();
	int ratio;
	string str;

	if (getuid(who) != owner_id)
		return notify_fail("只有店主才能用这个命令。\n");

	notify_fail("指令格式：set_price <ratio> \n" + "定价范围为：1 到 100倍。\n");

	if (!arg) return 0;
	if (sscanf(arg,"%d",ratio) != 1) return 0;
	if (ratio < 1 || ratio > 100) return 0;

	if (ratio < 10 && deposit < 1)
		return notify_fail("你的定价少于成本，必须先付定金(deposit)。\n");

	price_ratio = ratio;
	save();

	if (ratio < 10)
	message_vision("$N决定将所有物品" + chinese_number(ratio) + "折出售。\n", who);
	else if (ratio==10)
	message_vision("$N决定所有物品按原价出售。\n", who);
	else
	{
		str = chinese_number(ratio/10);
		ratio = ratio-(ratio/10)*10;
		if (ratio)
		str += "点"+chinese_number(ratio);
		message_vision("$N决定所有物品按原价的" + str + "倍出售。\n", who);
	}

	return 1;
}

int do_status(string arg)
{
	object who = this_player();
	int hour, next;
	string str;

	if (!close_time)
	{
		close_time = time() + PERIOD;
		save();
	}

	next = close_time - time();
	if (next < 60)
	new_owner();
	else
	{
		hour = next/3600;
		if (hour)
		str = chinese_number(hour) + "小时";
		else
		str = "";
		hour = (next - hour*3600)/60;
		if (hour)
		str += chinese_number(hour) + "分钟";
		write("投标获胜者将于" + str + "后成为新店主。\n");
	}

	if (bidder)
	write("当前最高投标是" + bidder_name + "[" + bidder + "]："
		+ price_string(bid) + "\n");
	else
	write("目前还没有人投标。\n");

	write("昨日盈利：" + price_string(last_profit) + "\n");

	if(wizardp(who) || getuid(who)==owner_id)
	{
		write("\n盈利　　　：" + price_string(profit) + "\n");
		write("剩余预付金：" + price_string(deposit) + "\n");
		write("价格指数　：" + price_ratio + "\n");
	}

	return 1;
}

void new_owner()
{
	int prof;
	object old, mbx;
	mapping mail;
	string msg;

	close_time = time() + PERIOD;

	if (owner_id)
	{
		prof = profit + deposit;
		if (prof>0)
		pay_back(owner_id, prof);
		old = find_player(owner_id);

		msg = "你的店主(" + name(1) + ")任期结束，结余" + price_string(prof) + "已存入你的户头。\n";
		msg += "其中盈利" + price_string(profit) + "，剩余预付金 " + price_string(deposit) + "。\n";

		if (old)
		tell_object(old,msg);
		mail = (["from": name(1) + "(" + query("id") + ")",
			"title": name(1) + "：帐目结算", "to": owner_id,
			"time": time(), "status": "N", "text": msg
		]);

		seteuid(getuid());
		mbx = new(MAILBOX_OB);
		mbx->set_owner("vendor_sale");
		mbx->send_mail(owner_id,mail,1);
		destruct(mbx);
	}

	if (bidder)
	{

		owner_id = bidder;
		owner_name = bidder_name;
		owner_long = bidder_long;
		set_new_owner(owner_id, owner_name, owner_long);
	}
	else
	{
		owner_id = 0;
		owner_name = 0;
		owner_long = 0;
		set_default_owner();
	}

	last_profit = profit;
	profit = 0;
	deposit = 0;
	bidder = 0;
	bidder_name = 0;
	bid = 0;
	price_ratio = 10;

	save();

}

void set_new_owner(string id, string name, string long)
{
	string short;
	string *newid;

	set_temp("apply/name",({name}));

	if (pointerp(newid = query("shop_id")))
	{
		newid = ({newid[0] + " " + id}) + newid;
	}
	else
	{
		newid = ({"boss " + id, "boss"});
	}

	set_temp("apply/id",newid);
	set_temp("apply/long",({long}));

	if (stringp(short = query("shop_title")))
	{
		short += " ";
	}
	else if (stringp(short = query("title")))
	{
		short += " ";
	}
	else short = query("name") + " ";

	short += name + "[" + capitalize(newid[0]) + "]";
	set_temp("apply/short",({short}));
}

void set_default_owner()
{
	delete_temp("apply/name");
	delete_temp("apply/id");
	delete_temp("apply/short");
	delete_temp("apply/long");
}

void reload(string filename)
{
	::reload(filename);

	if(owner_id)
	set_new_owner(owner_id, owner_name, owner_long);
}

string query_save_file()
{
	string id;
	id = query_save_name();
	if ( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "npc/boss/%s", id);
}
