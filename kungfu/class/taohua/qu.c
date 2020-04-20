// qu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name( "曲灵风" ,({ "qu lingfeng", "qu" }));
	set("gender", "男性");
	set("age", 46);
	set("long",@LONG
曲灵风是黄药师的大徒弟，也是黄药师最得意的徒儿。他对黄药师一贯忠
心耿耿，尤其是性格古怪，象极了他师父的邪气。他身形修长，相貌英俊
，白衣飘飘，形容潇洒。
LONG
);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 25);
	set("chat_chance", 1);
	set("chat_msg", ({
		"曲灵风说道：“师父疼爱小师妹，他的软猬甲一直由小师妹穿着。”\n",
		"曲灵风自言自语地说道：“这个桃花阵，嗨，不简单！”\n",
	}));

	set("jing",3000);	
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("shen_type",1);

	set("combat_exp",2700000);
	set_skill("music",300);
	set_skill("force", 300);
	set_skill("bibo-shengong", 300);
	set_skill("unarmed", 300);
	set_skill("xuanfeng-leg", 300);
	set_skill("strike", 300);
	set_skill("luoying-zhang", 300);
	set_skill("dodge", 300);
	set_skill("anying-fuxiang", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("luoying-shenjian", 300);
	set_skill("qimen-wuxing",300);
	set_skill("literate", 300);
	set_skill("cuixin-zhang",300);
	set_skill("hand",300);
	set_skill("finger",300);

	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "luoying-shenjian");

	create_family("桃花岛", 2, "弟子");

	set("inquiry", ([
		"桃花岛":   "这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
		"桃花阵":   "往南就是了。",
		"东邪":	 "家师人称东邪！呵呵。",
		"西毒":	 "欧阳锋是与家师并世齐名的高手，人称老毒物。",
		"南帝":	 "听家师说段王爷现在出家当了和尚，法名一灯。",
		"北丐":	 "北丐洪七公是丐帮帮主，现在扬州城外。",
		"黄蓉":	 "她是师父的爱女。",
		"黄药师":   "你要拜访家师？"
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
	if (ob->query_dex() < 20){
		command("say 我派武功讲究轻灵巧捷。");
		command("say 这位"+RANK_D->query_respect(ob)+"可能是白来桃花岛一趟了。");
		return;
	}
	if ((int)ob->query("shen") < 1){
		command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"请回吧。");
		return;
	}
	if (ob->query("gender") == "无性"){
		command("say 师父最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
		return;
	}
	if (ob->query_skill("bibo-shengong",1) <= 200){
		command("say 你进桃花岛之前没去我冯师弟那儿么？");
		return;
	}
	if (ob->query_skill("literate",1) < 100){
		command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
		return;
	}
	command("smile");
	command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
	command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
	command("wield jian");
	return 1;
}
