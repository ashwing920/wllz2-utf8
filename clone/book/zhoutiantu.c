// force_book.c 内功心法

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("周天图", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是张周天图,标明了血刀门内功的行走路线。\n");
		set("value", 500);
		set("material", "paper");
		set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": "force",	// name of the skill
			"exp_required": 0,	  // minimum combat experience required
			"jing_cost":	25,	 // jing cost every time study this
			"difficulty":   10,	 // the base int to learn this skill
			"max_skill":	40,	 // the maximum level you can learn
			"min_skill":	9	  // the maximum level you can learn
		]) );
	}
}

