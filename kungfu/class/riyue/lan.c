
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me1();
string ask_me2();

void create()
{
	set_name("蓝凤凰", ({ "lan fenghuang", "lan",}));
	set("long", @LONG
这女子肌肤微黄，双眼极大，黑如点漆。她掌管日月教在苗疆的下属“五
毒神教”，使毒手法诡秘奇特，令人防不胜防。
LONG
);
	set("title",HIC"日月神教五毒圣姑"NOR);        
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
    
	set("combat_exp", 1000000);
	set_skill("unarmed",100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);        
	set_skill("blade", 100);
	set_skill("literate",100);
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
		"迷魂香": (: ask_me1 :),
		"玉箫": (: ask_me2 :),
	]));
	set("book_count", 1);

	setup();
	carry_object("clone/cloth/cloth")->wear();        

}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "女性" ){
		command ("say 对不起，我只收女弟子。");
		return;
	}
	command("say 咦，不错的小女孩嘛，我就收下你了。");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "dancer")
	ob->set("class", "dancer");
	ob->set("title","日月神教五毒圣女");
}
string ask_me1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + 
		"与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，迷魂香不在我处。";
	add("book_count", -1);
	ob = new("/d/heimuya/npc/obj/yao");
	ob->move(this_player());
	return (RANK_D->query_respect(ob) +"可真坏，可要用在你的心上人身上哦。");
}
string ask_me2()
 {
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + 
		"与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，玉箫不在我处。";
	add("book_count", -1);
	ob = new(__DIR__"obj/yuxiao");
	ob->move(this_player());
	return (RANK_D->query_respect(ob) +"宝箫送佳人，你可要好好保管哦。");
}
