// jinshe-jian 金蛇剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("真武剑",({ "zhenwu jian", "zhenwu", "sword", "jian" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 600000);
		set("material", "steel");
		set("long", "这是一柄四尺来长的闪闪发光的宝剑，剑匣宽宽大大镶着金丝，
剑身笔直到狰狞到像锐不可当，隐隐透发出一股正气。\n");
		set("wield_msg", HIY "$N一拍剑匣“狰”的一声$n弹出，但见金光闪闪，
寒芒吞吐。 ....$N不由得从心底升起一股杀气。\n" NOR);
		set("unwield_msg", HIY "真武剑幻作一道金光，「唰」地飞入剑鞘。\n" NOR);
		set("unequip_msg", HIY "真武剑幻作一道金光，「唰」地飞入剑鞘。\n" NOR);
	}
	init_sword(100);
	setup();
}
