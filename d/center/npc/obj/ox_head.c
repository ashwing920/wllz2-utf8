inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("牛头", ({ "ox head", "head" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块半腐烂的牛头\n");
                set("unit", "块");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        setup();
}
int finish_eat()
{
        object qu;
        set_name("牛头骨", ({"bone"}));
        set("value",0);
        set("long", "一个啃得干干净净的牛头骨\n");
        set_max_encumbrance(10);
        qu = new(__DIR__"maggot");
        qu->move(this_object());
        return 1;
}

int is_container()
{
        if(this_object()->query("name") == "牛头骨" )
                        return 1;
        else  return 0;
}