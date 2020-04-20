// ant.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(RED"西域毒蝎"NOR,({ "du xie","xiezi","xie"}));
	set("long", @LONG
一只全身红褐色的蝎子，长期生长在沙漠一带。
LONG
);
	set("race","昆虫");
	set("subrace","爬虫");
	set("age",15);
	set("str",124);		// 膂力
	set("cor",126);		// 胆识
	set("dex",120);

	set("chat_chance",5);

	set("chat_msg",({
		(: random_move :),
		name() + RED"往石壁上的洞窟钻了进去。\n"NOR,
		name() + RED"从石壁上的洞窟伸出一个头来，警惕的四周张望。\n"NOR,
	}));

	set("max_jing",8000);
	set("jing",8000);
	set("max_qi",8000);
	set("qi",8000);

	set("combat_exp",2700000);
	set_skill("unarmed",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_temp("apply/attack",400);
	set_temp("apply/armor", 400);
	set_temp("apply/damage",400);
	set_temp("apply/dodge", 400);
	set_temp("apply/unarmed_damage",400);

	setup();
}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		this_object()->kill_ob(ob);
		this_object()->set_leader(ob);
		ob->kill_ob(this_object());
	}
}
int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor") /10){
		ob->apply_condition("duxie_poison",ob->query_condition("duxie_poison")+10);
		tell_object(ob, RED"你仔细一看，被咬中的地方肿起一块青紫！\n"NOR);
	}
}
void afterdie_func(object killer)
{
	object obj;

	if(!random(7) && NATURE_D->is_night() && random(5) > 2){
		obj=new(__DIR__"obj/duxieke");
		if(obj->move(killer))
			tell_object(killer,HIC"恭喜！你获得了战利品"+ clean_color(obj->short()) +HIC"一个。\n"NOR);
		else
			destruct(obj);
	}

}
