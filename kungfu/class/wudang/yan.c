// yan.c 俞岱岩

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("俞岱岩", ({ "yu daiyan", "yu" }));
	set("nickname", "武当三侠");
	set("long",@LONG
他就是张三丰的最不幸的弟子、武当七侠之三的俞岱岩。身穿一件干干净
净的青布长衫。他不过三十出头年纪，双腿残废，张真人命他主持真武剑
阵。
LONG
);
	set("gender", "男性");
	set("age", 31);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jingli", 1000);
	set("max_jingli",1000);
	set("jiali",225);
	set("combat_exp", 2700000);
	set("score", 60000);

	set_skill("force", 300);
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 300);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("literate",300);
	set_skill("taoism",300);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("chat_chance", 1);

	set("chat_msg", ({
		"俞岱岩说道：真武剑阵是恩师的心血。",
		"俞岱岩仰天叹道：哪位巫师能治好我的腿，我也请鸭庄一顿。"
	}));

	create_family("武当派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment() != environment(ob)) return;
	if(((int)ob->query_skill("taiji-shengong", 1) == 0)){
		message_vision(CYN"十三弟子对$N齐声喝道：你这个邪魔外道，敢来真武剑阵？\n\n"NOR,ob);
		message_vision(CYN"真武剑阵顿时启动，高台上剑气纵横，把$N围在中央。\n"NOR,ob);
		message_vision(CYN"十三口长剑齐出，在$N身上划出了十三道口子，鲜血淋漓。\n"NOR,ob);
		say(CYN"\n\n俞岱岩脸现怒容：“邪魔外道，也敢闯真武剑阵！”\n");
		message_vision("俞岱岩居高临下，起手一掌把$N劈落高台。\n\n\n"NOR,ob);
		ob->move("/d/wudang/nanyangong");
		CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s 私闯真武剑阵，念其成长不易，暂免一死！",ob->name(1)));
	}
	return;
}

void attempt_apprentice(object me)
{
	if ((int)me->query("guarded") < 3) {
		command("say " + RANK_D->query_respect(me) +"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)me->query_skill("taiji-shengong", 1) < 100) {
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(me) +"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)me->query("shen") < 1000) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(me) +"是否还做得不够？");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + me->query("id"));
}
