// yunvjing1.c 玉女心经上
// By Lgg,1998.9


inherit BOOK;
#include <ansi.h>

void create()
{
	set_name( "玉女心经上册", ({ "jing1", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("unit", "本");
		 set("long",
	"这是一本写在薄绢上的书。封面上写着 玉女心经「上」。\n",
	 );
	 set("value", 0);
	 set("material", "silk");
	 set("bcolor", BBLU);    // 书的整体颜色
         set("lcolor", WHT);     // 书的装订线颜色
         set("fcolor", BWHT);    // 书的标题框颜色
	 set("tcolor", BLK);     // 书的标题颜色
	 set("skill", ([
			"name":	   "yunv-xinfa",
			"exp_required" : 3000,
			"jing_cost":  30,
			"difficulty": 20,
			"max_skill":  60
		]) );
	}
}

