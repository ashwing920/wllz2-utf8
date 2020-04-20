//jiumozhi.c 鸠摩智

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("鸠摩智", ({ "jiumo zhi", "zhi" ,"ming wang","jiu"}));
        set("nickname", HIG "大轮明王" NOR);
        set("long",@LONG
他就是雪山寺的掌门，人称大轮明王的鸠摩智。他对佛法有精深的研究。
身穿一件大红袈裟，头带僧帽。
LONG
);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);

        set("jing",10000);
        set("max_jing",10000);
        set("neili",12000);
        set("max_neili",12000);
        set("jiali",600);
        set("combat_exp",51200000);

        set_skill("longxiang",800);
        set_skill("necromancy",800);
        set_skill("force",800);
        set_skill("xiaowuxiang",800);
        set_skill("dodge",800);
        set_skill("shenkong-xing",800);
        set_skill("unarmed",800);
        set_skill("yujiamu-quan",800);
        set_skill("parry",800);
        set_skill("sword",800);
        set_skill("mingwang-jian",800);
        set_skill("lamaism",800);
        set_skill("literate",800);
        set_skill("staff",800);
        set_skill("xiangmo-chu", 800);
        set_skill("strike",800);
        set_skill("huoyan-dao", 800);
        set_skill("hammer",800);
        set_skill("riyue-lun",800);
        set_skill("magic",800);
        set_skill("essencemagic",800);
        set_skill("dashou-yin",800);
        set_skill("hand",800);
        map_skill("strike","huoyan-dao");
        map_skill("magic","essencemagic");
        map_skill("hammer","riyue-lun");
        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "yujiamu-quan");
        map_skill("staff", "xiangmo-chu");
        map_skill("hand", "dashou-yin");
        map_skill("sword","mingwang-jian");
        prepare_skill("hand", "dashou-yin");
        prepare_skill("unarmed", "yujiamu-quan");

        create_family("雪山寺", 1, "掌门");
        set("class","lama");

        setup();

        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/xiangmo-chu")->wield();
        add_money("silver",50);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +"还是请回吧！");
                return;
        }

        if ((string)ob->query("class") != "lama") {
                command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +"还是请回吧！");
                return;
        }
        if ((string)ob->query("family/family_name") != "雪山寺"){
                command("say 这位" + RANK_D->query_respect(ob) +"既非本寺弟子，还是请回吧！");
                return;
        }

        if ((int)ob->query_skill("lamaism",1)<400) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +"是否还应该多多钻研本门的心法？");
                return;
        }

        command("chat 哈哈哈哈！！！！！我雪山寺真是后继有人，真是可喜可贺。");
        command("recruit " + ob->query("id"));

}
