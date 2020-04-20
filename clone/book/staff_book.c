                                                 // staff_book.c

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name( "杖法通解", ({ "paper" , "shu", "book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本破纸片，上面画着舞杖的小人。\n");
                set("value", 100);
                set("material", "paper");
                set("bcolor", BGRN);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name": "staff",        // name of the skill
                        "exp_required": 10000,  // minimum combat experience required
                        "jing_cost":    40,      // jing cost every time study this
                        "difficulty":   20,      // the base int to learn this skill
                        "max_skill":    99,      // the maximum level you can learn
                ]) );
        }
}
