// 玩家家丁.c 家丁

inherit NPC;

void create()
{
        set_name("家丁", ({ "jia ding", "jia" }));
        set("gender", "男性");
        set("age", 16);

        set("combat_exp", 3000);
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
