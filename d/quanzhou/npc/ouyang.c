// 欧阳詹

inherit NPC;

void create()
{
	set_name("欧阳詹", ({ "ouyang zhan", "zhan", "ouyang"  }));
	set("gender", "男性");
	set("age", 45);
	set("max_jing", 2000);
	set("max_qi", 2000);
	set("neili", 2000);
	set("jiali", 100);
	set_skill("literate", 165);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("chat_chance", 3);
	set("chat_msg", ({
		"欧阳詹说道：知错能改，善莫大焉。\n",
		"欧阳詹说道：尊师重道，礼仪廉耻。 \n",
	}) );
	setup();
}
