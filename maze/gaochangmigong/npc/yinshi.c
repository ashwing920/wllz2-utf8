//laogui.c 老鬼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("隐士",({ "yin shi","yinshi","master"}));
	set("long",@LONG
一个身着长袍，道貌岸然的剑客，只见他面无表情，颜色严峻，眉头深锁
，似乎有什么事情还没想明白。
LONG);
	set("age",random(20)+40);
	set("gender", "男性");
	set("str",80 + random(60));
	set("dex",90);

	set("jing",15000);
	set("max_jing",15000);
	set("neili",25000);
	set("max_neili",25000);
	set("max_qi",8000);
	set("qi",8000);
	set("jiali",300);
	set("combat_exp",10000000);

	set_temp("apply/armor",350);
	set_temp("apply/damage",500);
	set_temp("apply/unarmed_damage",500);

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

	set_skill("unarmed",500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("dodge", 500);
	set_skill("literate",500);
	set_skill("huashan-sword",500);
	set_skill("zixia-shengong",500);
	set_skill("huashan-ken",500);
	set_skill("feiyan-huixiang",500);
	set_skill("zhengqijue",500);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-ken");
	map_skill("dodge", "feiyan-huixiang");

	setup();

	carry_object("/clone/weapon/gangjian")->wield();
	carry_object(__DIR__"obj/huisechangpao")->wear();
	add_money("silver",30+random(25));

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：大胆！竟敢扰我静修！纳命来！\n\n");
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
		if(!random(5))
			obj=new(__DIR__"obj/qingtong_duanjian");
		else
			obj=new(__DIR__"obj/gangtie_huwan");

		if(obj->move(killer))
			tell_object(killer,HIC"恭喜！你获得了战利品"+ clean_color(obj->short()) +HIC"一件。\n"NOR);
		else
			destruct(obj);
	}

}
