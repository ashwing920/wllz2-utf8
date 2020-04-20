
// buddhism-book.c

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("佛法真卷",({ "buddhism book5","book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本走江湖武师写的关于佛法的书籍。\n");
                set("value", 4000);
                set("material", "paper");
                set("bcolor", BYEL);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":  "buddhism",     //name of the skill
                        "exp_required": 50000,  //minimum combat experience required
                        "jing_cost":    50,     // jing cost every time study this
                        "difficulty":   60,     // the base int to learn this skill
                        "min_skill":    149,    // the minimum level you can learn
                        "max_skill":    200,    // the maximum level you can learn
                ]));
        }
}
