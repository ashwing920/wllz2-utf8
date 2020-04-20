// dao.c 静道师太

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("静道师太", ({ "jingdao shitai","jingdao","shitai"}));
	set("long",@LONG
她是一位中年出家道姑，道冠高拢，慈眉善目。
LONG
);
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);

	set("jing",3000);
	set("max_jing",3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("jingli",1500);
	set("max_jingli", 1500);

	set("combat_exp", 2700000);
	set("score", 1000);

	set_skill("yitian-sword",300);
	set_skill("sword",300);
	set_skill("persuading", 300);
	set_skill("throwing", 300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("parry", 300);
	set_skill("strike", 300);
	set_skill("blade", 300);
	set_skill("literate", 300);
	set_skill("mahayana", 300);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 300);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	map_skill("sword","yitian-sword");

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	command ("say 阿弥陀佛！贫尼不收弟子。\n");
	command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
	return;
}
