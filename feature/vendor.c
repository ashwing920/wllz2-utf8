// vendor.c
#include <dbase.h>
#include <ansi.h>

int is_vendor(){ return 1;}

int buy_object(object me, string what)
{
	mapping goods;
	string *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	name = keys(goods);
	for(i = 0; i < sizeof(name); i ++) {
		if(what == name[i]->name() || what == name[i]->query("id"))
			return (int)(name[i]->query("value")) ;
	}
	return 0;
}

// 完成交易, 将物件交给买主并传出相关讯息
void compelete_trade(object me, string what)
{
	mapping goods;
	object ob;
	string ob_file,msg;
	string *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return;
	name = keys(goods);
	for(i = 0; i < sizeof(name); i ++) {
	if(what == name[i]->name() || what == (name[i]->query("id")))
	{
		if( stringp(ob_file = name[i]) ) {
			ob = new(ob_file);
			message_vision("$N向$n买下一"+ (string)ob->query("unit") + 
				(string)ob->query("name")+"。\n",me,this_object());
				switch(random(3)) {
					case 0:
						msg = "$n说道：多谢盛惠"+ MONEY_D->price_str(ob->query("value")) +"，欢迎下次再来。\n";
						break;
					case 1:
						msg = "$n连连点头哈腰的对$N笑道：客倌，盛惠"+MONEY_D->price_str(ob->query("value"))+"。\n";
						break;
					case 2:
						msg = "$N从怀里拿出"+ MONEY_D->price_str(ob->query("value"))+"还给$n。\n";
						break;
				}
				ob->move(me,1);
				message_vision(msg,me,this_object());
			return;
		}
	}
	}
}

// 列出所出售的物品及价钱
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
		s = (string)name[i]->name();
		for(j = 0, temp = 0; j < strlen(s) ; j++, temp++)
			if( (int)s[j] == 27 )
				for(temp--; j < strlen(s) && s[j] != 'm'; j++ );
		for(j = temp; j < 20; j++ ) s += " ";
		list += s + sprintf("%-16s 每%s%s"CYN"(现货大量供应)\n"NOR,capitalize(name[i]->query("id")),
                (string)name[i]->query("unit"),MONEY_D->price_str(name[i]->query("value")));
	}
	write(list);

	return 1;
}
