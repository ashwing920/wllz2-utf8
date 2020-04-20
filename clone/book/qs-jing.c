// qs-jing 七伤拳经

inherit BOOK;

#include <ansi.h>

void create()
{
        set_name("七伤拳经", ({ "qishang quanjing","book","jing" }));
        set_weight(600);
        set("no_sell",1);
        set("no_pawn",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_put",1);
        set("no_get_from",1);
        set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 500);
                set("material", "paper");
                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name": "qishang-quan",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    99,     // the maximum level you can learn
                        "min_skill":    0,      // the maximum level you can learn
                ]) );
        }
}
