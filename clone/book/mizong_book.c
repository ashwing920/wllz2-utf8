// 密宗心经

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name( "密宗心经", ({ "jing" , "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册密宗心经,记载着佛学的要旨。\n");
		set("value", 0);
		set("material", "paper");
		set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": "lamaism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 30+random(20),// jing cost every time study this
			"difficulty":   20,	 // the base int to learn this skill
			"max_skill":	99,	 // the maximum level you can learn
		]) );
	}
}

