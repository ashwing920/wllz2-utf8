// sample master.c code

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("彭有敬", ({"peng youjing", "peng", "youjing"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌钵龙头");
	set("gender", "男性");
	set("age", 50);
	set("long",@LONG
彭有敬是丐帮中净衣派的首领，衣着干净华丽，不象叫化子。他脸上挂着
慈祥的笑容，一双眼睛有摄人心魄的力量。
LONG
);

	set("attitude", "heroism");
	set("class", "beggar");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("jing",3000);
	set("max_jing",3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	
	set("combat_exp",2700000);
	set("score",20000);
	
	set_skill("force", 300);
	set_skill("huntian-qigong", 300);
	set_skill("unarmed", 300);
	set_skill("xianglong-zhang", 300);
	set_skill("dodge", 300);
	set_skill("xiaoyaoyou", 300);
	set_skill("parry", 300);
	set_skill("staff", 300);
	set_skill("begging",300);
	set_skill("training",300);
	set_skill("hand",300);
	set_skill("shexing-diaoshou",300);
	set_skill("blade",300);
	set_skill("liuhe-daofa",300);
	map_skill("hand","shexing-diaoshou");
	map_skill("blade","liuhe-daofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry","xianglong-zhang");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
	return;
}
#include "/kungfu/class/gaibang/gaibang.h"
