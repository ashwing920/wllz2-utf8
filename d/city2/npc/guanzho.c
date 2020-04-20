// guanzho5.c

inherit NPC;

void create()
{
        set_name("观众", ({"guan zhong" }));
        set("long", @LONG
此人相貌奇丑，狮鼻阔口，一望而知不是中土人士。
LONG
);
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 26);
        set("dex", 22);
        
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 5);
        set("combat_exp", 20000);
        set("score", 30000);

        set_skill("dodge", 40);
        set_skill("zhaixinggong", 30);
        set_skill("unarmed", 50);
        set_skill("xingxiu-duzhang", 40);
        set_skill("parry", 60);

        map_skill("dodge", "zhaixinggong");
        map_skill("unarmed", "xingxiu-duzhang");
        map_skill("parry", "xingxiu-duzhang");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
