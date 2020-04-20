// tang liang.c 唐亮

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐亮", ({ "tang liang", "tang" }));
	set("nickname", HIW "千手千眼" NOR);
	set("long",@LONG
他是唐门第一高手，传说他可以同时发出一千种不同暗器。也可以同时接
下一千种暗器。他大约五十有余，双手总是笼在袖中。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);

	set("max_jing",3000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali", 300);
	set("combat_exp",6400000);

	set_skill("poison",400);
	set_skill("force", 400);
	set_skill("biyun-xinfa", 400);
	set_skill("dodge", 400);
	set_skill("qiulinshiye", 400);
	set_skill("strike", 400);
	set_skill("unarmed",400);
	set_skill("biye-wu", 400);
	set_skill("parry", 400);
	set_skill("throwing", 400);
	set_skill("zimu-zhen", 400);
	set_skill("literate", 400);
	set_skill("zhuihun-biao",400);
	set_skill("liuxing-dao",400);
	set_skill("wuzhan-mei",400);
	set_skill("sword",400);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");

	create_family("唐门", 6 ,"精益堂堂主");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/zhuyebiao")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 300) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}
