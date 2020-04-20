// jianshang.c - 奸商

#include <ansi.h>

inherit NPC;

void create()
{
	int n;
	n = random(3);
	if(n<=1)
	set("title","奸商");
	if(n=2)
	set("title","贪官");
	else
	set("title","富商");		
	set_name(npc_name("男性"), ({ "jian shang" }) );
        set("long", @LONG
他是一个经常出入于青楼寻欢的人。
LONG
);
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 35);
        set("combat_exp",20000+random(30000));
	set("shen_type",-1);

        set("env/wimpy", 30);

	set_skill("unarmed",60); 
	set_skill("parry",60);
	set_skill("dodge",60);

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();	// 装备

        add_money("gold",1);				// 金钱
}
