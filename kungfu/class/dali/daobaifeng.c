// daobaifeng.c 刀白凤

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("刀白凤", ({ "dao baifeng", "dao" }));
	set("title",  "大理国王妃" );
	set("nickname",  CYN"玉虚散人"NOR );
	set("gender", "女性");
	set("long",@LONG
这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。她本是大
理国皇帝段正淳的正房原配夫人。因恼丈夫风流不羁，沾花惹草，一怒之
下跑到这里出了家。她看起来约三十多岁。
LONG
);
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("force",800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("cuff", 800);
	set_skill("strike", 800);
	set_skill("whip", 800);
	set_skill("kurong-changong", 800);
	set_skill("duanjia-sword", 800);
	set_skill("tiannan-step", 800);
	set_skill("jinyu-quan", 800);
	set_skill("wuluo-zhang", 800);
	set_skill("feifeng-whip", 800);
	set_skill("literate", 800);
	set_skill("finger",800);
	set_skill("liumai-shenjian",800);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "feifeng-whip");
	map_skill("sword", "duanjia-sword");
	map_skill("finger","liumai-shenjian");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	create_family("大理段家",18,"王妃");

	setup();
	
	carry_object("/d/dali/npc/obj/cynrobe")->wear();
	carry_object("/d/dali/obj/fuchen")->wield();

	add_money("silver", 10);

}

void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("dali_title");
	if ((int)ob->query_skill("kurong-changong",1) < 400 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if ((string)ob->query("gender") != "女性")
	{
		command("say 我只收女弟子。");
		return;
	}
	if ((int)ob->query("shen") < 100000  )
	{
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
	if (strsrch(oldtitle, "大理镇南王府") >= 0)
	{
		command("say 很好，既然入我门来就得终身为奴供我驱使。");
		command("recruit " + ob->query("id"));
		ob->set("dali_title", oldtitle);
	}
	else
	{
		command("say 你是何人，如此大胆，假冒我府中厮仆！");
		return;
	}
}

