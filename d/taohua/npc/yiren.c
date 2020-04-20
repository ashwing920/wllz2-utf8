// jianghuyiren.c

#include <ansi.h>

inherit NPC;

string ask_nanshi();
string ask_back();

void create()
{
	set_name("陈阿牛", ({ "chen aniu","chen" }));
	set("title",HIY"江湖卖艺人"NOR);
	set("nickname","一点呆");
	set("long",@LONG
他是一个外地来的江湖艺人，方方正正的脸上一看就知道是个初入江湖的
巴交老实人，这不，想回家也迷路了。
LONG
);
	set("gender", "男性");
	set("age", 33);
	set("attitude", "friendly");
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);

	set("inquiry",([
		"哪里人氏": "我叫陈阿牛，武功镇人氏，此次是来昆明卖艺，赚点银两。\n",
		"家住哪里": "我家就在武功镇旁的小村里。\n",
		"难事": (: ask_nanshi() :),
		"到了吗": (: ask_back() :),
	]));
	
	set("chat_chance",5);
	set("chat_msg",({
		(: random_move() :),
	}));
		

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 10000);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	add_action("do_select","回答");
}
string ask_nanshi()
{
	object me;
	me = this_player();
	
	if(base_name(environment(this_object())) == "/d/village/shack") 
		return "唉，现在的日子越来越难过，家里穷的快揭不开锅了。";

	if(me->query("marks/陈阿牛"))
		return "这位"+ RANK_D->query_respect(me)+"真是一个热心人。";

	if(me->query_temp("ask_chenaniu"))
		return "这位"+ RANK_D->query_respect(me)+"能否做作好事，送俺回武功镇去？"HIC"回答 (yes/no)"NOR;

	command("say 我是武功镇人氏，此次到昆明卖艺，赚点银两回家，没想在这里迷失了方向。");
	command("say 我在这里已经兜了好几天了，一直找不到回家的路。");
	me->set_temp("ask_chenaniu",1);
	return "这位"+ RANK_D->query_respect(me)+"能否做作好事，送俺回武功镇去？"HIC"回答 (yes/no)"NOR;
}
int do_select(string arg)
{
	object me;
	me = this_player();
	
	if(!me->query_temp("ask_chenaniu")) return 0;
		
	if(!arg || arg == "")
		return notify_fail("你是否愿意带"+ name()+"回家？"HIC"回答 (yes/no)\n"NOR);
	else if(arg == "yes"){
		message_vision("$N想了一会，对$n说道：好吧，我就送你一程，你跟我走就是了。\n",me,this_object());
		message_vision("$N连忙道：多谢这位"+ RANK_D->query_respect(me)+"，好人有好报，您真是菩萨再世啊。\n",this_object());
		command("follow "+ me->query("id"));
		delete("chat_chance");
		set_temp("quest_for",me);
		return 1;
	}
	else if(arg == "no"){
		message_vision("$N摇了摇头，说道：我还有要事，这个..这个...改天再说吧。\n",me);
		message_vision("$N点了点头，说道：哦，那不劳烦这位"+ RANK_D->query_respect(me)+"了。\n",this_object());
		return 1;
	}
	else return notify_fail("你是否愿意带"+ name()+"回家？"HIC"回答 (yes/no)\n"NOR);
}
string ask_back()
{
	object me;
	me = this_player();
	
	if(!me->query_temp("ask_chenaniu"))
		return "这位"+ RANK_D->query_respect(me)+"莫非能看穿我的心事？";

	if(base_name(environment(me)) == "/d/village/shack"){
		if(query_temp("quest_for") == me ){
			tell_object(me,"你终于把迷路的陈阿牛送回了家。\n");
			if(!me->query("marks/陈阿牛")){
				tell_object(me,"由于你仗义行善，你的潜能增加了 1000 点。你的江湖威望也有所提高了。\n");
				me->set("marks/陈阿牛",1);
				me->add("weiwang",100);
				me->add("learned_points",-1000);
				me->delete_temp("ask_chenaniu");
				delete_temp("quest_for");
				CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)将迷路的陈阿牛送回了家，得到了一些奖励。",me->name(),me->query("id")));
			}
			return "多谢这位"+ RANK_D->query_respect(me)+"，谢天谢地，终于回到家了。";		
		}
		return "谢天谢地，江湖上好人还是多，我终于到家了。";
	}
	else {
		command("shake "+ me->query("id"));
		return "嗯，这个...这里好像还不是吧。";
	}
}
void reset()
{
	set("chat_chance",5);
	delete_temp("quest_for");
}