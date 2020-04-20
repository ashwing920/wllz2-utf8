// wusangui.c 吴三桂

inherit NPC;

void create()
{
        set_name("吴三桂", ({ "wu sangui", "wu" }));
        set("age", 58);
        set("gender", "男性");
        set("long", "这就是大名鼎鼎的引清兵入关的平西王---吴三桂\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("dex", 30);
        set("combat_exp", 100000);
        set("shen_type", -1);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("force", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 80);


        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/guanfu")->wear();
}


