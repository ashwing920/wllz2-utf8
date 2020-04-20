// bishou.c 匕首

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR"匕首"NOR, ({ "bishou","sword" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "细看那匕首，剑身如墨，无半点光泽。\n");
                set("value", 50000);
                set("no_sell",1);
                set("no_pawn",1);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，只觉一股寒气扑面而来。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘，只听嗤的一声轻响。\n");
        }
        init_sword(50);
        setup();
}
