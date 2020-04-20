// Npc: /kungfu/class/shaolin/da-mo.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("达摩老祖", ({"da mo","da","mo",}));
	set("long",@LONG
他是一位卷发络腮须的天竺老僧，身穿一袭邋遢金丝绣红袈裟。但却满面
红光，目蕴慈笑，眼现智珠，一派得道高僧气势。他就是少林派开山鼻祖
、当今武林的隐世高僧达摩祖师。
LONG
);

	set("title", HIR"少林开山祖师"NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 80);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);
	set("score",200000);

	set_skill("unarmed",800);
	set_skill("buddhism",800);
	set_skill("literate",800);
	set_skill("blade", 800);
	set_skill("claw", 800);
	set_skill("club", 800);
	set_skill("cuff", 800);
	set_skill("dodge", 800);
	set_skill("finger", 800);
	set_skill("force", 800);
	set_skill("hand", 800);
	set_skill("parry", 800);
	set_skill("staff", 800);
	set_skill("strike", 800);
	set_skill("sword", 800);
	set_skill("whip", 800);

	set_skill("banruo-zhang", 800);
	set_skill("cibei-dao", 800);
	set_skill("damo-jian", 800);
	set_skill("fengyun-shou", 800);
	set_skill("fumo-jian", 800);
	set_skill("hunyuan-yiqi", 800);
	set_skill("jingang-quan", 800);
	set_skill("longzhua-gong", 800);
	set_skill("luohan-quan", 800);
	set_skill("nianhua-zhi", 800);
	set_skill("pudu-zhang", 800);
	set_skill("qianye-shou", 800);
	set_skill("sanhua-zhang", 800);
	set_skill("riyue-bian", 800);
	set_skill("shaolin-shenfa", 800);
	set_skill("weituo-gun", 800);
	set_skill("wuchang-zhang", 800);
	set_skill("xiuluo-dao", 800);
	set_skill("yingzhua-gong", 800);
	set_skill("yijinjing", 800);
	set_skill("yizhi-chan", 800);
	set_skill("zui-gun", 800);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 34, "弟子");
	setup();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

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

	if ( ob_fam["generation"] != 36 ){
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当！");
		return;
	}

	if ((ob->query_int() < 40) || (ob->query("PKS") > 3 )) {
		command("say 万事都讲一个缘字。");
		command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}

	if(ob->query_skill("dodge",1)>=300 
	&& ob->query_skill("force",1)>=300 
	&& ob->query_skill("parry",1)>=300 
	&& ob->query_skill("buddhism",1)>=300){
		command("say 老衲又得一可塑之才，真是大畅老怀！");
		name = ob->query("name");
		new_name = "渡" + name[2..3];
		ob->set("name", new_name);
	
		command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派渡字辈弟子！");
		command("recruit " + ob->query("id"));
	}
	else
		command("say 你现在就来找我也太早了点吧！");
	return;
}

