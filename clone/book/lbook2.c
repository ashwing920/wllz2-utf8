// lbook2.c

inherit BOOK;
#include <ansi.h>
void create()
{
        set_name("百家姓", ({ "literateb2", "shu2", "book2" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);                              
        else
        { 
                set("unit", "本");
                set("long","读书人必读的百家姓。\n");
                set("value", 2000);
                set("material", "paper");
                set("bcolor", BGRN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill",
                ([
                        "name": "literate",       // name of the skill
                        "exp_required": 100,      // minimum combat experience required
                        "jing_cost":    20,       // jing cost every time study this
                        "difficulty":   25,       // the base int to learn this skill
                        "max_skill":    99,       // the maximum level you can learn
                        "min_skill":    50,       // minimun level required
                ]) );
        }
}
