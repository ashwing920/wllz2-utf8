// tulong-dao.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{

	set_name(HIM"屠龙刀"NOR, ({ "tulong dao","tulong","dao", "blade" }));
	set_weight(35000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("rigidity", 9);
		set("long",@LONG
这是一把浑身发黑的屠龙刀，刀刃间隐隐有血光流动，锋利无匹，当年江
湖中人为此刀，拼得你死我活，是刀中之宝。
LONG
);
		set("value",50000);
		set("weapon_prop/parry", 5);
		set("material", "steel");
		set("wield_msg", HIM"只见黑光一闪，$N手中已提着一把黑沉沉的大刀，正是号称“武林至尊”的宝刀屠龙！\n"NOR);
		set("unwield_msg", HIM"黑光忽灭，$n跃入$N怀中。\n"NOR);
		set("treasure",1);
	}
	init_blade(160);
	setup();
}
