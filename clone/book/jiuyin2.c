
inherit BOOK;
#include <ansi.h>
void create()
{
	set_name("「九阴真经」下册", ({ "jiuyin zhenjing2","zhenjing2", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		 set("long",
	"这是一本用薄绢写成的书。上书：九阴真经(下)”。\n"
	"笔法清秀脱俗，看来出于女子手笔。\n",
	);
		set("value", 0);
		set("material", "silk");
		set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name":	   "jiuyin-baiguzhao",
			"exp_required": 10000,
			"jing_cost":  30,
			"difficulty": 20,
			"max_skill":  99,
			"min_skill":  0
		]) );
	}
}
