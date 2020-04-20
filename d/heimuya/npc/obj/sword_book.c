#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("华山剑谱", ({ "sword book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 200);
                set("material", "paper");
                set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":         "sword",
                        "exp_required": 0, 
                        "jing_cost":    30,
                        "difficulty":   30,
                        "max_skill":    60    
                ]) );
        }
}
