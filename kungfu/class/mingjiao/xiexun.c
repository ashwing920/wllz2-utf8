// XieXun.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",@LONG
他是一位身材魁伟异常的的老者，身穿一件白布长袍。他满头黄发，威风
凛凛，真如天神一般，只是两只眼睛并不睁开。
LONG
);

	set("title",HIR"明教护法"NOR);
	set("nickname",HIY"金毛狮王"NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class","fighter");

	set("age", 63);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("shen_type",1);
	set("score", 80000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("buddhism",400);
	set_skill("sword", 400);
	set_skill("blade", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("blade", 400);
	set_skill("unarmed",400);
	set_skill("tulong-daofa",400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("lingxu-bu", 400);
	set_skill("damo-jian", 400);
	set_skill("qishang-quan", 400);
	set_skill("hunyuan-zhang", 400);
	set_skill("literate", 400);
	set_skill("perception",400);

	map_skill("unarmed","hunyuan-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "tulong-daofa");
	map_skill("sword", "damo-jian");
	map_skill("blade", "tulong-daofa");
	prepare_skill("cuff","qishang-quan");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("exert powerup") :),
	}) );
	create_family("明教",34, "法王");
	setup();
	carry_object("/clone/weapon/tulongdao")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	if (interactive(this_player()) && this_player()->query_temp("fighting")){
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

int accept_object(object who, object ob)
{
	object qkbook;
	if ((string)ob->query("id")=="yi xin") {
		if(!query("qk_trigger")) {
		qkbook = new("/clone/book/qiankun_book");
		say("谢逊说道：谢谢你终于让我知道了阳教主的下落，我无以酬谢，这张羊皮就聊表谢意吧。\n"
		"谢逊把" + qkbook->query("name") + "交给了" + who->query("name") + "。\n");
		qkbook->move(who);
		message("channel:rumor",HIM"【武林传奇】某人："+ who->name()+"拿到乾坤大挪移心法了。\n"NOR,users());
		set("qk_trigger", 1);
		}
	}
	return 1;
}
#include "fawang.h"
