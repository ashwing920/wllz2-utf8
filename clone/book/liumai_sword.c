//liumai-book.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name( "六脉神剑谱", ({ "pu", "jian pu" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 1000);
                set("material", "paper");
                set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name": "liumai-shenjian",      // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 20+random(20),     // jing cost every time study this
                        "difficulty":   40,     // the base int to learn this skill
                        "max_skill":    100,    // the maximum level you can learn
                ]) );
                set("no_drop",1);
                set("no_sell",1);
                set("no_put",1);
                set("no_get_from",1);
        }
}
void owner_is_killed() { destruct(this_object()); }
