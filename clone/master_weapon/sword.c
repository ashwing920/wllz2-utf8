//sword for master.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIM"百战"HIW"神剑"NOR,({ "sword for master","sword" }));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
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
		set("weapon_prop/personality",8);//魅力
		set("weapon_prop/dexerity",-6);//身法
		set("weapon_prop/strength",4);//臂力
		set("weapon_prop/composure",-4);//定力
		set("long", "这是百人道场打造出来的百战神剑，据说是由千人血祭而成，带有一定的灵性。\n");
		set("wield_msg", "$N随手从身后抽出一把$n，紧紧的握在手中，顿时杀气大增，灵气逼人。\n");
		set("unwield_msg","$N将手中的$n轻轻插入背上的剑鞘，杀气顿减。\n");
	}
	init_sword(800);
	setup();
}
string query_autoload() { return "1"; }