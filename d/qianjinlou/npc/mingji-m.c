// mingji.c - 名妓

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("冬红", ({ "dong hong","dong"}) );
        set("long", @LONG
她是千金楼里出了名的名妓，在千金楼倍受宠爱。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per", 30);

        set("combat_exp",random(40000)+10000);
	set("shen_type",-1);
        set("env/wimpy", 30);
        set("chat_chance",10);
        set("chat_msg",({
        	(: command("xixi") :),
        }));
        setup();
        
	carry_object("/clone/cloth/green-silk")->wear();
        add_money("silver",5);
}
