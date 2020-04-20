// chen.c

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("陈有德", ({ "chen youde", "chen" }));
	set("long", "陈有德是扬州武馆馆长。\n");
	set("gender", "男性");
	set("age", 45);

	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("claw", 200);
	set_skill("hand", 200);
	set_skill("strike", 200);
	set_skill("finger", 200);
	set_skill("cuff", 200);

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp",800000);
	set("shen_type",1);
	setup();

}
int accept_object(object who, object ob)
{
	int time;
	if (ob->query("money_id") && ob->value() >= 500)
	{
		time = ob->value();
		if(time > 5000) time = 5000;
		who->set_temp("marks/yangzhou_paied",time);
		message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) + "想学什么呢？\n" , who);
		return 1;
	}
	message_vision("陈有德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
	return 0;
}
int recognize_apprentice(object ob)
{
	if(!ob->query_temp("marks/yangzhou_paied")) return 0;
	ob->add_temp("marks/yangzhou_paied",-1);
	return 1;
}
