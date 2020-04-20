//blade for master.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR"百战"HIW"狂刀"NOR, ({ "blade for master","blade" }));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
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
		set("weapon_prop/personality",10);//魅力
		set("weapon_prop/dexerity",-5);//身法
		set("weapon_prop/strength",4);//臂力
		set("weapon_prop/composure",-5);//定力
		set("long", "这是百人道场打造出来的百战狂刀，据说是由千人血祭而成，带有一定的灵性。\n");
		set("wield_msg", "$N随手从身后抽出一把$n，紧紧的握在手中，顿时杀气大增，灵气逼人。\n");
		set("unwield_msg","$N将手中的$n轻轻插入背上的刀鞘，杀气顿减。\n");
	}
	init_blade(800);
	setup();
}
string query_autoload() { return "1"; }
