// shunvjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIM "淑女剑" NOR, ({ "shunvjian", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",@LONG
这是一口遍体通黑的剑，剑身上用金丝锩着几个字：窈窕淑女，君子好逑！
LONG
);
                set("value", 12000);
                set("material", "steel");
                set("weapon_prop/personality", 25);
                set("woman_only",1);
                set("wield_msg", "$N低叹一声，将$n缓缓抽出剑鞘。\n");
                set("unwield_msg", "$N右手一晃，$n已然回鞘。\n");
        }
        init_sword(100);
        setup();
}
