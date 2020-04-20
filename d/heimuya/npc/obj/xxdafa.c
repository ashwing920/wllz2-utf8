// blade-book.c

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("吸星大法",({"xixing-force book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 1500);
		set("material", "paper");
		set("bcolor", BRED);    // 书的整体颜色
		set("lcolor", WHT);     // 书的装订线颜色
		set("fcolor", BWHT);    // 书的标题框颜色
		set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":  "xixing-force",
			"exp_required": 50000,  // minimum combat experience required
			"jing_cost":    60,     // jing cost every time study this
			"difficulty":   30,     // the base int to learn this skill
			"max_skill":    120     // the maximum level you can learn
		]) );
	}
}
