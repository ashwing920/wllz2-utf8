// qinpu.c

inherit BOOK;
#include <ansi.h>

void create()
{
	set_name("黄石谱", ({ "huangshi pu" ,"pu" ,"book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本琴谱，你读着读着，似
乎可以从里面发现一些其他的东西。\n"
			"原来这是一本藏着剑法的琴谱。\n");
		set("value", 1000);
		set("material", "paper");
		set("bcolor", BYEL);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
		set("skill", ([
			"name": "wuyun-jianfa",	// name of the skill
		"exp_required": 100, 
		   "jing_cost": 10,
		  "difficulty": 20,			// the base int to learn this skill
		   "max_skill": 80
				 ]) );
	}
}

