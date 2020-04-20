// zongguan.c 总管

#include <ansi.h>
inherit NPC;

int job();
int finish();

void create()
{
	set_name("张万福", ({ "zhang wanfu", "zhang" }));
	set("title","富豪院总管");
	set("gender", "男性");
	set("long",@LONG
他是富豪院里的管家，从小追随着主人，现在负责富豪院里的一切大
小事务。
LONG
);
	set("age",55);
	set("inquiry", ([
		"job"  : (: job :),
		"finish": (: finish :),
	]));
	set("combat_exp",20000);
	set("max_jing",2000);
	set("jing",2000);
	set("max_qi",2000);
	set("qi",2000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();

	add_money("silver",3);
	carry_object("/clone/cloth/cloth")->wear();
}

int job()
{
	object me,obj,ob;
	me = this_player();
	obj = this_object();

	if (me->query("combat_exp") >= 10000) {
	command("shake "+ me->query("id"));
	command("say "  + RANK_D->query_respect(me) +"见笑了，老头子怎敢牢烦您呢？！");
	return 1;
}
	if (me->query_temp("wash_job")){
	command("? "+ me->query("id"));
	command("say 叫你去洗碗，你洗完了吗？？");
	return 1;

}
	if(me->query_temp("clean_job")){
	command("? "+ me->query("id"));
	command("say 叫你去扫地，你打扫干净了吗？？");
	return 1;

}

	if( me->query("gender") == "女性") {
	command("look "+ me->query("id"));
	command("say 你到后院的厨房那边洗碗["HIG"xi 碗"NOR+CYN"]吧！");
	me->set_temp("wash_job",1);
	me->add_temp("jobed/洗碗",1);
	obj->add_temp("give_job",1);
	return 1;
}       else

	if( me->query("gender") == "男性" || me->query("gender") == "无性") {
	message_vision("$N打量了$n一眼。\n",obj,me);
	command("say 好吧！你去把后院给打扫["HIG+"sao 地"NOR+CYN"]一下。");
	me->set_temp("clean_job",1);
	obj->add_temp("give_job",1);
	if( !present("sao ba",me)) {
	ob=new("clone/misc/saoba");
	ob->move(me,1);
	message_vision("$N给了$n一把扫把。\n",obj,me);
}
	return 1;
	}

}
int finish()
{
	int n;
	object me,obj;
	me = this_player();

	if (me->query_temp("wash_finish")){

	command("nod "+ me->query("id"));
	command("say 好！干得好！");
	me->add("combat_exp",me->query_temp("job_times") * 5);
	me->add("potential",me->query_temp("job_times") * 5);
	me->delete_temp("wash_job");
	me->delete_temp("job_times");
	me->delete_temp("wash_finish");
	n = random(10) + 1;
	obj = new("/clone/money/silver");
	obj->set_amount(n);
	obj->move(me,1);
	message_vision("$N出色的完成了工作，获得了奖励。\n",me);
	message_vision("$N的经验增加了和潜能增加了，还赚到了一些银子。\n",me);

	return 1;
}
	if (me->query_temp("clean_finish")){
	command("nod "+ me->query("id"));
	command("say 好！干得好！");
	me->add("combat_exp",me->query_temp("job_times") * 5);
	me->add("potential",me->query_temp("job_times") * 5);
	me->delete_temp("clean_job");
	me->delete_temp("job_times");
	me->delete_temp("clean_finish");
	n = random(10) + 1;
	obj = new("/clone/money/silver");
	obj->set_amount(n);
	obj->move(me,1);
	message_vision("$N出色的完成了工作，获得了奖励。\n",me);
	message_vision("$N的经验和潜能增加了，还赚到了一些银子。\n",me);

	return 1;

}
	command("say 工作还没有做完就来领赏？");
	return 1;

}
