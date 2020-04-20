//fire.c

#include <ansi.h>;
#include <weapon.h>

inherit STAFF;


void create()
{
        set_name("灯笼", ({"deng long"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long","这是用于夜晚照路的灯笼，到了晚上就可以点(dian)着了。\n");
                set("unit","支");
                set("value",100);
                set("wield_msg","$N把$n握在手中做武器。\n");
                set("unwield_msg","$N把手中紧握的$n松开了。\n");
        }
	init_staff(25);
	setup();

}
void init()
{
	if(environment() == this_player())
        add_action("do_dian", "dian");
        add_action("do_move", "drop");
        add_action("do_move", "put");
}
int do_move(string arg)
{
	object me,obj;
	me = this_player();
	obj = this_object();
	
	if(id(arg)){
		if((int)obj->query("light")) remove_call_out("fire_over");
		if((int)me->query_temp("light")) me->set_temp("light",0);
		return 0;
	}
}
			
int do_dian(string arg)
{
        object me,obj;
        int time;
        me = this_player();
        obj = this_object();
        time = 120;

        if( !arg || arg=="" ) 	
        	return notify_fail("你要点着什么？\n");

        if(id(arg)){
        	if((int)obj->query("light"))
        		return notify_fail("灯笼已经点燃了。\n");

        	if((int)obj->query("light_times") > 1)
        		return notify_fail("这把灯笼已经点不着了。\n");

		tell_room(environment(me), me->name() + "点燃了灯笼，一蓬火光一闪，四周顿时亮了起来。\n",({ me }));
		write("你点燃了灯笼，一蓬火光一闪，四周顿时亮了起来。\n");
		obj->add("light_times",1);
		obj->set("light",1);
		obj->set("value",0);
		obj->set("name",HIY"点燃的灯笼"NOR);
		me->set_temp("light", 1);
		call_out("fire_over",time,me,obj);
		return 1;
	}
}
void fire_over(object ob,object obj)
{
	if(!ob || !obj) return;
	tell_object(ob,HIY"幽幽的，你手中的灯笼火光终于熄灭了！\n"NOR);
	obj->set("light",0);
	ob->set_temp("light",0);
	obj->set("name","灯笼");
}
