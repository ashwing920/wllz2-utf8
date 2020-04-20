//laogui.c 老鬼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("独眼老鬼",({ "duyan laogui","laogui"}));
	set("long",@LONG
一个老头子，苍白的头发却梳理得十分整齐。他蒙着一只眼睛，另一只眼
睛狠狠的盯着你看，眼神中乏着丝丝敌意。
LONG);
	set("age",random(20)+60);
	set("gender", "男性");
	set("str",80 + random(20));
	set("dex",90);

	set("jing",12000);
	set("max_jing",12000);
	set("neili",25000);
	set("max_neili",25000);
	set("max_qi",3000);
	set("qi",3000);
	set("jiali",300);
	set("combat_exp",10000000);

	set_temp("apply/armor",400);
	set_temp("apply/unarmed_damage",350);

	set("chat_chance",5);
	set("chat_msg",({
		(: heal_self :),
		(: random_move :),
	}));

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}));
	
	set_skill("force",500);
	set_skill("unarmed",500);
	set_skill("parry", 500);
	set_skill("dodge", 500);
	set_skill("claw",500);
	set_skill("finger",500);
	set_skill("hand",500);
	set_skill("strike",500);

	set_skill("shexing-diaoshou",500);
	set_skill("chanchu-bufa",500);
	set_skill("qianye-shou",500);
	set_skill("sanhua-zhang",500);
	set_skill("chanchu-bufa",500);
	set_skill("jiuyin-baiguzhao",500);
	set_skill("hamagong",500);
	set_skill("nianhua-zhi",500);

	map_skill("dodge","chanchu-bufa");
	map_skill("parry","jiuyin-baiguzhao");
	map_skill("unarmed","jiuyin-baiguzhao");
	map_skill("hand","shexing-diaoshou");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("force","hamagong");
	map_skill("strike","sanhua-zhang");
	map_skill("finger","nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object(__DIR__"obj/heibugua")->wear();
	add_money("silver",30+random(30));

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：大胆，竟敢扰我清休，纳命来！！\n\n");
		this_object()->kill_ob(ob);
		this_object()->set_leader(ob);
		ob->kill_ob(this_object());
	}
}

void afterdie_func(object killer)
{
	object obj;
	int p,e,m;

	m = (int)killer->query("combat_exp") / 50000;
	p = random(45) + 700 - m;

	if( p > 250) p = 350;
	if( p < 0 ) p = 0;
	e = p/3*2;
	if( e > 200) e = 250;
	if( e < 0 ) e = 0;

	if( e > 0 && p > 0){
		killer->add("potential",p);
		killer->add("combat_exp",e);
		tell_object(killer,sprintf(HIC"在这场战斗中，你的实战经验提高了%s点，潜能增长了%s点。\n"NOR,
		chinese_number(e),chinese_number(p)));
	}
	if(!random(7) && NATURE_D->is_night() && random(5) > 2){
		obj=new(__DIR__"obj/baguadao");
		if(obj->move(killer))
			tell_object(killer,HIC"恭喜！你获得了战利品"+ clean_color(obj->short()) +HIC"一件。\n"NOR);
		else
			destruct(obj);
	}

}
