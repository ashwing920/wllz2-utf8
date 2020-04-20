// huotou.c 伙头

inherit NPC;

void create()
{
        set_name("老汉", ({ "lao han","lao" }));
        set("gender","男性");
        set("long",@LONG
他是负责主人一家大小膳食的老汉，手艺不错。
LONG
);
	set("per",26);
        set("age",62);

        set("combat_exp",20000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
        setup();

        add_money("silver",3);
        carry_object("/clone/cloth/cloth")->wear();
}
        
