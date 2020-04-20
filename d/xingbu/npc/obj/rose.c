// /d/xingbu/npc/obj/rose.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIB "玫瑰花" NOR, ({ "rose" }) );
        set_weight( 400 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一朵盛开的蓝色玫瑰花，据说原产自西方遥远的荷兰国。\n");
                set("unit", "朵");
                set("value", 1000);
		set("material", "flower");
       		set("armor_prop/personality", 2);
		set("armor_type", "head");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}

