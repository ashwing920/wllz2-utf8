// yijinjing.c

inherit BOOK;
#include <ansi.h>


void create()
{
	set_name("易筋经", ({ "yijinjing" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long",
		"易筋经\n"
		"这是一卷古朴丝织经轴，看来很有年月了，上面文字坚深，不知你识
也不识。易筋经是少林镇寺之宝 ，一直妥藏此处。\n");
		set("value", 10);
		set("material", "silk");
		set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":		"yijinjing",	// name of the skill
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	200	// the maximum level you can learn
		]) );
	}
}
