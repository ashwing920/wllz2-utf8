//Cracked by Kafei
// qiangdao.c 强盗

inherit NPC;

void create()
{
	set_name("强盗", ({ "qiang dao","dao","robber" }) );
	set("gender", "男性");
	set("age", 35+random(5));
	set("long","这家伙满脸杀气，一付凶神恶煞的模样，时不时发出邪恶的阴笑。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );

	set_skill("sword", 20);
	set_skill("blade", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
