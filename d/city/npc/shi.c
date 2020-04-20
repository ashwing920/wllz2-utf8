// shi.c 史青山

#include <ansi.h>

inherit NPC;

string ask_job();

void create()
{
	set_name("史青山", ({ "shi qingshan", "shi" }));
	set("title", "扬州守将");
	set("gender", "男性");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long",@LONG
史青山曾经是武当山的俗家弟子，不知为何吃上了朝廷饭。
LONG
);
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("inquiry",([
		"难事": (: ask_job() :),
	]));

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("taiji-jian", 50);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 700);
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 20);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/cloth/tiejia")->wear();
}

int accept_fight(object me)
{
	command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
	return 0;
}
string ask_job()
{
	object me;
	me = this_player();
	
	if(me->query_temp("ask_shiqingshan"))
		return "唉，山贼一日不除，我一日寝食难安啊。";
	
	if(me->query("marks/史青山"))
		return "多谢这位" + RANK_D->query_respect(me) +"拔刀相助，解决了我一件难事，真是扬州百姓之福啊。";
	
	me->set_temp("ask_shiqingshan",1);
	return "据巡城的官兵称，近日来有一群山贼聚集于扬州城外密林，打算不日之内进城烧杀抢掠。\n"
		"我虽为扬州守将，可惜城内兵将不多，单凭一人之力恐怕难以将这帮乱贼绳之以法。\n"
		"为今之计，唯有将其头子拿下，以瓦解这帮乱贼。\n";
}
int accept_object(object who, object ob)
{
	
	if((string)ob->query("name") == HIR"山贼头子的头颅"NOR
	&& who->query_temp("ask_shiqingshan")
	&& ob->query("last_damage_from") == who) {
		message_vision("$N接过头颅一看，不禁喜道：这位"+ RANK_D->query_respect(who)+"拔刀相助，解决了我一件难事，真是扬州百姓之福啊。\n",this_object());
		if(!who->query("marks/史青山")){
			tell_object(who,"由于你智勇双全，擒贼先擒王，将城外的山贼一网打尽。\n");
			tell_object(who,"你的潜能增加了 1000 点，江湖威望也有所提高了。\n");
			who->add("learned_points",-1000);
			who->add("weiwang",100);
			who->set("marks/史青山",1);
			who->delete_temp("ask_shiqingshan");
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)帮史青山瓦解了扬州城外的山贼，得到了一些奖励。",who->name(),who->query("id")));
		}
		return 1;
	}
	return 0;
}
