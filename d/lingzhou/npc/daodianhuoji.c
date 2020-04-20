// daodianhuoji.c

inherit NPC;

void create()
{
	set_name("小伙计", ({ "xiao huoji", "huoji" }));
	set("shen_type", 1);
	set("gender", "男性" );
	set("age", 33);

	set("combat_exp", 400);
	set("attitude", "friendly");
	setup();

	carry_object("/clone/misc/cloth")->wear();
}
