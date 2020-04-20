// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void create()
{
        set_name("扇子", ({"shan zi", "shan"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一把用来煽炉子的葵扇，已经被长年的炉火熏得一片乌黑了。\n");
                set("unit", "把");
                set("value", 100);
        }
}
