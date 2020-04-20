// cenqisi.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("岑其斯", ({ "cen qisi", "cen" }));
        set("nickname",HIG"五毒秀士"NOR);
        set("long",@LONG
他就是五毒教的右护法，人称五毒秀士的岑其斯。经常装扮成一个白衣秀
士的模样，没事总爱附庸风雅。
LONG
);
        set("gender", "男性");
        set("age", 38);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing",3000);
        set("neili", 4500);
        set("max_neili",4500);
        set("jiali",200);
        set("combat_exp",800000);

        set_skill("force", 800);
        set_skill("wudu-shengong", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("wudu-bian",800);
        set_skill("wudu-zhang",800);
        set_skill("wudu-xinfa",800);
        set_skill("whip",800);          
        set_skill("guimei-shenfa", 800);
        set_skill("strike",800);
        set_skill("pour",800);
        set_skill("literate",800);
        set_skill("unarmed",800);
        set_skill("poison",800);
	set_skill("hook",800);
//	set_skill("wudu-gou",800);
	
//	map_skill("hook","wudu-gou");
        map_skill("unarmed","wudu-zhang");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "guimei-shenfa");
        map_skill("strike", "wudu-zhang");
        map_skill("parry", "wudu-bian");
        map_skill("whip", "wudu-bian");

        create_family("五毒神教",16,"护法");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/d/wudu/obj/shenyi")->wear();
        add_money("gold",1);

}

void attempt_apprentice(object ob)
{
        command("heihei");
        command("say 想入我五毒神教，能活着走出我五毒密林再说吧！");
}

