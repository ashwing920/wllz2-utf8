// fighter-a.c - 小游侠

#include <ansi.h>

inherit NPC;

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
        "刘","林" });
string *name_words = ({ "文","武","斌","彦","良","志","忠","良","志","忠",
        "孝","雄","龙","明","勇","元","华","宏","胜","进","铭","彬","东","伟" });

void create()
{
        string name;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "xiao youxia","youxia" }) );
        set("title", "小游侠");
        set("long", @LONG
一个小游侠，能在江湖行走，武功肯定不会差。
LONG
);

        set("attitude", "heroism");
        set("gender", "男性" );
        set("age", 18);

        set("combat_exp",30000 + random(20000));
        set("env/wimpy",20);

	set("max_qi",1000);
	set("qi",1000);
	set("neili",500);
	set("max_neili",500);
	set("jiali",20);
	
	set_skill("force",50);
	set_skill("sword",50);
	set_skill("unarmed", 50);
	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("hengshan-sword",30);
	set_skill("huntian-qigong",30);
	set_skill("xiaoyaoyou",30);
	set_skill("banruo-zhang",30);

	map_skill("force", 	"huntian-qigong");
	map_skill("sword", 	"hengshan-sword");
	map_skill("unarmed", 	"banruo-zhang");
	map_skill("parry", 	"henshan-sword");
	map_skill("dodge", 	"xiaoyaoyou");

        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/cloth/xiaoyao-jin")->wear();	
	carry_object("/clone/weapon/sword")->wield();
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "我初涉江湖，并不随便和人打架！\n");
        return 0;
}
