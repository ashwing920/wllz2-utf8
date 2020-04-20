// hand_book.c

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("棋谱", ({ "qi pu", "pu" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本薄薄的小册，上面密密麻麻的写满了蝇头小楷，横竖棋格。\n");
		set("value", 500);
		set("material", "silk");
		set("bcolor", BCYN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	   "hand",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}
