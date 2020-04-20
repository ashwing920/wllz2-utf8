// lin-pingzhi.c

inherit NPC;

#include <ansi.h>;
string ask_job();
void create()
{
	set_name("林平之", ({ "lin pingzhi","lin","pingzhi"}));
	set("gender", "男性");
	set("age", 18);
	set("long",@LONG
林平之是岳不群最小的一个弟子，也是他的东床快婿。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 35);

	set("max_jing",2500);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 120);

	set("combat_exp", 800000);
	set("shen_type", -1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.feilong" :),
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.wushuang" :),
	}) );
	set("inquiry",([
		"深仇大恨": (: ask_job() :),
		"余沧海":"杀父仇人！我一定要亲手砍了这狗贼！！",
		"林震南":"林震南是我家父，莫非你和我家父有交往？",
		"林远图":"你问那么多干什么？",
		"辟邪剑谱":"辟邪剑谱是我家家传宝物！",
		"袈裟":"莫非你是冲着我家家传之物来的？",
	]));

	set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 200);
	set_skill("zixia-shengong",200);
	set_skill("huashan-sword", 200);
	set_skill("huashan-neigong", 200);
	set_skill("huashan-ken", 200);
	set_skill("huashan-zhangfa", 200);
	set_skill("huashan-shenfa", 200);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	create_family("华山剑派", 14, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
void die()
{
	object killer,book;

	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}
	if(userp(killer))
	{
		 book=new("/clone/book/pixie_book");
		 book->move(killer);
		 CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s拿到辟邪剑谱啦！",killer->name()));
	}
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	this_object()->dismiss_team();
	::die();
}
string ask_job()
{
	object me;
	me = this_player();
	
	if(me->query("marks/林平之"))
		return "多谢这位"+ RANK_D->query_respect(me)+"仗义相助，我爹娘在天之灵，也得以安息了。";
	
	if(me->query_temp("ask_linpingzhi"))
		return "唉，家仇未报，武功未成，我还有什么脸面苟且偷生呢？";
	
	me->set_temp("ask_linpingzhi",1);
		return "青城派那帮狗贼，为了夺取我林家家传之物《辟邪剑谱》，杀我镖局上下三十三口。\n"
		"家父为保我性命，与家母双双惨死在恶贼的剑下......我流离失所，幸好为华山派\n"
		"掌门人所收留。近日来，我不断苦练剑法，誓必杀光那帮青城狗贼，为家父报仇雪恨。";
}
int accept_object(object who, object ob)
{
	
	if((string)ob->query("name") == HIR"余沧海的头颅"NOR
	&& who->query_temp("ask_linpingzhi")
	&& ob->query("last_damage_from") == who) {
		message_vision("$N连忙抱拳跪拜道：多谢这位"+ RANK_D->query_respect(who)+"，为了我林家报仇雪恨。\n",this_object());
		command("shout 爹、娘，你们在天之灵可以安息了！！！！");
		if(!who->query("marks/林平之")){
			tell_object(who,"由于你替林平之报仇雪恨，杀死了杀父仇人余沧海。\n");
			tell_object(who,"你的潜能增加了 1000 点，江湖威望也有所提高了。\n");
			who->add("learned_points",-1000);
			who->add("weiwang",100);
			who->set("marks/林平之",1);
			who->delete_temp("ask_linpingzhi");
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)替林平之报仇雪恨，得到了一些奖励。",who->name(),who->query("id")));
		}
		return 1;
	}
	return 0;
}
