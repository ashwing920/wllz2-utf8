// liangong-fu.c

inherit ITEM;

void create()
{
        set_name("干净衣服", ({ "ganjing yifu", "ganjing", "yifu", "cloth" }));
        set("long", "这是一件刚刚洗好的干净衣服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        setup();
}
