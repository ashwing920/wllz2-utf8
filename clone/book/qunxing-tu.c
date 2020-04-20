// qunxing-tu.c
inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("群星璀璨图", ({ "qunxing tu" ,"tu" ,"book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本描写着天上群星运动的书。\n"
			"但似乎并没有那么简单。\n");
		set("value", 1000);
		set("material", "paper");
		set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
//			  "name":  "beidou-zhen",		   // name of the skill
			  "name":  "array",		   // name of the skill
		  "exp_required":  100,
		 "jing_cost":  10,
		"difficulty":  20,			  // the base int to learn this skill
		 "max_skill":  120
				 ]) );
	}
}

