// zhangfapu.c 昊天掌法谱

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("昊天掌法谱", ({ "zhangfa pu","pu", }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("unit", "本");
		 set("long",
	"这是一本很破旧的书，书里面好象还有一些小人挥舞拳脚的图形。\n",
	 );
	 set("value", 0);
	 set("material", "paper");
	 set("bcolor", BYEL);    // 书的整体颜色
	 set("lcolor", WHT);     // 书的装订线颜色
	 set("fcolor", BWHT);    // 书的标题框颜色
	 set("tcolor", BLK);     // 书的标题颜色
	 set("skill", ([
			"name":	   "haotian-zhang",
			"exp_required" : 10000,
			"jing_cost":  30,
			"difficulty": 20,
			"max_skill":  80
		]) );
	}
}
