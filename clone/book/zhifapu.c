// zhifapu.c 一阳指法谱
// By Lgg,1998.9

inherit BOOK;
#include <ansi.h>

void create()
{
        set_name("一阳指法谱", ({ "zhifa pu","pu", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("unit", "本");
         set("value", 0);
         set("material", "silk");
         set("bcolor", BCYN);    // 书的整体颜色
         set("lcolor", WHT);     // 书的装订线颜色
         set("fcolor", BWHT);    // 书的标题框颜色
         set("tcolor", BLK);     // 书的标题颜色
         set("skill", ([
                        "name":    "sun-finger",
                        "exp_required" : 150000,
                        "jing_cost":  35,
                        "difficulty": 25,
                        "max_skill":  150
                ]) );
        }
        set("no_give", "这样东西不能随便给人。\n");
}
