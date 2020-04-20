// biyujian 碧玉剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG"碧玉剑"NOR,({ "biyu jian", "biyu", "sword", "jian" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("value",10000);
		set("treasure",1);
		set("material", "steel");
		set("weapon_prop/intelligence",2);
		set("long", "这是把轻巧的宝剑，剑身上隐隐的透出碧玉之光，当真锋利无比。\n");
		set("wield_msg", HIC "只听见「嗡」地一声，壁光闪现，$N将腰间解下的$n"+HIC"抖得笔直。\n" NOR);
		set("unwield_msg", HIC "碧玉剑幻作一道碧玉之光，「唰」地飞入剑鞘。\n" NOR);
		set("unequip_msg", HIC "碧玉剑幻作一道碧玉之光，「唰」地飞入剑鞘。\n" NOR);
	}
	init_sword(120);
	setup();
}
