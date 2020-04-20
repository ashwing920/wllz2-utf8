// master-bo.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慕容博", ({ "murong bo", "murong", "master" }));
	set("long",@LONG
他是江湖中大名鼎鼎，以一手“以彼之道，还施彼身”闻名天下的慕容博
。已有五十多岁人了，看起来却好象只有四十来岁，身材魁梧，十分健硕。
LONG
);

	create_family("慕容世家",1,"开山祖师");
	set("title",HIY"以彼之道  还施彼身"NOR);
	set("gender", "男性" );
	set("age", 58);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("kar", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("max_neili",12000);
	set("neili",12000);
	set("jiali",600);
	
	set("shen_type",1);
	set("combat_exp",51200000);

	set_skill("force",800); 
	set_skill("sword",800); 
	set_skill("unarmed",800); 
	set_skill("parry",800);
	set_skill("dodge",800);
	set_skill("blade",800);
	set_skill("strike",800);
	set_skill("finger",800);
	set_skill("literate", 800);
	set_skill("canhe-zhi",800);
	set_skill("xingyi-zhang",800);
	set_skill("shenyuan-gong",800);
	set_skill("douzhuanxingyi",800);
	set_skill("murong-sword",800);
	set_skill("murong-zhang",800);
	set_skill("taxue-steps", 800);
	set_skill("murong-daofa",800);

	map_skill("finger", "canhe-zhi");
	map_skill("blade", "murong-daofa");
	map_skill("strike", "xingyi-zhang");
	map_skill("force",  "douzhuanxingyi");
	map_skill("sword",  "murong-sword");
	map_skill("unarmed","murong-zhang");
	map_skill("parry",  "murong-sword");
	map_skill("dodge",  "taxue-steps");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");


	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action :),
		(: exert_function, "protect" :),
		(: exert_function, "recover" :),
	}) );
	
	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/longsword")->wield();
}

void attempt_apprentice(object ob)
{

	if((string)ob->query("family/family_name") != "慕容世家"){
		command("say 这位" + RANK_D->query_respect(ob) + "与我慕容世家毫无瓜葛，何来拜师一说？");
		return;
	}
	if((int)ob->query("betrayer")){
		command("say 我慕容世家，最讨厌象你这种背信弃义的人了。");
		return;
	}
	if((int)ob->query_skill("douzhuanxingyi",1) < 300){
		command("say 依我看，这位" + RANK_D->query_respect(ob) + "的斗转星移大法还未到火候吧？");
		return;
	}
	if((int)ob->query("shen") < 10000 ) {
		command("say 我慕容世家从不与邪魔歪道的人打交道，你还是离开吧！");
		return;
	}

	command("chat# 朗声说道：老夫我又收一良材，大燕兴复指日可待啦！");
	command("chat* haha"); 
	command("recruit " + ob->query("id"));
	ob->set("title","以彼之道 还施彼身");
}
