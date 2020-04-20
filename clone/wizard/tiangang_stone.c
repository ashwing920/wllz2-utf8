// tiangang_stone.c 天罡石

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"天罡石" NOR, ({ "tiangang stone", "stone" }) );
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
一颗具有神奇力量的天罡石，据说(use)可以提高兵器和防具的等级哦！
TEXT
                );
                
                set("unit","些");
                set("base_unit", "颗");
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
        int n;
        me = this_player();
        n = me->query("combat_exp") / 100;

        if(!id(arg)) return 0;
        
        message_vision(HIY"天罡石瞬间发出一道耀眼的光芒，照耀了半边的天际！突然，“嗖”的藏在了$N身上。\n"NOR,me);
        
        if(!me->query("armor") && !me->query("weapon")){
                me->add("combat_exp",n);
                tell_object(me,"恭喜！你的经验增加了"+ chinese_number(n)+"点！\n");
        }
        if( me->query("armor")){
                me->add("armor/lv",1);
                tell_object(me,"恭喜，你的"+ me->query("armor/name")+"提高了。\n");
        }

        if( me->query("weapon")){
                me->add("weapon/lv",1);
                tell_object(me,"恭喜，你的"+ me->query("weapon/name")+"提高了。\n");
        }

        destruct(this_object());
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
