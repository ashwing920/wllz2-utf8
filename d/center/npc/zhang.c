//zhangwuji.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;

int ask_job();
int is_guanfu() { return 1;}
void create()
{
	set_name("张世明", ({ "zhang shiming", "zhang", "shiming" }));
	set("long",@LONG
他是桃源城里，公正严明，素有包青天美誉的八府巡岸张大人。
LONG
);
	set("title","八府巡按");
	set("gender", "男性");
	set("age",40);
	set("shen_type",1);
	set("attitude", "friendly");

	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_jing",2000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 225);

	set("combat_exp",2700000);

	set_skill("force",300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("sword",300);
	set_skill("blade", 300);

	set("inquiry",([
		"任务":  (: ask_job :),
		"job": (: ask_job :),
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold",10);
}
void init()
{
	add_action("do_task","task");
}
int ask_job()
{
	object *ob,me;
	int i;
	me = this_player();

	if((int)me->query("combat_exp") < 1000000){
		command("say 官府查案并非儿戏，这位" + RANK_D->query_respect(me)+"经验尚浅，还是等以后再说吧。");
		return 1;
	}
	if((int)me->query("combat_exp") > 6000000){
		command("say 这位" + RANK_D->query_respect(me)+"德高望重，这些事情就不麻烦你了。");
		return 1;
	}
	if(me->query_temp("apply_job/guanfu")){
		command("say 这位"+ RANK_D->query_respect(me)+"，我交代的事情做得怎么样了？");
		return 1;
	}
	me->clean_up_team();
	if(!pointerp(me->query_team())){
		command("say 嗯，官府查案并非儿戏，"+ RANK_D->query_respect(me)+"只身前往，恐怕凶多吉少，不妥，不妥！");
		return 1;
	}
	if(!me->is_team_leader()){
		command("say 嗯，你们能够结队而行当然是最好。可是，你们的领队呢？");
		return 1;
	}
	if(sizeof(me->query_team()) < 3){
		command("say 嗯，结伴而行至少也要有三个人以上才可以加以配合吧？");
		return 1;
	}
	ob = me->query_team();
	for(i=0;i<sizeof(ob);i++)
	if(ob[i] && environment(me) != environment(ob[i])) {
		command("say 嗯，你们能够结队而行当然是最好。可是，你们的队伍中的人呢？");
		return 1;
	}
	foreach(object *obj in ob){
		if((int)obj->query("combat_exp") < 1000000){
			command("say "+ obj->name()+"的经验尚浅，恐怕难以担此大任。");
			return 1;
		}
		if((int)obj->query("combat_exp") > 6000000){
			command("say "+ obj->name()+"德高望重，这些事情就不麻烦"+ obj->name() +"了。");
			return 1;
		}
		if(((int)me->query("combat_exp") / (int)obj->query("combat_exp")) > 2
		|| ((int)obj->query("combat_exp") / (int)me->query("combat_exp")) > 2){
			command("say "+ me->name() +"和"+ obj->name()+"实战经验悬殊太大，恐怕照料不及呀。");
			return 1;
		}
		if(obj->query_temp("apply_job/guanfu")){
			command("say "+ obj->query("name")+"？我交代的事情办得怎么样了？");
			return 1;
		}
	}
	ob = me->query_team();
	for(i=0;i<sizeof(ob);i++)
	if(ob[i]){
		ob[i]->set_temp("apply_job/guanfu/quest",1);
		ob[i]->set_temp("apply_job/guanfu/place","盗贼山洞");
		ob[i]->apply_condition("apply_guanfu",60);
		tell_object(ob[i],this_object()->name()+"说道：好吧，那这次任务就交给你们几个人去做，仔细听着：\n"+
		"华山村连日以来，村内村民离奇失踪，据查该地并无生猛野兽出现，失踪的百姓当中\n"+
		"多数是妇人和孩童，你们火速前往华山村看个究竟，务必将此案查出个头绪来。\n");
	}
	return 1;
}
int do_task(string arg)
{
	object me;
	int savenpc;
	me = this_player();

	if(!arg || arg == "" || !me->query_temp("apply_job/guanfu")) return 0;
	if(arg == "cancel"){
		say(this_object()->name()+"说道：好吧！这件案子我叫别人去做，你走吧。\n");
		me->delete_temp("apply_job/guanfu");
		return 1;
	}
	else if(arg == "finish"){
		savenpc = (int)me->query_temp("apply_job/guanfu/save_npc");
		if(!savenpc){
			say(this_object()->name()+"疑道：人呢？你没把人带回来吗？\n");
			return 1;
		}
		else {
			say(this_object()->name()+"说道：嗯！好，做得好！\n");
			tell_object(me,"由于你出色的完成了任务，你获得了"+ chinese_number(savenpc*100)+"经验做为奖励。\n");
			me->add("combat_exp",savenpc * 100);
			me->delete_temp("apply_job/guanfu");
			return 1;
		}
	}
}