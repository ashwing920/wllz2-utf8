// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(YEL"铜钱镖"NOR, ({ "tong qianbiao", "biao" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "些");
                set("value", 100);
                set("base_unit", "枚");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", "这是江湖上人人皆知的暗器铜钱镖。\n");
                set("wield_msg", "$N摸出一些铜钱镖，捏在手中就待发出！\n"NOR);
                set("unwield_msg","$N将手里剩下的铜钱镖放进衣兜中。\n"NOR);
        }
        set_amount(100);
        init_throwing(10);
        setup();
}
