// zhaixing.c 摘星子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long",@LONG
他就是丁春秋的大弟子、星宿派大师兄摘星子。他三十多岁，脸庞瘦削，
眼光中透出一丝乖戾之气。
LONG
);
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp", 6400000);

	set_skill("parry", 400);
	set_skill("staff", 400);
	set_skill("poison", 400);
	set_skill("literate",400);
	set_skill("unarmed", 400);
	set_skill("force", 400);
	set_skill("throwing", 400);
	set_skill("dodge", 400);
	set_skill("strike", 400);
	set_skill("claw", 400);
	set_skill("feixing-shu", 400);
	set_skill("zhaixinggong", 400);
	set_skill("chousui-zhang", 400);
	set_skill("sanyin-wugongzhao", 400);
	set_skill("huagong-dafa", 400);
	set_skill("tianshan-zhang", 400);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	map_skill("unarmed","chousui-zhang");
	map_skill("throwing","feixing-shu");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"炼心弹"	: (: ask_me :),
		"秘籍"	  : (: ask_book :),
		"天山器法"  : (: ask_book :),
	]));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
	carry_object("/d/xingxiu/obj/yao");
	carry_object("/d/xingxiu/obj/yao1");
	carry_object("/d/xingxiu/obj/yao3");
	carry_object("/clone/cloth/cloth")->wear();

}

void attempt_apprentice(object ob)
{
	if(ob->query_skill("zhaixinggong",1) < 300) {
		command("say 摘星功是星宿派的独门绝技之一，依我看，你的摘星功还未到火候呀！");
		return;

	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	set("class", "fighter");
}

string ask_me()
{
	mapping fam;
	object ob,me;
	
	me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";
	if (query("dan_count") < 1)
		return "你来晚了，没有炼心弹了。";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(me);
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s得到了%s！！",
		me->name(),ob->name()+HIM));
		return "这些练心弹够你用的了吧。";
}

string ask_book()
{
	mapping fam;
	object ob,me;
	
	me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(me);
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s得到了%s！！",
		me->name(),ob->name()));
		return "好吧，这本书你拿回去好好看看吧。";
}
