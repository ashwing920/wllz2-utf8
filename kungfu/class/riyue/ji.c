#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("计无施", ({ "ji wushi", "ji",}));
	set("nickname", "夜猫子");
	set("long", @LONG
此人天赋异禀，目力特强，行事忽善忽恶，或正或邪，虽然名计无施，其
实却是诡计多端，是个极厉害的人物。
LONG
);
	set("title",HIY"日月神教光明右使"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("sword", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("literate", 200);
	set_skill("force",200);
	set_skill("tianmo-zhang",200);
	set_skill("whip", 200);
	set_skill("tianmo-sword",200);
	set_skill("blade", 200);
	set_skill("tianmo-dao",200);
	set_skill("riyue-bian",200);
	set_skill("piaomiao-shenfa",200);
	set_skill("wuchang-zhang",200);
	set_skill("tianmo-dafa",200);
	set_skill("xixing-force",200);
	set_skill("strike",200);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	map_skill("strike","tianmo-zhang");
	create_family("日月神教",3,"弟子");

	set("inquiry", ([
		"黑木令": (: ask_me :),
	]));
	set("book_count", 1);
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();

}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 20) {
		command("say " + RANK_D->query_respect(ob) +"天资欠聪，难学得我这一身武功。");
		return;
	}
	if (ob->query_dex() < 20) {
		command("say " + RANK_D->query_respect(ob) +"身手不捷，还是另求高师吧。");
		return;
	}
	if ((int)ob->query("shen") > -5000) {
		command("say " + RANK_D->query_respect(ob) +"我日月教乃邪魔外道，你们这些伪君子我们不耻为伍。");
		return;
	}
	if ((int)ob->query_skill("dodge",1) < 100) {
		command("say 习武之人，最主要练好基本功。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在基本招架上多下点功夫？");
		return;
	}
	command("say 好吧，本座就收下你了，今后就跟着本座好好地干。");
	command("recruit " + ob->query("id"));
	ob->set("nickname",HIG"日月神教光明右使座下第子"NOR);
}
string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1) 
		return "你来晚了，黑木令不在我处。";

	add("book_count", -1);
	ob = new("/d/heimuya/npc/obj/heimuling");
	ob->move(this_player());

	return HIY"此牌限时一日，可不能随便交给别人，你好自为知吧。"NOR;
}
void reset()
{
	if(query("book_count") < 1)
		set("book_count", 1);
}
