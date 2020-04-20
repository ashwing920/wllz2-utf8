//boss.c 

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

string ask_work();

void create()
{
	set_name("吴斯", ({ "wu si","wu"}));
	set("long",@LONG 
此人长相猥琐，给人一种阴森的感觉。面对着他，你就感觉脊梁发冷。
LONG
);
	set("title","棺材店老板");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("combat_exp", 1000000);
	set("futou_count",10);
	set_skill("wooder",100);

	set("vendor_goods",([
		"/clone/misc/muliao":1,
		"/clone/weapon/xuemudao":1,
	]));
	set("inquiry", ([
		"工作" : (: ask_work :),
		"job" : (: ask_work :),
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",10);
}
void init()
{       
	object ob;
     
	if( this_object()->query_temp("unconcious") ) return;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(1) ) {
		case 0:
			say( this_object()->query("name") + "阴笑地说道：这位" + RANK_D->query_respect(ob)
				+ "，要订口棺材吗？\n");
			break;
	}
}
string ask_work()
{
	object me;
	object futou;
	me = this_player();
	
	if(me->query("combat_exp") >= 50000 ) {
		return "唉，你赚钱都赚了差不多了吧，别档了别人的财路。\n";
	}
	
	if(query_temp("give_job") > (random(30) + 40)) {
		return "现在店里的木材够用了，你还是改天再来吧！\n";
	}
       
	if(me->query("gender") == "女性") {
		return "伐木这种粗重活好象不适合你做吧？\n";
	}
	if(me->query_temp("famu")) {
		return "不是叫你去伐木了吗？想偷懒啊？\n";
	}
	
	if(present("fu tou",this_player())) {
	me->set_temp("famu",1);
	me->set("futou_count",-1);
	set_temp("give_job",1);
		return "最近本店木材不够用了，"+ RANK_D->query_respect(me)+"能否去采一些木材回来给我？";
}       
	else {
		futou = new ("/clone/misc/futou");
		futou->move(this_player(),1);
		me->set_temp("famu",1);
		me->set("futou_count",-1);
		set_temp("give_job",1);
		return "最近本店木材不够用了，"+ RANK_D->query_respect(me)+"能否去采一些木材回来给我？";
	}
}

int accept_object(object me, object ob)
{
	int n,i;
	object obj;
	me = this_player();

	
	if( me->query_temp("famu") && me->query_temp("finish_famu") && ob->id("mu tou")){
	command("say 呵呵！不错，好好努力吧！");
	n = 5 + random(10);
	for( i = 0; i < n; i ++ ) {
		obj=new("/clone/money/silver");
		obj->move(me,1);
	} 
	me->add("combat_exp",20);
	me->add("potential",25);
	tell_object(me,HIW"由于你勤劳肯干，你被奖励了：" + chinese_number(20)+ "点实战经验。"NOR);
	tell_object(me,HIW + chinese_number(25) + "点潜能。你还赚到了一些银两！\n"NOR);
	me->delete_temp("famu");
	me->delete_temp("finish_famu");
	me->add_temp("tmark/吴斯",10);
	if( me->query_temp("tmark/吴斯") > 100){
		tell_object(me,"吴斯对你呵呵一笑，说道：不错，不错！这位"+ RANK_D->query_respect(me)+"天资聪颖，如有心\n与我学习一些木匠之技[wooder]，他日必定成材呀！\n");
	}
	return 1;
}
	command("? "+ me->query("id"));
	command("say 你给我这个东西干什么？");
	return 0;
}
int recognize_apprentice(object ob)
{
	if(!(int)ob->query_temp("tmark/吴斯")) return 0;
	if((int)ob->query_temp("tmark/吴斯") == 1 )
	message_vision("吴斯看看$N，说道：我能教你的东西到此为止，以后就要靠你自己了。\n", ob);
	ob->add_temp("tmark/吴斯", -1);
	return 1;
}
