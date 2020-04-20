//hua.c 百香花

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"百香花"NOR, ({"hua", "baixiang"}));
	set("unit", "朵");
	set("long", "这是一朵鲜艳的花，花香浓郁异常。\n");
	  set("value",100);
	setup();
}
