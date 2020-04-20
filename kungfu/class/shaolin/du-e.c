// due.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("渡厄", ({ "du e", "e" }) );
        set("title", "少林长老");
        set("gender", "男性");
        set("age", 90);
        set("long",@LONG
这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，如同一段枯木。
LONG
);

        set("attitude", "peaceful");
        set("class", "bonze");

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("jing",2000);
        set("max_jing",1000);
        set("neili",6000);
        set("max_neili",6000);
        set("jiali",80);
        set("combat_exp",6400000);
        set("score", 200000);

	set_skill("unarmed",400);
	set_skill("buddhism",400);
        set_skill("force", 400);
        set_skill("whip", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("hunyuan-yiqi", 400);
        set_skill("riyue-bian", 400);
        set_skill("shaolin-shenfa", 400);
        set_skill("blade", 400);
        set_skill("claw", 400);
        set_skill("club", 400);
        set_skill("cuff", 400);
        set_skill("finger", 400);
        set_skill("hand", 400);
        set_skill("staff", 400);
        set_skill("strike", 400);
        set_skill("sword", 400);
        set_skill("banruo-zhang", 400);
        set_skill("cibei-dao", 400);
        set_skill("damo-jian", 400);
        set_skill("fengyun-shou", 400);
        set_skill("fumo-jian", 400);
        set_skill("jingang-quan", 400);
        set_skill("longzhua-gong", 400);
        set_skill("luohan-quan", 400);
        set_skill("nianhua-zhi", 400);
        set_skill("pudu-zhang", 400);
        set_skill("qianye-shou", 400);
        set_skill("sanhua-zhang", 400);
        set_skill("weituo-gun", 400);
        set_skill("wuchang-zhang", 400);
        set_skill("xiuluo-dao", 400);
        set_skill("yingzhua-gong", 400);
        set_skill("yizhi-chan", 400);
        set_skill("zui-gun", 400);

        map_skill("blade", "cibei-dao");
        map_skill("claw", "longzhua-gong");
        map_skill("club", "wuchang-zhang");
        map_skill("cuff", "luohan-quan");
        map_skill("finger", "nianhua-zhi");
        map_skill("hand", "fengyun-shou");
        map_skill("staff", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
        map_skill("sword", "fumo-jian");
        map_skill("force", "hunyuan-yiqi");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");
        
        create_family("少林派", 35, "弟子");
        assign_apprentice("弟子", 0);

        set("inquiry", ([
                "伏魔刀"         : (: ask_me :),
        ]));
        set("count", random(2)+1);
        setup();
        carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
        object me, ob;
        mapping fam;

        me = this_player();
        ob = this_object();

        if( interactive(me) ) {
                if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
                && fam["generation"] == 36 ) return;

                if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
                && fam["generation"] > 36               
                && me->query("qi") < 50 ) {
                        me->move("/d/shaolin/qyping");
                        me->unconcious();
                        return;
                }

                me->set_temp("3du-ok",1);
                COMBAT_D->do_attack(ob, me, query_temp("weapon") );
                
                me->set_temp("fighter", 1);
                call_out("halt", 10);

                return;
        }

        return;
}

void halt()
{
        command("say 好吧，大家住手！ 看这家伙有什么话要说！");
        command("halt");
}

string ask_me()
{
        object ob;
        
        if ( !this_player()->query_temp("fighter") 
        ||      this_player()->query("combat_exp") < 100000 )
        {
                command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
                this_object()->kill_ob(this_player());
                this_player()->kill_ob(this_object());
        }

        if ( present("fumo dao", this_player()) )
                return RANK_D->query_respect(this_player()) + "宝刀只有一把，而且就在你身上，真是贪得无餍！";

        if ( present("fumo dao", environment()) )
                return RANK_D->query_respect(this_player()) + "宝刀只有一把，而且就在这里任你取走，真是贪得无餍！";

        if ( present("jingang zhao", this_player()) || present("jingang zhao", environment()) )
                return RANK_D->query_respect(this_player()) + "取了金刚罩，就不能再拿伏魔刀，莫要贪得无餍！";

        if (query("count") < 1)
                return "抱歉，你来晚了，伏魔刀已经给人取走了。";

        ob = new("/d/shaolin/obj/fumo-dao");
        ob->move(this_player());

        add("count", -1);

        message_vision("\n渡厄长笑一声，点点头，从身后的树洞里取出伏魔刀交给$N。\n\n", this_player());

        return "你既然能闯进金刚伏魔圈来，必然是当今武林中的非凡人物，这把刀是适逢其主了！";
}
#include "/kungfu/class/shaolin/du.h"
