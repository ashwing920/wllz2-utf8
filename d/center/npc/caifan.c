// caifan.c - 菜贩

inherit NPC;

void create()
{
	set_name("菜贩", ({ "cai fan" }) );
	set("long", @LONG
这是一名菜贩，正首着跟前的两个菜筐，等待卖个好价钱。
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
	
	carry_object("/clone/cloth/cao-hat")->wear();	// 装备
	carry_object("/clone/cloth/cloth")->wear();	

	add_money("silver", 10);			// 金钱
}
