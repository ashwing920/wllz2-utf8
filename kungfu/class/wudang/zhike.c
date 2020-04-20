// zhike.c 知客

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("知客道长", ({ "zhike daozhang", "lingxu daozhang", "lingxu", "zhike" }));
	set("long",@LONG
他道号灵虚，是武当山的知客道长。
LONG
);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("no_get", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("jing",1000);
	set("max_jing", 1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);

	set("combat_exp",100000);
	set("score", 1000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("wudang-jian", 100);
	set_skill("taoism", 100);

	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	create_family("武当派", 5, "弟子");
	set("chat_chance",2);
	set("chat_msg", ({
		"知客道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
		"知客道长说道：玄岳门乃武当出入门户，我等一定要精心守卫(volunteer)，不可丝毫懈殆。\n"
	}));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob;

	if( interactive(ob=this_player()) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
	mapping myfam;

	if(!ob || environment() != environment(ob)) return;
	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "武当派")
		  say ("知客道长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，欢迎到武当来，进来喝杯茶，歇歇腿吧。\n");
	else
		  say ("知客道长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，一路辛苦了。\n");
	return;
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 1) {
		command("say " + RANK_D->query_respect(ob) +"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;

	if (me->query_temp("in_guard")) 
		return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--){
		if (ob[i-1]->query_temp("in_guard"))
		return notify_fail("知客道长对你说：已经有人守山门了，你一会再来吧。\n");
	}
	tell_room(environment(me),me->query("name")+"开始在武当山门值守。\n");
	me->set("guard", HIG"山门守卫"NOR);
	me->set_temp("in_guard",1); 
	me->save();
	remove_call_out("end_guard");
	call_out("end_guard", 120, me);
	remove_call_out("clone_meng");
	call_out("clone_meng", 30, me);
	return 1;
}
void clone_meng(object me)
{
	object ob;
	if(me){
	tell_room(environment(me),"山下突然冲上来一伙蒙面大汉。\n");
	ob=new("/d/wudang/npc/mengmian.c");
	ob->move("/d/wudang/xuanyuegate");
	call_out("clone_meng", 100, me);
	}
}
void end_guard(object me)
{
	if(me) {
	me->delete("guard");
	me->add("guarded",1);
	me->add("combat_exp",10);
	me->add("potential",5);
	me->delete_temp("in_guard"); 
	me->save();
	remove_call_out("clone_meng");
	tell_room(environment(me),me->query("name")+"在武当山门值守期已满。\n");
	tell_object(me,"你在武当山门值守期已满。\n");
	}
}
void die()
{
	object *me;
	int i;
	me = users();
	for (i = 0; i < sizeof(me); i ++)
		me[i]->delete_temp("in_guard"); 
	::die();
}
