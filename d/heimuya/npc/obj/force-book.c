//book.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("太极拳经", ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
                set("value", 500);
                set("material", "paper");
                set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name": "cuff",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    40,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    50      // the maximum level you can learn
                ]) );
        }
}
