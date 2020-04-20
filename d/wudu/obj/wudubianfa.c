//wudubianfa

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name( "五毒鞭法", ({ "shu", "book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 500);
                set("material", "paper");
                set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name": "wudu-bian",    // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   15,     // the base int to learn this skill
                        "min_skill":     0,
                        "max_skill":    30,     // the maximum level you can learn
                ]) );
        }
}
