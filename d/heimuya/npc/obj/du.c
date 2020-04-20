                                          inherit ITEM;

void create()
{
        set_name("独孤九剑", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是令狐冲写的一本独孤九剑秘籍。\n");
                set("material", "paper");
                set("skill", ([
                        "name": "dugu-jiujian", // name of the skill
                        "exp_required": 100000,      // minimum combat experience required
                        "jing_cost":    50,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    150     // the maximum level you can learn
                ]) );
        }
}
