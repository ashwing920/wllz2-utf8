
#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
	set_name("鲍大楚", ({ "bao dachu", "bao",}));
	set("long", @LONG
一个身材瘦削的老者，依相貌根本看不出他是身怀绝艺的高手。
LONG
);
	set("nickname",HIR"日月神教朱雀堂主"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
	
	set("max_jing",3000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",50);
	set("combat_exp", 1000000);


	set_skill("sword", 100); 
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("unarmed",100);
	set_skill("force",100);
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
	create_family("日月神教", 3, "弟子");
	set("inquiry", ([
	      "疗伤" : (: ask_me :),
	]));
	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/cloth/cloth")->wear();          
}

string ask_me()
{
	mapping fam; 

	object ob;
	ob=this_player();

	command("look "+ ob->query("id"));

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";
	if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
		return RANK_D->query_respect(this_player()) + "气血充足，不用医治啊。";
		ob->set("eff_jing", (int)ob->query("max_jing"));
		ob->set("jing", (int)ob->query("max_jing"));
		ob->set("eff_qi", (int)ob->query("max_qi"));
		ob->set("qi", (int)ob->query("max_qi"));
	message_vision(YEL"$N从百汇给$n注入一股内力，$n觉得浑身暖洋洋的，好象失去的气血都回到了身上。\n"NOR,this_object(),ob);
		return "好了你可以走了。"; 

}