#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("贾布", ({ "jia bu", "jia",}));
	set("nickname", "黄面尊者");        
	set("long",@LONG
他那一张瘦脸蜡也似黄，两边太阳穴高高鼓起，便如藏了一杖核桃相似。
LONG
);
	set("title",HIY"日月神教风雷堂香主"NOR);        
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_jing",1000);
	set("neili",2000);
	set("max_neili",2000);
	set("jiali",100);
	set("combat_exp",1000000);


	set_skill("sword", 100); 
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("unarmed",100);
	set_skill("whip", 100);
	set_skill("staff", 100);
	set_skill("blade", 100);
	set_skill("force",100);
	set_skill("literate",100);
	set_skill("tianmo-zhang",100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);        
	set_skill("riyue-bian",100);
	set_skill("piaomiao-shenfa",100);
	set_skill("wuchang-zhang",100);
	set_skill("tianmo-dafa",100);
	set_skill("strike",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	map_skill("strike","tianmo-zhang");
	create_family("日月神教", 3, "弟子");
	setup();
	carry_object("/d/heimuya/npc/obj/bi")->wield();
	carry_object("/clone/cloth/cloth")->wear();        

}
int accept_object(object who, object ob)
{
	if(ob->query("name") == "向问天书信"){
		message_vision("贾布对$N说到：你既然有向左使的书信，还不快请进。\n",who);
		who->set_temp("hmy_enter",1);
		return 1;
	}
}
void attempt_apprentice(object ob)
{
	int exp;
	exp = (int)ob->query("combat_exp");
      
	if ((int)ob->query("shen") > 0) {
		command("say " + RANK_D->query_respect(ob) +"我日月教乃邪魔外道，你们这些伪君子我们不耻为伍。");
		return;
	}
	command("say 哈哈！ 那我就收下你吧。");
	command("recruit " + ob->query("id"));
}
