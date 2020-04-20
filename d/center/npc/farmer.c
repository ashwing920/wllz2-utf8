// farmer.c - 农民
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("农民", ({ "farmer" }) );
	set("long", @LONG
他是一个老实巴交的农民，每天起早摸黑的来到这里。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 35);
	set("str", 30);

	set("combat_exp",10000);
	set("env/wimpy", 30);

	set_skill("unarmed",40); 
	set_skill("parry",40);
	set_skill("dodge",40);
	setup();
	
	carry_object("/clone/cloth/zhu-hat")->wear();
	carry_object("/clone/cloth/suo-cloth")->wear();	
	carry_object("/clone/cloth/cao-boots")->wear();	
	add_money("silver", 10);
}
