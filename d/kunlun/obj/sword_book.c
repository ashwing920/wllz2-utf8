// force_book.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"剑谱"NOR, ({ "sword book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这本昆仑山的剑谱，上面只有一些模糊的图画。\n");
                set("value", 70);
                set("material", "paper");
                set("skill", ([
                        "name":          "zhengliangyi-sword",
                        "exp_required": 10000,
                        "jing_cost":     30,
                        "difficulty":   20, 
                        "max_skill":    40,
                ]));
        }
}
