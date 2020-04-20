//qijianpu.c 

#include <ansi.h>

inherit BOOK;

void create()
{
	set_name("天羽奇剑剑谱", ({ "jian pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本天羽奇剑剑谱，上面画着一些纷繁复杂的招式及修练法门。\n");
		set("value", 500);
		set("material", "paper");
		set("bcolor", BMAG);    // 书的整体颜色
		set("lcolor", WHT);     // 书的装订线颜色
		set("fcolor", BWHT);    // 书的标题框颜色
		set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	"tianyu-qijian",	
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost":	30, 	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	150,	// the maximum level you can learn
			"min_skill":	50,	// the minimum level you can learn
		]) );
	}
}
