#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + HIW "盘龙银绞丝" NOR, ({"yinjiao si", "yinjiao", "si"}));
        set_weight(3800);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", HIW "由穹外陨星中提炼出的神秘金属炼制而成，世所罕见。\n" NOR);
				set("value", 0);
				set("material", "silk");
        }
}

void owner_is_killed()
{
	destruct(this_object());
}