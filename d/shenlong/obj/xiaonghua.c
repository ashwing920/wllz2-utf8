#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("雄黄", ({"xionghuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包雄黄,据说可驱百毒，但不可服用。\n");
                set("value", 1000);
        }
        setup();
}
