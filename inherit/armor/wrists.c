// wrists.c

#include <armor.h>

inherit EQUIP;
void setup()
{
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_WRISTS);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}

varargs void init_glove(int damage, int flag)
{

	set("armor_prop/unarmed_damage", damage);
	set("armor_type", "glove");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}