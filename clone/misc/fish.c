//fish.c
//Design By Robert 蝴蝶君 email:robert_st@263.net

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鲜鱼",({"fish"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long",@LONG
这是一条活蹦乱跳的新鲜鱼儿，你可以用来吃(eat)，也可以将它卖掉。	
LONG
);
                set("value",0);
                set("material","food");
		set("food_remaining",3);
		set("food_supply", 20);
		set("no_sell",1);

        }
        setup();
}
