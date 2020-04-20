// yahuan.c 丫鬟

inherit NPC;

void create()
{
        set_name("丫鬟", ({ "ya huan", "ya" }));
        set("gender", "女性");
        set("age", 15);

        set("combat_exp", 4000);
        set("player_waiter",1);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
        setup();

        add_money("silver",3);
        carry_object("/clone/cloth/cloth")->wear();
}
