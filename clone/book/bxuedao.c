// force_book.c 内功心法

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("碧血刀", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 500);
		set("material", "paper");
                set("bcolor", BGRN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色

		set("skill", ([
			"name": "xue-dao",	// name of the skill
			"exp_required": 0,	  // minimum combat experience required
			"jing_cost":	40,	 // jing cost every time study this
			"difficulty":   20,	 // the base int to learn this skill
			"max_skill":	200,	 // the maximum level you can learn
			"min_skill":   150	  // the maximum level you can learn
		]) );
	}
}


