// sleepbag.c

inherit ITEM;

void create()
{
        set_name("睡袋", ({ "sleepbag" }) );
        set_weight( 1500 );
        set_max_encumbrance( 8000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只普通的麻织睡袋，江湖人士用它来在野外露宿。\n");
                set("value", 1000);
        }
}
