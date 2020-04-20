//whip for master.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name(HIG"百战"HIW"之鞭"NOR,({ "whip for master","whip" }));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000000);
		set("material", "iron");
		set("zongshi_only",1);
		set("ownmake",1);
		set("rigidity",2);
		set("no_put",1);
		set("no_get",1);
		set("no_get_from",1);
		set("no_drop",1);
		set("no_beg",1);
		set("no_steal",1);
		set("no_sell",1);
		set("weapon_prop/personality",12);//魅力
		set("weapon_prop/dexerity",-1);//身法
		set("weapon_prop/strength",2);//臂力
		set("weapon_prop/composure",-8);//定力
		set("long", "这是百人道场打造出来的百神之棍，据说是由千人血祭而成，带有一定的灵性。\n");
		set("wield_msg", "$N「唰」的一声从腰间抽出一条$n握在手中，顿觉英明神武，杀气逼人。\n");
		set("unwield_msg","$N将手中的$n收回，缚在腰间。\n");
	}
	init_whip(800);
	setup();
}
string query_autoload() { return "1"; }