// zhang.c 张三丰

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_zhang();

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", @LONG
他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。身穿一件污秽
的灰色道袍，不修边幅。身材高大，年满百岁，满脸红光，须眉皆白。
LONG
);
	set("gender", "男性");
	set("age", 96);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("spi",30);
	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.ba" :),
		(: perform_action, "parry.ren" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "protect" :),
	}));

	set("inquiry",([
		"忧心之事":(:ask_zhang():),
		"俞岱岩": "唉，岱岩半身不遂，我只能经常传予真气帮他续命。",
		"黑玉断续膏":"我听说汝阳王府的郡主赵敏就有此药，可惜我从未和汝阳王府的人打交道。",
		"张无忌":"无忌是翠山的孩儿，这孩子自小父母双亡，又身中玄冥之毒......",
	]));

	set_skill("force", 800);
	set_skill("taiji-shengong", 800);
	set_skill("dodge", 800);
	set_skill("tiyunzong", 800);
	set_skill("unarmed", 800);
	set_skill("taiji-quan", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("taiji-jian", 800);
	set_skill("liangyi-jian", 800);
	set_skill("wudang-jian", 800);
	set_skill("taoism", 800);
	set_skill("literate", 800);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/zhenwu-jian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 5) {
		command("say " + RANK_D->query_respect(ob) +
			"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 400) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + "是否还应该在太极神功上多下点功夫？");
		return;
	}

	if ((int)ob->query_skill("taoism", 1) < 400)	{
		command("say 我武当派乃道家武功，高深的武功离不开道学心法。");
		command("say " + RANK_D->query_respect(ob) +"是否还应该多读读道德经？");
		return;
	}
	if ((int)ob->query("shen") < 200000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}
string ask_zhang()
{
	object me;
	me = this_player();
	
	if(me->query("marks/张三丰"))
		return "多谢这位"+ RANK_D->query_respect(me)+"为岱岩寻来了黑玉断续膏。";
	
	if(me->query_temp("ask_zhangsanfeng"))
		return "希望你能早日寻得黑玉断续膏，为岱岩解除痛苦。";
	
	me->set_temp("ask_zhangsanfeng",1);
	return "岱岩自从参加赛刀大会回来之后，就被人打伤，至今仍旧半身不隧，唯有\n"
	"我天天为他传以真气续命。听说汝阳王府的赵敏有一种疗伤圣药“黑玉断续膏”，\n"
	"可以治好岱岩的伤，可是我从未和汝阳王府的人打交道 .....";
}
int accept_object(object who, object ob)
{
	
	if((string)ob->query("name") == HIK"黑玉断续膏"NOR
	&& who->query_temp("ask_zhangsanfeng")
	&& ob->query("give_to") == who
	&& (int)who->query_temp("fight_win_zhao") > 1) {
		message_vision("$N连忙道谢：多谢这位"+ RANK_D->query_respect(who)+"，岱岩的病有的救了。\n",this_object());
		if(!who->query("marks/张三丰")){
			tell_object(who,"由于你替张三丰找到了黑玉断续膏，治好了俞岱岩的伤。\n");
			tell_object(who,"你的潜能增加了 2000 点，江湖威望也有所提高了。\n");
			who->add("learned_points",-2000);
			who->add("weiwang",100);
			who->set("marks/张三丰",1);
			who->delete_temp("ask_zhangsanfeng");
			who->delete_temp("fight_win_zhao");
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)替张三丰找到了黑玉断续膏，得到了一些奖励。",who->name(),who->query("id")));
		}
		return 1;
	}
	return 0;
}
