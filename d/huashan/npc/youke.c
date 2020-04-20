// guest.c 游客

inherit NPC;

void create()
{
        set_name("游客", ({ "youke" }));
        set("gender", "男性");
        set("age", 20 + random(30));
        set("per",20 + random(30));
        set("kar",20 + random(30));
        set("int",20 + random(30));
        set("dex",20 + random(30));

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("combat_exp", 20000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 5);
}
        
