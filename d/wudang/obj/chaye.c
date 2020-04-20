// chaye.c
 
#include <ansi.h>

inherit COMBINED_ITEM;
 
void create()
{
	set_name("「女儿香」茶叶", ({ "cha ye","ye"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "才采的「女儿香」茶叶，发出一股淡淡的香气。\n");
		set("unit", "把");
		set("value", 100);
		set("base_unit", "片");
		set("base_weight", 1);
		set("base_value", 0);
		set("material","wood");
	}
	set_amount(10);
}
