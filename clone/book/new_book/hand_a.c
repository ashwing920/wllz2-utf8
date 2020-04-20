// hand-book.c

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("手法入门",({"hand book","book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本走江湖武师写的关于内功心法的书籍。\n");
                set("value", 1500);
                set("material", "paper");
                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":  "hand",       //name of the skill
                        "exp_required": 1 ,        //minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   10,        // the base int to learn this skill
                        "min_skill":    0,              // the minimum level you can learn
                        "max_skill":    19              // the maximum level you can learn
                ]) );
        }
}
