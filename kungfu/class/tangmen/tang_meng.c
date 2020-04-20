// tang meng.c 唐猛

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐猛", ({ "tang meng", "tang" }));
	set("nickname", HIW "霹雳火" NOR);
	set("long", @LONG
他是唐门第七代传人中的杰出人物。因为脾气火爆，嫉恶如仇。在江湖上
杀不不少大奸大恶之徒，人送外号 霹雳火。他大约三十有余，身材粗壮，
膀阔腰圆,最拿手的功夫是霹雳镖。
LONG
);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 32);

	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 225);
	set("combat_exp", 2700000);

	set_skill("poison",300);
	set_skill("force", 300);
	set_skill("biyun-xinfa", 300);
	set_skill("dodge", 300);
	set_skill("qiulinshiye", 300);
	set_skill("strike", 300);
	set_skill("unarmed",300);
	set_skill("biye-wu", 300);
	set_skill("parry", 300);
	set_skill("throwing", 300);
	set_skill("zimu-zhen", 300);
	set_skill("literate", 300);
	set_skill("zhuihun-biao",300);
	set_skill("liuxing-dao",300);
	set_skill("wuzhan-mei",300);
	set_skill("sword",300);

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

void init()
{
	object ob;

	if(interactive(ob = this_player()) && !is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}
void greeting(object ob)
{
	mapping fam;

	if( !ob || environment(ob) != environment() ) return;
	if (!(fam = ob->query("family")) || fam["family_name"] != "唐门")
		command("say 这里是唐门内堂，不要在这儿胡乱走动");
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000 ){
		command("say 我收徒最注重德行！");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	if (ob->query_str() < 25) {
		command("say 我虽然用的是暗器。");
		command("say 但是我的霹雳镖要求有很强的臂力。");
		command("say " + RANK_D->query_respect(ob) + "在力量上还需要多下功夫。");
		return;
	}
	if ((int)ob->query_skill("biyun-xinfa", 1) < 200) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 25) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 哈哈哈，我就收下你，记住以后要在江湖行侠仗义喔！");
	command("recruit " + ob->query("id"));
}
