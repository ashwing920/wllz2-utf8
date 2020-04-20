// dongfang.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("东方不败", ({ "dongfang bubai", "dongfang","master",}));
	set("long", @LONG
他就是武林之中一位惊天动地，威震当世的怪杰。此刻他剃光了胡须，脸
上竟然施了脂粉，身上那件衣衫式样男不男，女不女，颜色之妖，便穿在
少女身上，也显得太娇艳、太刺眼了些。
LONG
);
	set("title",HIY"日月神教掌旗使"NOR);
	set("gender", "无性");
	set("class","eunuch");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
	set("per", 26);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("literate",800);
	set_skill("sword",800);
	set_skill("parry",800);
	set_skill("dodge",800);
	set_skill("whip", 800);
	set_skill("unarmed",800);
	set_skill("blade",800);
	set_skill("force",800);
	set_skill("finger", 800);
	set_skill("kuihua-xinfa",800);
	set_skill("tianmo-dao",800);
	set_skill("riyue-bian",800);
	set_skill("tianmo-dafa", 800);
	set_skill("pixie-jian",800);
	set_skill("changquan", 800);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	set("inquiry", ([
		"葵花宝典": (: ask_me :),
	]));
	set("book_count", 1);
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();

}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "无性" )
	{
		command ("say 哼......你还没有资格做我的徒弟。");
		return;
	}

	command("say 嗯...你可要在日月神教好好干啊！。");
	command("recruit " + ob->query("id"));
	ob->set("class","eunuch");
}
string ask_me()
{
	mapping fam;
	object ob,me;
	me = this_player();
	

	if (!mapp(fam = me->query("family")) 
		|| fam["family_name"] != "日月神教")
		return RANK_D->query_respect(me) + "与本教素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，葵花宝典已经不在我处。";

	add("book_count", -1);
	ob = new("/d/heimuya/npc/obj/kuihua");
	ob->move(me);
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s得到江湖中人梦寐以求的葵花宝典！",
		me->name()));
	return "好吧，这本「葵花宝典」你拿回去好好看看。";
}
