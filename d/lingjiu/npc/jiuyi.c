// NPC jiuyi.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("九翼道人", ({ "jiuyi daoren", "jiuyi"}));
        set("long",@LONG
他是西夏一品堂礼聘的高手,身材高瘦,脸上总是阴沉沉的，
他轻功极高，擅使雷公挡，凭一手雷公挡功夫，成为江湖的一流高手。
LONG
);
        set("title", "西夏一品堂高手");
        set("gender", "男性");
        set("nickname", HIR "雷动于九天之上" NOR);
        set("age", 40);
        set("shen_type",-1);
        set("attitude", "peaceful");

        set("str", 27);
        set("int", 23);
        set("con", 24);
        set("dex", 30);

        set("jing",3500);
        set("max_jing",3500);
        set("neili",8000);
        set("max_neili",8000);
        set("jiali",220);
        set_skill("unarmed",400);
        set_skill("dodge",400);
        set_skill("force",400);
        set_skill("parry",400);
        set_skill("hand",400);
        set_skill("taoism",400);
        set("combat_exp",6400000);
        
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        
}
