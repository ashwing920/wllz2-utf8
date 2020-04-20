// blade-book.c

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("胡家刀谱残篇",({ "blade book","book"}));
        set_weight(200);
        set("no_give",1);
        set("no_put",1);
        set("no_get_from",1);
        set("no_sell",1);
        set("no_pawn",1);
        set("no_get",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本胡家刀谱的几页残篇。\n");
                set("value", 500);
                set("material", "paper");
                set("bcolor", BYEL);    // 书的整体颜色
                set("lcolor", HIY);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":  "hujia-daofa",         //name of the skill
                        "exp_required": 1000 ,  //minimum combat experience required
                        "jing_cost":    50,// jing cost every time study this
                        "difficulty":   30,        // the base int to learn this skill
                        "min_skill":    0,        // the minimum level you can learn
                        "max_skill":    100,              // the maximum level you can learn
                ]) );
        }
}
