// yan.c

#include <weapon.h>

inherit BLADE;

int init()
{       
        if(environment()==this_player())
        add_action("do_fire","fire");
}
void create()
{
        set_name("水烟筒", ({"yan tong", "tong"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一支云南人喜爱的水烟筒。你可以(fire)来吸烟。\n");
                set("unit", "个");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N从身后抽出$n握在手中当做武器。\n");
                set("unwield_msg", "$N将手中的$n放了回去。\n");
                set("use_time",5);
        }
        init_blade(20);
        setup();

}
int do_fire(string arg)
{       
        object me;
        me = this_player();

        if(!id(arg)) return 0;
        
        if( query("use_time")){
                message_vision("$N拿起水烟筒咕咕的吸了几口，缓缓的吐出烟雾，只觉的精神好多了。\n",me);
                me->add("jing",20);
                me->add("neili",10);
                if ((int)me->query("jing") > (int)me->query("eff_jing")) me->set("jing",(int)me->query("eff_jing"));
                if ((int)me->query("neili") > (int)me->query("max_neili")) me->set("neili",(int)me->query("max_neili"));
                add("use_time",-1);
                return 1;
        }
        else {
                write("水烟筒已经被抽光了。\n");
                destruct(this_object());
                return 1;
        }
} 
