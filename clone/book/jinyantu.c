
// jinyantu.c 金雁图谱
// By Lgg,1998.9


inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("金雁图谱", ({ "jinyan tu","tu", }));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("unit", "本");
		 set("long",
	"这是本很普通的书，书里面好象有一些小人飞舞的图形。\n",
	 );
	 set("value", 0);
	 set("material", "paper");
	 set("bcolor", BRED);    // 书的整体颜色
         set("lcolor", WHT);     // 书的装订线颜色
         set("fcolor", BWHT);    // 书的标题框颜色
	 set("tcolor", BLK);     // 书的标题颜色
	 set("skill", ([
			"name":	   "jinyan-gong",
			"exp_required" : 10000,
			"jing_cost":  25,
			"difficulty": 18,
			"max_skill":  60
		]) );
	}
}
