// daerba.c  达而巴

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("达而巴", ({ "daerba huofo", "huofo" }));
	set("long",@LONG
他是金轮法王座下的大弟子。深得法王的真传。身穿一件黄色袈裟，头带
僧帽。
LONG
);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",3000);
	set("max_jing", 3000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",225);
	set("combat_exp",2700000);
	set("score", 55000);


	set_skill("longxiang",300);
	set_skill("necromancy",300);
	set_skill("force",300);
	set_skill("xiaowuxiang",300);
	set_skill("dodge",300);
	set_skill("shenkong-xing",300);
	set_skill("unarmed",300);
	set_skill("yujiamu-quan",300);
	set_skill("parry",300);
	set_skill("sword",300);
	set_skill("mingwang-jian",300);
	set_skill("lamaism",300);
	set_skill("literate",300);
	set_skill("staff",300);
	set_skill("xiangmo-chu", 300);
	set_skill("strike",300);
	set_skill("huoyan-dao", 300);
	set_skill("hammer",300);
	set_skill("riyue-lun",300);
	set_skill("magic",300);
	set_skill("essencemagic",300);
	set_skill("dashou-yin",300);
	set_skill("hand",300);
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

	create_family("雪山寺",3,"活佛");
	set("class","lama");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
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

	if ((string)ob->query("family/family_name") != "雪山寺")        {
		command("say 这位" + RANK_D->query_respect(ob) +"既非本寺弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 200) {
		command("say 入我雪山寺，修习密宗心法是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) +"是否还应该多多钻研本门的心法？");
		return;
	}

	command("say 那好！我就收下你了，希望你能勤练武艺，将本寺武艺发扬光大！");
	command("recruit " + ob->query("id"));

}
