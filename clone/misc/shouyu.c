                
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("手谕",({"shou yu","yu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张官府的手谕。上面好象(kan)写着什么。\n");
                set("value",0);
                set("material","paper");
        }
        setup();
}

void init()
{
        add_action("do_read","kan");
}

int do_read(string arg)
{
        object ob,me;
        
        ob = this_object();
        me = this_player();

        if( arg == "yu" || arg =="shou yu") {
        if( !me->query("killer_npc")) 
                return notify_fail("手谕上什么也没写。\n");
        if( me->query("killer_npc")){
                tell_object(me,"官府手谕上写着：速将"+ me->query("kill_npc") + me->query("kill_npc_name") +"杀死！\n");
                return 1;
                }
        else return 0;
        }
}
