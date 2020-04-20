inherit ITEM;

#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIW"白玉美人像"NOR, ({"meiren xiang" ,"xiang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一个白玉美人像。\n");
                set("unit","个");
                set("owner_name","段誉");
                set("owner_id","duan yu");
        }
}

