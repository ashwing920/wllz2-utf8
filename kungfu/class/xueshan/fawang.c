// fawang.c  金轮法王

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("金轮法王", ({ "jinlun fawang", "fawang", "fawang" }));
	set("long",@LONG
他是雪山寺的护教法王。在雪山寺的地位仅次与掌门人鸠摩智。身穿一件
紫红袈裟，头带僧帽。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score",80000);

	set_skill("longxiang",400);
	set_skill("necromancy",400);
	set_skill("force",400);
	set_skill("xiaowuxiang",400);
	set_skill("dodge",400);
	set_skill("shenkong-xing",400);
	set_skill("unarmed",400);
	set_skill("yujiamu-quan",400);
	set_skill("parry",400);
	set_skill("sword",400);
	set_skill("mingwang-jian",400);
	set_skill("lamaism",400);
	set_skill("literate",400);
	set_skill("staff",400);
	set_skill("xiangmo-chu", 400);
	set_skill("strike",400);
	set_skill("huoyan-dao", 400);
	set_skill("hammer",400);
	set_skill("riyue-lun",400);
	set_skill("magic",400);
	set_skill("essencemagic",400);
	set_skill("dashou-yin",400);
	set_skill("hand",400);
	map_skill("magic","essencemagic");
	map_skill("hammer","riyue-lun");
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "yujiamu-quan");
	map_skill("staff", "xiangmo-chu");
	map_skill("hand", "dashou-yin");
	map_skill("sword","mingwang-jian");
	map_skill("strike","huoyan-dao");
	prepare_skill("hand", "dashou-yin");
	prepare_skill("unarmed", "yujiamu-quan");

	create_family("雪山寺", 2, "护教法王");
	set("class","lama");

	setup();
	carry_object("/d/xueshan/obj/jinlun")->wield();
	carry_object("/d/xueshan/obj/p-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();
	add_money("gold",1);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") != "男性") {
		command("say 修习密宗内功需要纯阳之体。");
		command("say 这位" + RANK_D->query_respect(ob) +"还是请回吧！");
		return;
	}

	if ((string)ob->query("class") != "lama") {
		command("say 我佛门的清规戒律甚多。");
		command("say 这位" + RANK_D->query_respect(ob) +"还是请回吧！");
		return;
	}

	if ((string)ob->query("family/family_name") != "雪山寺"){
		command("say 这位" + RANK_D->query_respect(ob) +"既非本寺弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("lamaism",1)<300) {
		command("say 入我雪山寺，修习密宗心法是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) +"是否还应该多多钻研本门的心法？");
		return;
	}

	command("smile");
	command("say 你就随我学习佛法吧！");
	command("recruit " + ob->query("id"));
}
