// xiaoguiz.c

inherit NPC;

void create()
{
        set_name("小桂子", ({ "xiao guizi", "xiao", "guizi" }) );
        set("gender", "无性" );
        set("age", 13);
        set("long",
                "这位小太监在一旁小心侍侯着，手里拿着一包药。\n");
        set("combat_exp",1000000);
        set_skill("unarmed",200);
        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("rascal",200);        
        map_skill("unarmed","rascal");
        set_temp("apply/defense",55);
        set_temp("apply/damage",55);
        set("attitude", "friendly");
        set("rank_info/respect", "小公公");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
                "小桂子说道：公公，再服一剂药，好不好？\n",
                "小桂子道: 再服半剂，多半不打紧。\n",
        }));
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/city2/obj/yaofen");
        add_money("silver",10);
}
