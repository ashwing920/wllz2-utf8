// pang.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("胖头陀", ({ "pang toutuo", "pang" ,"toutuo"}));
	set("title", HIY"神龙教"NOR"左护法");
	set("nickname",HIR "辽东胖尊者" NOR);
	set("long",@LONG
这头陀身材奇高,而且瘦得出奇，脸上皮包骨头,双目深陷，当真便如僵尸
一般。
LONG
);
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);

	set("max_jing",1000);
	set("jing",1000);
	set("combat_exp",100000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("force", 100);
	set_skill("hand", 100);
	set_skill("strike", 100);
	set_skill("staff", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("leg",100);
	set_skill("finger",100);
	set_skill("yixingbu", 100);
	set_skill("jueming-tui",100);
	set_skill("poison",100);
	set_skill("yingxiong-sanzhao",100);
	set_skill("shenlong-bashi", 100);
	set_skill("huagu-mianzhang", 100);
	set_skill("shenlong-xinfa", 100);
	set_skill("shedao-qigong", 100);
	set_skill("sword",100);
	map_skill("finger","yingxiong-sanzhao");
	map_skill("leg","jueming-tui");
	map_skill("staff", "shedao-qigong");
	map_skill("force", "shenlong-xinfa");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixingbu");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");
	create_family("神龙教",2,"弟子");

	set("neili",4000);
	set("max_neili",4000);
	set("jiali", 120);
	set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]) );
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 10);
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") > -0  ) {
		command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
