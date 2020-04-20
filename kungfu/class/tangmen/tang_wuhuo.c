// tang wuhuo.c 唐无火

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("唐无火", ({ "tang wuhuo", "tang" }));
	set("nickname", HIW "不温不火" NOR);
	set("long", @LONG
他是唐门第七代传人中的杰出人物。处事为人八面玲珑，做事稳稳当当，
脾气不急不燥。江湖人称“不温不火”唐大侠。他大约四十有余，笑容可
掬，双目隐有精芒闪烁。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);

	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("poison",200);
	set_skill("force", 200);
	set_skill("biyun-xinfa", 200);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 200);
	set_skill("unarmed",200);
	set_skill("biye-wu", 200);
	set_skill("parry", 200);
	set_skill("throwing", 200);
	set_skill("zimu-zhen", 200);
	set_skill("literate", 200);
	set_skill("zhuihun-biao",200);
	set_skill("liuxing-dao",200);
	set_skill("wuzhan-mei",200);
	set_skill("sword",200);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");

	create_family("唐门", 7, "传人");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 100) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 22) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}
