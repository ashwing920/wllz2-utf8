                
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("杀手令",({"sha shouling","ling"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块出自于杀手盟的杀手令。上面好象(kan)写着什么。\n");
                set("value",0);
                set("material", "iron");
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

        if( arg == "ling" || arg =="sha shouling") {
        if( !me->query("killer_npc")) 
                return notify_fail("杀手令上什么也没写。\n");
        if( me->query("killer_npc")){
                tell_object(me,"杀手令上写着：速将"+ me->query("killer_npc") + me->query("killer_npc_name") +"杀死！\n");
                return 1;
                }
        else return 0;
        }
}
