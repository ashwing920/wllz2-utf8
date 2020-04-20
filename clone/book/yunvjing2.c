// yunvjing2.c 玉女心经下
// By Lgg,1998.9

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("玉女心经下册", ({ "jing2", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("unit", "本");
		 set("long",
	"这是一本写在薄绢上的书。封面上写着 玉女心经「下」。\n",
	 );
	 set("value", 0);
	 set("material", "silk");
	 set("bcolor", BMAG);    // 书的整体颜色
	 set("lcolor", WHT);     // 书的装订线颜色
	 set("fcolor", BWHT);    // 书的标题框颜色
         set("tcolor", BLK);     // 书的标题颜色
	 set("skill", ([
			"name":	   "yunv-xinfa",
			"exp_required" : 65000,
			"jing_cost":  42,
			"difficulty": 32,
			"max_skill":  100
		]) );
	}
}
