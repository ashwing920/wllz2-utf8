// xuanming-zhang 玄冥掌谱

inherit BOOK;

#include <ansi.h>

void create()
{
        set_name("玄冥掌谱", ({ "xuanming zhangpu","book","shu" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","本");
                set("value",10);
                set("material", "paper");
                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色
        }
}
