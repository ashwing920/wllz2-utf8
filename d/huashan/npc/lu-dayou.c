// lu-dayou.c

inherit NPC;

void create()
{
	set_name("陆大有", ({ "lu dayou", "lu", "dayou" }) );
	set("nickname", "六猴儿");
	set("gender", "男性");
	set("age", 31);
	set("long",@LONG
陆大有是岳不群的第六位弟子，和令狐冲最是交好。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);

	set("combat_exp", 3500000);
	set("shen_type", 1);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	create_family("华山剑派", 14, "弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	NPC_D->full_init(this_object());
}
