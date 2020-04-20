inherit NPC;
void create()
{
        set_name("李白", ({ "li bai", "li" }));
        set("long", "太白居士，他看起来满腹经纶。\n");
        set("gender", "男性");
        set("age", 65);
        set_skill("literate", 1500);
        set("max_jing",220);
        set_skill("taoism", 300);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_temp("apply/attack", 280);
        set_temp("apply/defense", 280);
        set_temp("apply/damage", 200);
        set("combat_exp", 1000000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
