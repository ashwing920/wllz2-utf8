// Npc: /kungfu/class/shaolin/xuan-tong.c

inherit NPC;

void create()
{
	set_name("玄痛大师", ({"xuantong dashi","xuantong","dashi",}));
	set("long",@LONG
他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材高大，两手过
膝。双目半睁半闭，却不时射出一缕精光。
LONG
);
	set("nickname", "戒律院主持");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing", 1000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score", 50000);

	set_skill("force", 400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("dodge", 400);
	set_skill("shaolin-shenfa", 400);
	set_skill("parry", 400);
	set_skill("hand", 400);
	set_skill("claw", 400);
	set_skill("club", 400);
	set_skill("staff", 400);
	set_skill("zui-gun", 400);
	set_skill("pudu-zhang", 400);
	set_skill("qianye-shou", 400);
	set_skill("yingzhua-gong", 400);
	set_skill("buddhism", 400);
	set_skill("literate", 400);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "yingzhua-gong");
	map_skill("staff", "pudu-zhang");
	map_skill("club", "zui-gun");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("finger", "nianhua-zhi");

	create_family("少林派", 36, "弟子");

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派"){
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") {
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] ){
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄"){
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈！");
		command("recruit " + ob->query("id"));
	}
	else {
		command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
		return;
	}

	return;
}

