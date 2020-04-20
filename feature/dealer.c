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
	string ob_file;
	string *name, last = "";
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return;
	name = keys(goods);
	for(i = 0; i < sizeof(name); i ++) {
	if(what == name[i]->name() || what == (name[i]->query("id")))
	{
		if( stringp(ob_file = name[i]) ) {
			ob = new(ob_file);
			// 不断减少货物，直到剩余个数为零时，从货物列表中删除
			goods[name[i]] --;
			if( goods[name[i]] <= 0 ) {
				map_delete(goods, name[i]);
				last = "最后";
			}
			if( ob->move(me,1) ) {
				write(sprintf("你向%s买下%s一%s%s。\n", this_object()->query("name"),
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
		s = name[i]->name();
		for(j = 0, temp = 0; j < strlen(s) ; j++, temp++) 
			if( (int)s[j] == 27 ) 
				for(temp--; j < strlen(s) && s[j] != 'm'; j++ );
		for(j = temp; j < 20; j++ ) s += " ";
		list += s + sprintf("%-16s 每%s%s"CYN"(现货%s%s)\n"NOR,capitalize(name[i]->query("id")),name[i]->query("unit"),
		MONEY_D->price_str(name[i]->query("value")),chinese_number(goods[name[i]]),name[i]->query("unit"),
		);
	}
	write(list);

	return 1;       
}
