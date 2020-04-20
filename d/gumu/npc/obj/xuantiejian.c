// xuantie jian 玄铁重剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( HIC"玄铁重剑"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 50000);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("weapon_prop/strength",20);
                set("wield_str",30);
                set("man_only",1);
                set("wield_msg", HIY"$N嗡的一声从背后抽出玄铁重剑，但见寒气逼人，杀雾迷茫，方圆之内轰然雷声滚滚，肃杀万分。\n"NOR);
                set("long", "此剑长七尺，黝黑黝黑由万年玄铁所铸，沉重无比，无锋无刃，却杀气森然，实乃天下第一神兵。\n");
                set("unwield_msg","$N将玄铁剑插回肩后，杀气顿减。\n" NOR);
        }
        init_sword(150);
        setup();
}
