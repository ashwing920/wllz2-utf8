// liangong-fu.c

inherit ITEM;

void create()
{
        set_name("破衣服", ({ "po yifu", "po", "yifu", "cloth" }));
        set("long", "这是一件被洗破了的衣服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        setup();
}
