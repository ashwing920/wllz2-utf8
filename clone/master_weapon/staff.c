//staff for master.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIY"百战"HIW"之棍"NOR,({ "staff for master","staff" }));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 10000000);
		set("material", "iron");
		set("rigidity",2);
		set("zongshi_only",1);
		set("ownmake",1);
		set("no_put",1);
		set("no_get",1);
		set("no_get_from",1);
		set("no_drop",1);
		set("no_beg",1);
		set("no_steal",1);
		set("no_sell",1);
		set("weapon_prop/personality",9);//魅力
		set("weapon_prop/dexerity",-3);//身法
		set("weapon_prop/strength",5);//臂力
		set("weapon_prop/composure",-7);//定力
		set("long", "这是百人道场打造出来的百神之棍，据说是由千人血祭而成，带有一定的灵性。\n");
		set("wield_msg", "$N把$n紧紧的握在手中，顿觉英明神武，杀气逼人。\n");
		set("unwield_msg","$N松开了手中的$n。\n");
	}
	init_staff(800);
	setup();
}
string query_autoload() { return "1"; }