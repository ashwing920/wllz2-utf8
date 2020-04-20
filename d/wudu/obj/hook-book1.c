//wudubianfa

#include <ansi.h>

inherit BOOK;

void create()
{
	set_name("钩法上册", ({ "hook book","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 500);
		set("material", "paper");
		set("bcolor", BRED);    // 书的整体颜色
		set("lcolor", WHT);     // 书的装订线颜色
		set("fcolor", BWHT);    // 书的标题框颜色
		set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": "hook",    // name of the skill
			"exp_required": 1,      // minimum combat experience required
			"jing_cost":    20,     // jing cost every time study this
			"difficulty":   25,     // the base int to learn this skill
			"min_skill":     0,
			"max_skill":    49,     // the maximum level you can learn
		]) );
	}
}
