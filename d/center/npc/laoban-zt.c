// laoban-zt.c - 澡堂老板

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("澡堂老板", ({ "lao ban" }) );
        set("long", @LONG
他是澡堂老板。
LONG
	);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 45);
        set("combat_exp",random(30000)+20000);
	set("shen_type",1);
        set("env/wimpy",10);
	set_skill("unarmed",random(50)); 
	set_skill("parry",random(50));
	set_skill("dodge",random(50));
        setup();      
	carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
}

int accept_object(object who, object ob)
{
      
	if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("$N点头哈腰，对$n说道：这位"+ RANK_D->query_respect(who)+"里面请请！\n",this_object(),who);
		who->set_temp("give_wash_money",1);
		return 1;
                } 
        return 0;
}
