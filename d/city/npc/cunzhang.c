// cunzhang.c 流氓头

inherit NPC;

void create()
{
	set_name("村长", ({ "cunzhang", "zhang" }));
	set("gender", "男性");
	set("age", 50);
	set("long", "他长得一副忠厚老实的样子，他就是桃花村的村长。\n");
	
	set("combat_exp", 10000);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 2);
}

