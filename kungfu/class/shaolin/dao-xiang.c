// Npc: /kungfu/class/shaolin/dao-xiang.c

inherit NPC;

string ask_me_1(string name);
string ask_me_2(string name);

void create()
{
	set_name("道相禅师", ({"daoxiang chanshi","daoxiang","chanshi",}));
	set("long",@LONG
他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵刃，身穿
一袭灰布镶边袈裟，似乎有一身武艺。
LONG
);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_jing",1000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp", 800000);
	set("score", 100);

	set_skill("force", 200);
	set_skill("hunyuan-yiqi", 200);
	set_skill("dodge", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("finger", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("blade", 200);
	set_skill("cibei-dao", 200);
	set_skill("parry", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	prepare_skill("finger", "nianhua-zhi");

	create_family("少林派", 39, "弟子");

	set("inquiry", ([
		"铁护腕" : (: ask_me_1, "huwan" :),
		"铁护腰" : (: ask_me_1, "huyao" :),
		"皮手套" : (: ask_me_1, "shoutao" :),
		"皮围脖" : (: ask_me_1, "weibo" :),
		"铁指套" : (: ask_me_1, "zhitao" :),
		"僧鞋"   : (: ask_me_1, "sengxie" :),
		"铁背心" : (: ask_me_2, "beixin" :)
	]));

	set("huju_count", 50);
	set("beixin_count", 5);

	setup();
	carry_object("/d/shaolin/obj/jiedao")->wield();
	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + "你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("huju_count") < 1)
		return "抱歉，你来得不是时候，防具已经发完了。";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("道相给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。不过要记住，防具只可防身练武，不可凭此妨害他人。";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";

	if (query("beixin_count") < 1)
		return "抱歉，你来得不是时候，武器已经发完了。";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("道相给$N一件" + ob->query("name") + "。\n", this_player());

	return "拿去吧。不过要记住，铁背心乃是防身宝物，不可凭此妨害他人。";
}