                       // book.c

#include <ansi.h>

inherit BOOK;
void setup()
{}

void create()
{

        set_name("葵花宝典", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。\n");
                set("value", 50000);
                set("material", "paper");
                set("no_give",1);
                set("no_put",1);
                set("no_get_from",1);
                set("no_pawn",1);
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set("bcolor",BBLU);    // 书的整体颜色

                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
                set("skill", ([
                        "name":  "kuihua-xinfa",      //name of the skill
                        "exp_required": 4000,   //minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "min_skill":    20,     // the minimum level you can learn
                        "max_skill":    49,     // the maximum level you can learn
                ]) );
        }
}
