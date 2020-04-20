// dushe

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("沙蟒",({ "sha mang","mang" }) );
	set("long","一种长期生活在沙漠地带的蟒蛇，巨大的身躯竟有两个拳头大小。\n");
	set("race","蛇类");
	set("age",26);
	set("attitude","aggressive");

	set("max_jing",12000);
	set("jing",12000);
	set("max_qi",12000);
	set("qi",12000);

	set("str",150);
	set("cor",50);
	set("dex",10);
	set("con",50);
	set("int",50);

	set("chat_chance",5);
	set("chat_msg",({
		(: random_move :),
	}));
	if(!random(5)){
		set("eatable",1);
		set("afterdie",__DIR__"obj/snake_meat");
	}
	add_temp("apply/attack",500);
	add_temp("apply/damage",800);
	add_temp("apply/armor",700);
	set_temp("apply/unarmed_damage",600);

	set_skill("parry",300);
	set_skill("unarmed",300);
	set("combat_exp",2700000);
	setup();
}
int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor") /4){
		if(!ob->is_busy()) ob->start_busy(1+random(4));
			tell_object(ob,"沙蟒用尾巴把你的双脚紧紧缠住，使得你动弹不得。\n");
	}
}
void afterdie_func(object killer)
{
	object obj;
	if(!random(7) && NATURE_D->is_night()){
		obj=new(__DIR__"ghost");
		obj->set("back_time",120+time());
		obj->move(environment(killer));
	}

}
