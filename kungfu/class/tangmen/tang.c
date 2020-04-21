// tang.c 唐老太太

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("唐老太太", ({ "tang laotai", "tang" }));
	set("nickname", HIW "霹雳夫人" NOR);
	set("long",@LONG
她就是唐门第六代掌门唐老太太，在她的经营下，唐门在江湖中声名更加
显赫。她大约七十有余，一头银发，红光满面。
LONG
);
	set("gender", "女性");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp", 51200000);

	set_skill("poison",800);
	set_skill("force", 800);
	set_skill("biyun-xinfa", 800);
	set_skill("dodge", 800);
	set_skill("qiulinshiye", 800);
	set_skill("strike", 800);
	set_skill("unarmed",800);
	set_skill("biye-wu", 800);
	set_skill("parry", 800);
	set_skill("throwing", 800);
	set_skill("zimu-zhen", 800);
	set_skill("literate", 800);
	set_skill("zhuihun-biao",800);
	set_skill("liuxing-dao",800);
	set_skill("wuzhan-mei",800);
	set_skill("sword",800);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");
	create_family("唐门", 6, "掌门");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.mthy" :),
		(: perform_action, "throwing.dinhun" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("inquiry", ([
		"大闹唐门" : (: ask_me :)
	]));

	setup();
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
	carry_object("/d/tangmen/obj/shujin")->wear();
}

void attempt_apprentice(object ob)
{
	string name,new_name;

	if ((int)ob->query_skill("biyun-xinfa", 1) < 400) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 35) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 唐门又多了一个得力人才，真是可喜可贺。");
	command("recruit " + ob->query("id"));

	name = ob->query("name");
	name = replace_string(name,"唐","");
	switch(strlen(name)){
		case 1:	new_name = "唐" + name;break;
		case 2:	new_name = "唐" + name[1..1];break;
		case 3: new_name = "唐" + name[2..2];break;
		case 4: new_name = "唐" + name[3..3];break;
		default:
	}
	ob->set("name",new_name);
}
string ask_me()
{
	object me;
	me =this_player();
	if (me->query_temp("marks/闹")){
		command("say 你想帮唐方那个死丫头打探消息吗？看我不劈了你");
		command("hit " + me->query("id"));
		return "看来老太婆非得教训你一下不可。\n";
	}
	if (me->query_temp("marks/萧")){
		command("angry " + this_player()->query("id"));
		command("say 难道你想像萧秋水一样来个大闹唐门吗？\n");
		command("heng " + this_player()->query("id"));
		command("say 唐方那个死丫头！\n");
		this_player()->set_temp("marks/闹",1);
		me->delete_temp("marks/萧");
		return"萧秋水已被我关起来了！她别想再见到这个混小子了！\n";
							}
	else{
		return "瓜娃子，你说啥子？老太婆听不懂哦！\n";
	}


}
