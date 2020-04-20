
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("向问天", ({ "xiang wentian", "xiang",}));
	set("long",@LONG
只见他容貌清瘦，颏下疏疏朗朗一丛花白长须，垂在胸前，腰间挂着一把
长剑。
LONG
);
	set("title",HIY"日月神教光明左使"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",2700000);
	set("score", -5000);

	set_skill("sword", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 300);
	set_skill("force",300);
	set_skill("tianmo-zhang",300);
	set_skill("whip", 300);
	set_skill("tianmo-sword",300);
	set_skill("blade", 300);
	set_skill("tianmo-dao",300);
	set_skill("riyue-bian",300);
	set_skill("piaomiao-shenfa",300);
	set_skill("wuchang-zhang",300);
	set_skill("tianmo-dafa",300);
	set_skill("xixing-force",300);
	set_skill("strike",300);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	map_skill("strike","tianmo-zhang");

	create_family("日月神教", 3, "弟子");
	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object letter;
	if(ob->query("name") == "金创药" || ob->query("name") == HIY"金创药"NOR){
		message_vision("向问天对$N说到：谢谢你了，我这封书信给你上黑木崖行个方便。\n",who);
		letter = new("/d/heimuya/npc/obj/shuxin");
		letter->move(who);
		message("channel:rumor",HIM"【武林传奇】某人："+ who->name() +"拿到向问天书信啦！\n"NOR,users());
		return 1;
	}
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 25) {
		command("say " + RANK_D->query_respect(ob) +"天资欠聪，难学得我这一身武功。");
		return;
	}
	if (ob->query_dex() < 25) {
		command("say " + RANK_D->query_respect(ob) +"身手不捷，还是另求高师吧。");
		return;
	}
	if (ob->query_str() < 25) {
		command("say " + RANK_D->query_respect(ob) +"臂力不够，请走吧。");
		return;
	}
	if( ob->query_skill("dodge",1) < 200){
		command("say " + RANK_D->query_respect(ob) +"基本闪躲好象还不够啊？");
		return;
	}
	if ((int)ob->query("shen") > -10000) {
		command("say " + RANK_D->query_respect(ob) +"我日月教乃邪魔外道，你们这些伪君子我们不耻为伍。");
		return;
	}

	command("say 好吧，本座就收下你了，今后就跟着本座好好地干。");
	command("recruit " + ob->query("id"));
	ob->set("nickname",HIG"日月神教光明左使座下弟子"NOR);
}
