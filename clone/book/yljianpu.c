
inherit BOOK;
#include <ansi.h>

void create()
{
	set_name( "云龙剑谱",({ "shu","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本云龙剑谱，封皮上一条长龙在云中若隐若现。\n");
		set("value", 500);
		set("material", "paper");
		set("bcolor", BMAG);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": "yunlong-jian",  //name of the skill
			"exp_required": 10000 , //minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	49,	// the maximum level you can learn
			"min_skill":	20	// the minimum level you can learn
		]) );
	}
}
