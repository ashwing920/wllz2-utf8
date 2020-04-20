inherit COMBINED_ITEM;

void create()
{
	set_name("迷魂香", ({ "mihun xiang", "yao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一种毒性猛烈的春药，你可以把它倒(pour)在酒水之中使用。\n" );
		set("unit", "包");
		set("base_value", 700);
		set("base_unit", "包");
		set("base_weight", 30);
	}
	set_amount(1);
}
