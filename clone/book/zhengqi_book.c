// zhengqi_book.c  正气吟

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("正气吟", ({ "zhengqi_book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这是一本薄薄的册页。\n");
		set("value", 1000);
		set("material", "paper");
		set("bcolor", BCYN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	 "zhengqijue",	   // name of the skill
			"exp_required": 10000,		  // minimum combat experience required
								// to learn this skill.
			"jing_cost" :   30,
			"difficulty":   30,			 // the base int to learn this skill
								// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	99,			 // the maximum level you can learn
			"min_skill":	0			   // the maximum level you can learn
								// from this object.
		]) );
	}
}

