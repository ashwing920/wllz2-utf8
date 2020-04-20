//xunbu.c 巡捕
#include <ansi.h>

inherit NPC;

void create()
{   
	int iType;

	iType = random(9);

	if(( iType == 1 ) || ( iType == 2 ))
		set_name("铁手", ({ "tie shou","tie" }) );
	else if(( iType == 3 ) || ( iType == 4 ))
		set_name("无情", ({ "wu qing" }) );
	else if(( iType == 5 ) || ( iType == 6 ))
		set_name("追命", ({ "zhui ming" }) );
	else
		set_name("冷血", ({ "leng xue" }) );

	set("title","江南四大名捕之一");
	set("age", random(20) + 20);
	set("gender", "男性");
	set("long","他就是江南四大名捕之一的"+ name() +"。\n");
	set("attitude", "killer");
	set("str", 24);
	set("dex", 46);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance",10);
	set("chat_msg",({
		name()+"得意的说道：江湖上谁不知道我江南名捕"+ name() +"的名字！\n",
		name()+"喝道：哪个小贼让我见到了，我一定不会手下留情。\n",
		name()+"正纳闷：今天怎么没人杀人呀？老子烦死了。\n",
		(: random_move :),
	}));

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("blade", 120);
	set_skill("force", 120);
	set_skill("tiyunzong",120);
	set_skill("taiji-shengong",120);
	set_skill("taiji-dao",120);             
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("blade", "taiji-dao");
	map_skill("parry", "taiji-dao");
	set_temp("is_riding",HIW"烈日马"NOR);
      
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	object ob;

	::init();

	if(objectp(ob = this_player()) 
		&& ob->query("thief") >= 10){
			command("say "+ RANK_D->query_respect(ob)+"，你这个窃贼！今日遇到老子算你倒霉！");
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("听说惯窃%s(%s)被%s逮了个正着，终于锒铛入狱，沦为阶下之囚！",
				ob->name(1),ob->query("id"),name(1)));
		ob->move("/d/xingbu/qiushi1");
		ob->apply_condition("parsion",ob->query("thief") * 10);
	}
}
