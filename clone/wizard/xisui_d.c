// xisui-dan.c - 洗髓丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIC "洗髓丹" NOR, ({ "xisui dan", "dan" }) );
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
这是可以内服（use）的洗髓丹，它们是只有神仙才拥有的东西。
它可以使你的所有基本属性升级。
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
        me = this_player();
        
        if(!id(arg)) return 0;
        if( me->query("str") <= 35 ) {
                me->add("str", 1);
                tell_object(me, "你的力量升级了！\n");
        }
        if( me->query("int") <= 35 ) {
                me->add("int", 1);
                tell_object(me, "你的悟性升级了！\n");
        }
        if( me->query("dex") <= 35 ) {
                me->add("dex", 1);
                tell_object(me, "你的身法升级了！\n");
        }
        if( me->query("per") <= 35 ) {
                me->add("per", 1);
                tell_object(me, "你的魅力升级了！\n");
        }
        if( me->query("con") <= 35 ) {
                me->add("con", 1);
                tell_object(me, "你的根骨升级了！\n");
        }
        if( me->query("kar") <= 35 ) {
                me->add("kar", 1);
                tell_object(me, "你的运气升级了！\n");
        }
        destruct(this_object());
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
