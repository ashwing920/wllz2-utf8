// fuling.c 茯苓
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"茯苓"NOR, ({"fuling"}));
        set_weight(500);
        set("unit", "块");
        set("long", "这是一块成型的茯苓，看来可以入药。\n");
        setup();
}

int do_eat(string arg)
{
        if(!id(arg)) return 0;
        write("你三口两口把茯苓吃了下去。\n");
        destruct(this_object());
        return 1;
}
