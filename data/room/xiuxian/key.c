// File(/data/room/xiuxian/key.c) of xiuxian's key
// Create by LUBAN which written by Doing Lu

inherit ITEM;
#include <ansi.h>

string query_autoload() { return "1"; }

void autoload(string param)
{
}


void create()
{
	set_name(YEL "宗姑家的钥匙" NOR, ({"key", "key of xiuxian"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一把用来开启休闲(xiuxian)的钥匙。
。\n");
		set("unit", "把");
		set("no_pawn", 1);
		set("item_make", 1);
		set("value",0);
		set("no_steal",1);
		set("no_get",1);
		set("no_beg",1);
		set("no_put",1);
		set("key_master","xiuxian");
	}
}
