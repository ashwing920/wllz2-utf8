// tang fang.c 唐方

#include <ansi.h>

string ask_me();
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("唐方", ({ "tang fang", "tang" }));
	set("long", @LONG
她面容苍白，神情憔悴，清丽的面庞仿佛还带着泪痕。她大约二十有余。
LONG
);
	set("gender", "女性");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("poison",200);
	set_skill("force", 200);
	set_skill("biyun-xinfa", 200);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 200);
	set_skill("unarmed",200);
	set_skill("biye-wu", 200);
	set_skill("parry", 200);
	set_skill("throwing", 200);
	set_skill("zimu-zhen", 200);
	set_skill("literate", 200);
	set_skill("zhuihun-biao",200);
	set_skill("liuxing-dao",200);
	set_skill("wuzhan-mei",200);
	set_skill("sword",200);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("parry","liuxing-dao");
	map_skill("sword","wuzhan-mei");

	create_family("唐门", 7, "传人");


	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.wumei" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
	}) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"唐方幽幽叹口气，轻轻按住琴弦，出神得看着远方的湖面。\n",
		"唐方漫不经心地拨弄了几下琴弦，自言自语道：也不知道萧郎现在是生是死....。\n",
		"唐方轻轻吹了一下渺渺升起的檀香，两行清泪缓缓流下面颊。 \n",
	}) );
	set("inquiry",
		([
			"萧郎" : (: ask_me :)
		]));


	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/tangmen/obj/shuxiu")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 100) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if ((int)ob->query_skill("dodge", 1) < 100) {
		command("say 我的功夫需要身法灵巧才可以随意施展。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在轻功上多下点功夫？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 好吧，我就收下你吧...");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	object me;
	me=this_player();
	if (me->query_temp("marks/萧")){
		return "算了吧，看来你也不知道萧郎的消息，你走吧。\n";
	}
	command("ah " + this_player()->query("id"));
	command("say 你知道萧郎吗！？自从他上次大闹唐门后就失去了消息。\n");
	command("sigh");
	this_player()->set_temp("marks/萧",1);
		return "老太太为这事非常生气，再也不许我见他了。\n";


}

int accept_object(object who, object ob)
{
	object book;

	if ((string)ob->query("name")==HIC"玉佩"NOR) {
		if(!query("yl_trigger")) {
			say("唐方说道：这不是萧郎的玉佩吗？太谢谢你了，虽然没有见到萧郎，\n能见到他的信物，我已经很欣慰了。唐方悠悠地叹了一口气：这里有一本暗器总诀，就算是给你的酬谢吧。\n");
			book = new("/d/tangmen/obj/throwbook");
			message_vision("$N把"+ book->query("name") +"交给了$n。\n",this_object(),who);
			book->move(who);
			set("yl_trigger", 1);
		}
		else say("唐方杏目圆睁，说道：你这个人怎么这样讨厌啊。\n");
		return 1;
	}
	return 0;
}
