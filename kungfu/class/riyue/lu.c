#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("绿竹翁", ({ "lu zhuweng", "lu",}));
	set("long",@LONG
此人琴棋书画无一不精，尤其善于画竹，武功如何就不得而知了。
LONG
);
	set("title",RED"日月神教朱雀堂坛主"NOR);
	set("gender", "男性");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("combat_exp", 100000);

	set_skill("tianmo-zhang",100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);
	set_skill("piaomiao-shenfa",100);
	 set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	set("inquiry", ([
		"太极拳经": (: ask_me :),
	]));
	set("book_count", 1);
	setup();
}

string ask_me()
 {
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，太级拳经不在我处。";
	add("book_count", -1);
	ob = new("/d/heimuya/npc/obj/force-book");
	ob->move(this_player());
	message("channel:rumor",HIM"【武林传奇】某人："+ this_player()->name()+"拿到太极拳经啦！\n"NOR,users());
	return "好吧，这本「太级拳经」你拿回去好好钻研。";
}

