// master-mu.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慕容复", ({ "murong fu", "murong", "master" }));
	set("long",@LONG
他是慕容世家的少主。他大约二十七八的年纪，身着淡黄轻衫，腰悬长剑
，俊雅清贵，潇洒闲逸。一手“以彼之道，还施彼身”闻名天下，和乔峰
合称“北乔峰，南慕容”。
LONG
);

	create_family("慕容世家", 2, "少主");
	set("rank_info/respect", "少侠");
	set("gender", "男性" );
	set("age", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("kar", 30);

	set("jing",3000);
	set("max_jing",3000);
	set("max_neili",4500);
	set("neili",4500);
	set("jiali",225);
	set("class", "scholar");
	
	set("shen_type",1);
	set("combat_exp",2700000);

	set_skill("force",300); 
	set_skill("sword",300); 
	set_skill("unarmed",300); 
	set_skill("parry",300);
	set_skill("dodge",300);
	set_skill("blade",300);
	set_skill("strike",300);
	set_skill("finger",300);
	set_skill("literate", 300);
	set_skill("canhe-zhi",300);
	set_skill("shenyuan-gong",300);
	set_skill("xingyi-zhang",300);
	set_skill("douzhuanxingyi",300);
	set_skill("murong-sword",300);
	set_skill("murong-zhang",300);
	set_skill("taxue-steps", 300);
	set_skill("murong-daofa",300);

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
	string name,new_name;

	if((int)ob->query("betrayer")){
		command("say 我慕容世家，最讨厌象你这种背信弃义的人了。");
		return;
	}
	if( ((int)ob->query("int") < 25) ) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的悟性还不够高？");
		return;
	} 
	if( ((int)ob->query("dex") < 27) ) {
		command("say 斗转星移讲究的是与身法配合，依我看" + RANK_D->query_respect(ob) + "的身法还不够高？");
		return;
	}
	if( ((int)ob->query_skill("taxue-steps",1) < 100) ) {
		command("say 斗转星移讲究的是与身法配合，依我看" + RANK_D->query_respect(ob) + "的踏雪无痕还不够高？");
		return;
	} 
	if((int)ob->query("shen") < 0 ) {
		command("say 我慕容世家从不与邪魔歪道的人打交道，你还是离开吧！");
		return;
	}

	name = ob->query("name");
	name = replace_string(name,"慕容","");
	switch(strlen(name)){
		case 1:	new_name = "慕容" + name;break;
		case 2:	new_name = "慕容" + name;break;
		case 3: new_name = "慕容" + name[3..4];break;
		case 4: new_name = "慕容" + name[3..4];break;
		default:
	}
	ob->set("name",new_name);
	command("smile");
	command("chat 我慕容世家又增一家将，大燕复国指日可待！哈哈！！");
	command("say 很好，从今日起，你便是我慕容世家的弟子，列入慕容世家的族谱。\n");
	command("recruit " + ob->query("id"));
}
