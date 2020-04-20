// tianlong.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(BLINK HIR"天龙"NOR, ({"tian long","long" }) );
        set("horse_prop/max_life",100);
        set("horse_prop/life",100);
        set("prep", "on");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        	set("value",0);
                set("long", @LONG 
$HIY$这是一条$HIR$天龙$NOR$！$HIW$只有逍遥和神仙才能使用。能让你到达�
文掣龅胤健�$NOR$
LONG
);

	};
	setup();
}

void init()
{
        if(environment() == this_player()){
        	add_action("do_home","home");
        	add_action("do_full","full");
        }
}
int do_home()
{
        object me = this_player();
        
        if(geteuid(me) != "sjzww"
        && geteuid(me) != "elva"
        && !wizardp(me)) {
		tell_object(me,"这是逍遥先生给他的好朋友专用的坐骑，你不是逍遥的朋友无权骑它。\n"
				"天龙看了你一眼，把头一转驾起祥云飞上天去！\n");

	if( (string)me->query_temp("is_riding"))
        		me->delete_temp("is_riding");
        	delete("equipped");
        	this_object()->unequip();
        	destruct(this_object());
        	return 0;
        }
        me->move("/u/bmw/workroom");
        return 1;
}
int do_full()
{
        object me = this_player();
 
        if(geteuid(me) == "elva"){
                me->set("eff_qi",me->query("max_qi"));
                me->set("qi",me->query("eff_qi"));
                me->set("eff_jing",me->query("max_jing"));
                me->set("jing",me->query("eff_jing"));
                me->set("neili",me->query("max_neili"));
                me->set("food",me->max_food_capacity());
                me->set("water",me->max_water_capacity());
                tell_object(me,"你已经恢复到了最佳状态！\n");
                return 1;
        }
        return 0;
}
