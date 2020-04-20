// gouroutang.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("狗肉汤", ({"gourou tang", "tang"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个满满一碗狗肉汤的大海碗，够喝一气的了。\n");
                set("unit", "碗");
                set("value", 200);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "water",
                "name": "狗肉汤",
                "remaining": 25,
                "drunk_apply": 5,
        ]));
}
