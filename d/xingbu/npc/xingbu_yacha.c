// yacha.c 锦衣侍卫

inherit NPC;

void create()
{
        set_name("刑部衙差", ({ "xingbu yacha", "yacha" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","一个和蔼可亲的中年人，看见他，让你感觉到无论有什么冤情都可以找他帮忙。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp",1000000);
        setup();
    	NPC_D->full_init(this_object());
}

