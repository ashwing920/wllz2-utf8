// zixia_book.c  紫霞秘芨

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("大乘涅磐功", ({ "mahayana book","book","shu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 1000);
                set("material", "paper");
                set("bcolor", BCYN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":  "mahayana",       // name of the skill
                        "exp_required": 50000,            // minimum combat experience required
                        "jing_cost" :   30,
                        "difficulty":   30,                      // the base int to learn this skill
                        "max_skill":    199,                     // the maximum level you can learn
                        "min_skill":    0                          // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}

