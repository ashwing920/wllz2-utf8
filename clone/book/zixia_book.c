// zixia_book.c  紫霞秘芨

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("紫霞密芨", ({ "zixia_book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
//		set("no_drop",1);
		set("long",
			"学紫霞神功。\n");
		set("value", 1000);
		set("material", "paper");
		set("bcolor", BMAG);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	 "zixia-shengong",	   // name of the skill
			"exp_required": 50000,		  // minimum combat experience required
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

