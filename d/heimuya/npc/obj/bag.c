#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"百宝袋"NOR, ({ "bai baodai","dai" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "这是一口能装百物的宝袋，可以用来装一些杂物。\n");
		set("value", 1);
	}
}
int is_container() { return 1; }
