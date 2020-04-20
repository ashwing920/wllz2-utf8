// silver-dan.c - 银丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIW"银丹"NOR, ({ "silver dan", "dan" }) );
        set("no_transfer", 1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        set("no_give",1);
        set("no_get_from",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以内服（use）的银丹。据说具有一种神奇力量。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "粒");
                set("base_weight", 10);
                set("value", 0 );
        }
        setup();
}
void init()
{
        if(environment()==this_player()){
        add_action("do_eat","use");
        }
}
int do_eat(string arg)
{
        object me;
        int pot;
        me =this_player();
        pot = 2000 + random(5000);
        
        if(!id(arg))
        me->add("potential",pot);
        tell_object(me, "你的潜能增加了" + chinese_number(pot) + "点！\n");
        destruct(this_object());
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
