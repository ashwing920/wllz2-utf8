// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// xuzhu.c

#include <ansi.h>

inherit NPC;

inherit F_MASTER;

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",@LONG
这是一个二十五六岁的年轻人, 浓眉大眼，大大的鼻子扁平下塌，容貌颇
为丑陋。身穿一件华贵雅致的长袍，倒使他更显几分精神。他就是天山童
姥的救命恩人。
LONG
);
	set("title", "灵鹫宫掌门人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIR "梦郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("score",20000);
	set_skill("force",400);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("hand",400);
	set_skill("strike", 400);
	set_skill("literate",400);
	set_skill("perception",400);
	set_skill("zhemei-shou",400);
	set_skill("liuyang-zhang",400);
	set_skill("yueying-wubu",400);
	set_skill("bahuang-gong", 400);
	set_skill("sword",400);
	set_skill("tianyu-qijian",400);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword","tianyu-qijian");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("灵鹫宫",2, "弟子");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	add_money("silver",10);
}

void attempt_apprentice(object ob)
{
	
	if((int)ob->query_skill("bahuang-gong", 1) < 200) {
	command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
	return;
}  
	if((string)ob->query("gender")=="女性"){
		command("think");
		command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
	return;
	} else {
	command("say 灵鹫宫不收男弟子，这位"+ RANK_D->query_respect(ob)+"还是请回吧！");
	return;
	}
}
