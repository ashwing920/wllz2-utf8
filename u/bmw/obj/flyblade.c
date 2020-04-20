
// flyblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("柳叶飞刀", ({ "flyblade" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 700);
                set("material", "steel");
                set("long", "这是一把非常薄且杀伤力很高柳叶飞刀。\n");
                set("wield_msg", "$N手中一抖柳叶飞刀已经出现在$N的手中。\n");
                set("unwield_msg", "$N手腕一翻柳叶飞刀已经无影无踪了！。\n");
        }
        init_blade(50);
        setup();
}
