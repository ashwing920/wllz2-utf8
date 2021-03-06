// Npc: /kungfu/class/shaolin/qing-guan.c

inherit NPC;
void create()
{
	set_name("清观比丘", ({"qingguan biqiu","qingguan","biqiu",}));
	set("long",@LONG
他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含着无穷劲
力。他身穿一袭白布黑边袈裟，似乎身怀武艺。
LONG
);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 25);

	set("max_jing",800);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
	set("score", 100);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("strike", 100);
	set_skill("sanhua-zhang", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "sanhua-zhang");

	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 40, "弟子");

	setup();

	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}



