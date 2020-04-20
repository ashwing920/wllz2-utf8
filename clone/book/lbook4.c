// literateb4.c 论语

inherit BOOK;

#include <ansi.h>

void create()
{
        set_name("论语", ({ "literateb4", "shu4", "book4"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","一本孔夫子的《论语》。\n");
                set("value", 4000);
                set("material", "paper");
                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                "name": "literate",     // name of the skill
                "exp_required": 10000,  // minimum combat experience required
                "jing_cost":    10,     // jing cost every time study this
                "difficulty":   50,     // the base int to learn this skill
                "max_skill":   149,     // the maximum level you can learn to
                "min_skill":   120,     // minimun level required
                ]) );
        }
}
