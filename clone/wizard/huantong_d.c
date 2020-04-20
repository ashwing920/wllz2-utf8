// huantong-dan.c - 还童丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIC "还童丹" NOR, ({ "huantong dan", "dan" }) );
        set_weight(100);
        set("no_give", 1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get",1);
        set("no_get_from",1);
        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是一颗不可多得的还童丹，听说可以让人年轻。
TEXT
);
                
                set("unit","颗");
                set("value", 0 );
        }
        setup();
}
void init()
{
        if(environment()==this_player()){
        add_action("do_eat","eat");
        }
}
int do_eat(string arg)
{
        object me;
        me = this_player();
        if(!arg ) return 0;
        if(arg == "dan" || arg == "huantong dan"){
        if( me->query("mud_age") <= 86400)
                return notify_fail("你已经不需要还童丹了。\n");
        message_vision("$N拿起一颗$n，慢慢的吞了下去。\n",me,this_object());
        me->add("mud_age", -86400);
        me->add("age", -1);
        tell_object(me, "你看起来好象年轻了许多。\n");
        destruct(this_object());
        }
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
