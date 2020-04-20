// bojuan.c
#include <ansi.h>
inherit BOOK;

void create()
{
        set_name("帛卷", ({ "bo juan", "bo", "juan" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("value", 500);
                set("material", "silk");
                set("bcolor", BWHT);    // 书的整体颜色
                set("lcolor", GRN);     // 书的装订线颜色
                set("fcolor", BCYN);    // 书的标题框颜色
                set("tcolor", WHT);     // 书的标题颜色
                set("skill", ([
                        "name": "beiming-shengong",     // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    100,      // the maximum level you can learn
                ]) );
        }
}
