#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(CYN"柳叶刀"NOR, ({ "Liuye dao","dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄像柳叶般的弯刀，日月教徒的常备武器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(25);
	setup();
}