// ding.c 丁春秋

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string *drugs = ({
       "/obj/yao",
       "/obj/yao1",
       "/obj/yao",
       "/obj/yao2",
       "/obj/yao",
       "/obj/yao3",
       "/obj/yao",
});

int give_drug();
string ask_me();
string ask_du1();
string ask_du2();

void create()
{
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", "星宿老怪");
        set("long", @LONG
他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。可是他
看起来形貌清奇，仙风道骨。
LONG
);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("jing",10000);
        set("max_jing",10000);
        set("neili",12000);
        set("max_neili",12000);
        set("jiali",600);
        set("combat_exp", 51200000);

        set("chat_chance_combat",120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "regenerate" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.xue" :),
        }) );

        set_skill("parry", 800);
        set_skill("staff", 800);
        set_skill("poison", 800);
        set_skill("literate",800);
        set_skill("unarmed", 800);
        set_skill("force", 800);
        set_skill("throwing", 800);
        set_skill("dodge", 800);
        set_skill("strike", 800);
        set_skill("claw", 800);
        set_skill("feixing-shu", 800);
        set_skill("zhaixinggong", 800);
        set_skill("chousui-zhang", 800);
        set_skill("sanyin-wugongzhao", 800);
        set_skill("huagong-dafa", 800);
        set_skill("tianshan-zhang", 800);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-wugongzhao");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        map_skill("unarmed","chousui-zhang");
        map_skill("throwing","feixing-shu");
        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-wugongzhao");
        set("book_count", 1);
        set("zhen_count", 1);
        set("san_count", 1);
        set("drug_count",15);
        set("inquiry", ([
                "毒药" : (: give_drug :),
                "毒经" : (: ask_me :),
                "星宿毒经" : (: ask_me :),
                "碧磷针" : (: ask_du1 :),
                "三笑逍遥散" : (: ask_du2 :),
                "逍遥三笑散" : (: ask_du2 :),
        ]));
        create_family("星宿派", 1, "开山祖师");
        setup();
        carry_object("/clone/weapon/staff")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -10000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
        if ((int)me->query("combat_exp") < 100000) {
                command("say 你这点微末道行如何能学到老仙的神妙功夫。");
                return;
        }
        if((int)me->query_skill("zhaixinggong",1) < 400) {
        command("say 摘星功是星宿派的独门绝技之一，依我看，你的摘星功还未到火候呀！");
        return;

        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");

        message_vision("星宿老怪微闭双眼，手捻长须，一副等人拍马(flatter)的样子。\n",
        this_player());
        me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";
        add("book_count", -1);
        ob = new("/clone/book/dujing_2");
        ob->move(this_player());
        message("channel:rumor",HIM"【武林传奇】某人：听说"+ this_player()->name()+"从丁春秋那里得到了「星宿毒经」了！\n"NOR,users());
        return "好吧，这本「星宿毒经」你拿回去好好钻研。";
}
string ask_du1()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        if (this_player()->query_skill("poison",1)<50)
                return "你的毒技火候未到，用不了这种东西。";
        if (query("zhen_count") < 1)
                return "你来晚了，碧磷针都发完了。";
        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/bilinzhen");
        ob->move(this_player());
        message("channel:rumor",HIM"【武林传奇】某人：听说"+ this_player()->name()+"从丁春秋那里得到碧磷针了！\n"NOR,users());
        return "好吧，那你就先用这些针吧。";
}
string ask_du2()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        if (this_player()->query_skill("poison",1)<100)
                return "你的毒技火候未到，用不了这种东西。";
        if (query("san_count") < 1)
                return "你来晚了，现在没什么剩的了。";
        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiaosan");
        ob->move(this_player());
        message("channel:rumor",HIM"【武林传奇】某人：听说"+ this_player()->name()+"从丁春秋那里拿到「三笑逍遥散」了！\n"NOR,users());
        return "好吧，这包毒药你拿回去善加利用吧。";
}
int give_drug()
{
        object drug, me, ob;
        mapping fam;
        me = this_object();
        ob = this_player();

        if((fam = this_player()->query("family")) &&
        fam["family_name"] == "星宿派" && (ob->query_skill("huagong-dafa", 1) > 79)){
        if(me->query("drug_count") >= 1 && !ob->query_temp("drug_give")){
                add("drug_count", -1);
                drug = new("/d/xingxiu" + drugs[random(sizeof(drugs))] );
                drug->move(ob);
                ob->set_temp("drug_give", 1);
                message_vision("$N对$n点了点头，交给$n一小包药粉。\n", me, ob);
                return 1;
        }
        if(ob->query_temp("drug_give"))
                command("say 我不是给过你了吗？");
                else
                command("say 你来晚啦，都被你师兄们拿走了。");
                return 1;
        }
        else return 0;
}
