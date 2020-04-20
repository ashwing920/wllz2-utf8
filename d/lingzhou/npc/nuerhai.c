                                         // nuerhai.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("努儿海", ({ "nu erhai", "nu" }));
        set("title", HIM"西夏一品堂"HIG"接引使"NOR);
        set("gender", "男性");
        set("age", random(10) + 20);
        set("str", 25);
        set("dex", 16);
        set("per", 13);
        set("long", "一个身形极高、鼻子极大，声音阴阳怪气的汉子。\n");

        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);

        set("neili", 1000); 
        set("max_neili", 1000);
        set("jiali", 100);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
