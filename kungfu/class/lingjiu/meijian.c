// meijian.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梅剑", ({ "mei jian", "mei"}));
	set("long",@LONG
这是个容貌姣好的女子，瓜子脸蛋。眼如点漆，清秀绝俗。你总觉得在哪
见过她。
LONG
);
	set("gender", "女性");
	set("age", 21);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);

	set("combat_exp",800000);
	set("score", 10000);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("sword",200);
	set_skill("literate",200);
	set_skill("perception",200);
	set_skill("zhemei-shou",200);
	set_skill("liuyang-zhang",200);
	set_skill("tianyu-qijian",200);
	set_skill("yueying-wubu",200);
	set_skill("bahuang-gong",200);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	prepare_skill("sword","tianyu-qijian");

	create_family("灵鹫宫",3,"弟子");

	setup();

	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	add_money("silver",15);
}

void init()
{
	object ob;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "灵鹫宫") {
		message_vision("梅剑冲着$N点点头，微微笑了笑。\n",ob);
		return;
	}
	if (!(string)ob->query("family/family_name")){
		message_vision("梅剑冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender")=="女性"){
		command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
	return;
	}
	else{
	command("say 灵鹫宫不收男弟子，这位"+ RANK_D->query_respect(ob)+"还是请回吧！");
	return;
	}
}
