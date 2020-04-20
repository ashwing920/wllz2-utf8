// thousand-cash.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIW"一千两银票" NOR, ({"thousand-cash", "thousand-silver", 
		"thousand-cash_money", "thousand-silver_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "thousand-cash");
                set("long", "一张面额值一千两银子的银票。\n");
                set("unit", "叠");
                set("base_value", 100000);
                set("base_unit", "张");
                set("base_weight", 3);
        }
        set_amount(1);
}
