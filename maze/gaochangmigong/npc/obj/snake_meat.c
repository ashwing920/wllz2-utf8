// bird-meat.c 鸟肉
// 修改：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

#include <weapon.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蟒蛇肉", ({ "snake meat", "meat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块蟒蛇肉。\n");
                set("unit", "块");
                set("value", 10);
                set("food_remaining", 4);
                set("food_supply",80);
        }
        setup();
}

