inherit ITEM;
#include <task.h>
void create()
{
        set_name("弹珠", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "欧阳克小时候玩的弹珠。\n");
                set("unit", "颗");
               set("owner_name","欧阳克");
               set("owner_id","ouyang ke");
        }
}

