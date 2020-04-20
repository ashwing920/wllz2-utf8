// lbook3.c

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("千字文", ({ "literateb3", "shu3", "book3" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long","读书人必读的千字文。\n");
                set("value", 3000);
                set("material", "paper");
                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill",
                ([
                        "name": "literate",       // name of the skill
                        "exp_required": 1000,     // minimum combat experience required
                        "jing_cost":    25,       // jing cost every time study this
                        "difficulty":   30,       // the base int to learn this skill
                        "max_skill":    119,      // the maximum level you can learn
                        "min_skill":    100,      // minimun level required
                ]) );
        }
}
