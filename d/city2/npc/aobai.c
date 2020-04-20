// aobai.c

inherit NPC;

void create()
{
	set_name("鳌拜", ({"ao bai","ao","bai",}));
	set("long",@LONG
他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，相貌狰狞，太阳
穴高高鼓起，似乎身怀绝世武功。
LONG
);
	set("nickname", "满洲第一勇士");
	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 50);
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 150);
	set("combat_exp", 150000);
	set("score", 50000);

	set_skill("force", 90);
	set_skill("hunyuan-yiqi", 90);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 95);
	set_skill("hand", 100);
	set_skill("parry", 100);
	set_skill("literate", 55);
	set_skill("fengyun-shou", 90);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");

	set("chat_chance_combat", 10);  
	set("chat_msg_combat", ({
		" 鳌拜怒道：你敢不让我睡觉，老子宰了你 ！\n",
		(: command("say 老子宰了你这" + RANK_D->query_rude(this_player())+"!\n") :),
		(: command("pain") :),
	}));
	setup();
	carry_object("/d/city2/obj/anmenkey")->wield();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/d/city2/obj/yaoshi")->wield();
	add_money("gold",2);
}
