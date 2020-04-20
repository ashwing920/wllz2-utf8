// jinsijia.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIY"金丝甲"NOR, ({ "jinsi jia", "jia"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 30000);
		set("material", "leather");
		set("armor_prop/armor", 100);
	}
	setup();
}
void owner_is_killed()
{
	write(HIY"只见眼前金光一闪...好象是.....\n"NOR);
	destruct(this_object());
} 
