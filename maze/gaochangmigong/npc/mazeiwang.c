//laogui.c 老鬼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("马贼王",({ "mazei wang","mazai","master"}));
	set("long",@LONG
他就是马贼当中的首领，经常带领着一帮马贼外出抢掠，欺压当地百姓。
LONG);
	set("age",random(20)+40);
	set("gender", "男性");
	set("str",80 + random(60));
	set("dex",90);

	set("jing",14000);
	set("max_jing",14000);
	set("neili",28000);
	set("max_neili",28000);
	set("max_qi",10000);
	set("qi",10000);
	set("jiali",325);
	set("combat_exp",10500000);

	set_temp("apply/armor",450);
	set_temp("apply/damage",450);
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

	set_skill("force", 550);
	set_skill("huntian-qigong", 550);
	set_skill("unarmed", 550);
	set_skill("xianglong-zhang",550);
	set_skill("dodge", 550);
	set_skill("xiaoyaoyou",550);
	set_skill("parry", 550);
	set_skill("staff", 550);
	set_skill("dagou-bang",550);
	set_skill("begging", 550);
	set_skill("checking", 550);
	set_skill("training", 550);
	set_skill("hand",550);
	set_skill("shexing-diaoshou",550);
	set_skill("blade",550);
	set_skill("liuhe-daofa",550);
	set_skill("staff",550);
	set_skill("fengmo-zhang",550);
	map_skill("parry","dagou-bang");
	map_skill("hand","shexing-diaoshou");
	map_skill("blade","liuhe-daofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("staff", "fengmo-zhang");

	setup();

	carry_object("/clone/weapon/staff")->wield();
	carry_object(__DIR__"obj/damagua")->wear();
	add_money("silver",10+random(50));

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：嘿嘿！留下你的尸骸！！\n\n");
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
			obj=new(__DIR__"obj/jujue");
		else
			obj=new(__DIR__"obj/liuyun-pifeng");

		if(obj->move(killer))
			tell_object(killer,HIC"恭喜！你获得了战利品"+ clean_color(obj->short()) +HIC"一件。\n"NOR);
		else
			destruct(obj);
	}

}
