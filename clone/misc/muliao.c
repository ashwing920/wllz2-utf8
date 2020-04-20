// paper_seal.c

inherit COMBINED_ITEM;

void create()
{
        set_name("木料", ({"mu liao","wood","liao"}));
        set("long","这是一捆已经削好了，准备做木器用的木料。\n");
        set("unit","捆");
        set("base_unit","捆");
        set("base_weight",20);
        set("value",1500);
        set_amount(2);
}
