// yu.c 俞莲舟

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("俞岱岩", ({ "yu daiyan", "yu","daiyan" }));
	set("nickname",HIR"活死人"NOR);
	set("long",@LONG
他就是武当七侠之一的俞岱岩，只见他脸色苍白，双唇干枯，
残喘气息，恐怕是伤重所致。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("can_get",1);	

	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",20000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score", 80000);
	set("eff_qi",200);
	set("qi",10);

	set_skill("force", 400);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 400);
	set_skill("unarmed", 400);
	set_skill("taiji-quan", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("taiji-jian", 400);
	set_skill("liangyi-jian", 400);
	set_skill("taoism", 400);
	set_skill("literate", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}) );
	create_family("武当派",3,"弟子");
	setup();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void revive()
{
	if(environment())
	message_vision("$N刚刚醒过来，喘了口气，又晕了过去。\n",this_object());
	unconcious();
}
