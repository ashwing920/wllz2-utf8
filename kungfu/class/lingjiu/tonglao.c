// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
        set("long",@LONG
她就是「灵鹫宫」的开山祖师，乍一看似乎是个十七八岁的女子，可神情
却是老气横秋。双目如电，炯炯有神，向你瞧来时，自有一股凌人的威严。
LONG
);
        set("title", "灵鹫宫主人");
        set("gender", "女性");
        set("age",19);
        set("nickname", HIR "唯我独尊" NOR);
        set("shen_type",0);
        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);
        set("per", 38);
        set("spi", 30);

        set("jing",10000);
        set("max_jing",10000);
        set("neili",12000);
        set("max_neili",12000);
        set("jiali",600);

        set("combat_exp",51200000);

        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "regenerate" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.feixian" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "hand.duo" :),
        }) );

        set_skill("force", 800);
        set_skill("unarmed", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("hand",800);
        set_skill("strike", 800);
        set_skill("literate",800);
        set_skill("perception",800);
        set_skill("zhemei-shou",800);
        set_skill("liuyang-zhang",800);
        set_skill("yueying-wubu",800);
        set_skill("bahuang-gong", 800);
        set_skill("tianyu-qijian",800);
        set_skill("sword",800);

        map_skill("sword", "tianyu-qijian");
        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry","tianyu-qijian");
        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");
        create_family("灵鹫宫",1, "开山祖师");

        setup();
        carry_object("/clone/food/jiudai");
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/clone/weapon/sword")->wield();

}

void attempt_apprentice(object ob)
{

        if((string)ob->query("gender")!="女性"){
                command("say 你找死啊！");
                return;
        }
        if ((int)ob->query_skill("bahuang-gong", 1) < 400) {
                command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                return;
        }
        if (ob->query_con() < 30) {
                command("say 本门功法极为难练，依我看这位"+ RANK_D->query_respect(ob)+"的根骨似乎还不够啊！");
                return;
        }
        command("say 那好吧！希望你日后能勤练武艺！否则我绝不饶你！");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
        ob->set("class", "dancer");
        return;
}
