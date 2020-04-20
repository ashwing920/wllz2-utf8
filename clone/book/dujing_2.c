
inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("『星宿毒经【下册】』", ({ "du jing2", "book2" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "\n		 『星宿毒经【下册】』\n\n");
		set("value", 50);
		set("material", "paper");
		set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill",
		([
			"name":	"poison",	// name of the skill
			"exp_required": 50000,	  // minimum combat experience required
			"jing_cost":	20,	  // jing cost every time study this
			"difficulty":   25,	 // the base int to learn this skill
			"max_skill":	99,	// the maximum level you can learn
			"min_skill":	50,	 // minimun level required
		]) );
	}
	setup();
}
