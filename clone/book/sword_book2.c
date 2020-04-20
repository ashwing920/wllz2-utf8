// sword_book.c

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("华山剑谱", ({ "sword book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封面上写著「华山剑法 -- 卷二（进阶）」\n");
		set("value", 1000);
		set("material", "paper");
		set("bcolor", BCYN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": 	"huashan-sword",	// name of the skill
			"exp_required":	1000,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	30,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40			// the maximum level you can learn
								// from this object.
		]) );
	}
}
