// cong-buqi.c  丛不弃

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("丛不弃", ({ "cong buqi", "cong" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("title", "华山剑宗第十三代弟子");
	set("age", 52);
	set("long",@LONG
丛不弃是华山剑宗高手。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("shen_type",1);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 400);
	set_skill("sword", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("literate", 400);
	set_skill("huashan-sword", 400);
	set_skill("huashan-neigong", 400);
	set_skill("huashan-ken", 400);
	set_skill("huashan-zhangfa", 400);
	set_skill("huashan-shenfa", 400);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	create_family("华山剑派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不想收徒。");
}
