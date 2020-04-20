//mazei.c 马贼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("马贼头子",({ "mazei touzi","mazei","touzi"}));
	set("long",@LONG
他是这帮马贼当中的头子，身材魁梧，络腮胡须，一付凶残的样子看了让
人不禁心寒。
LONG);
	set("age",random(20)+20);
	set("gender", "男性");
	set("str",50 + random(20));
	set("dex",50);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",20000);
	set("max_neili",20000);
	set("qi",6000);
	set("max_qi",6000);
	set("jiali",300);
	set("combat_exp",8000000);

	set_temp("apply/armor",750);
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
	
	set_skill("force", 450);
	set_skill("unarmed",450);
	set_skill("parry", 450);
	set_skill("dodge", 450);
	set_skill("sword", 450);
	set_skill("blade", 450);
	set_skill("whip", 450);
	set_skill("yunlong-shengong", 450);
	set_skill("yunlong-shenfa", 450);
	set_skill("yunlong-xinfa",450);
	set_skill("wuhu-duanmendao", 450);
	set_skill("houquan", 450);
	set_skill("yunlong-jian", 450);
	set_skill("yunlong-bian", 450);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("blade","wuhu-duanmendao");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
	map_skill("unarmed","houquan");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/mazeiyi")->wear();

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：嗯！又来了一个送死的，兄弟们，给我上呀！\n\n");
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
	p = random(45) + 500 - m;

	if( p > 250) p = 250;
	if( p < 0 ) p = 0;
	e = p/3*2;
	if( e > 200) e = 200;
	if( e < 0 ) e = 0;

	if( e > 0 && p > 0){
		killer->add("potential",p);
		killer->add("combat_exp",e);
		tell_object(killer,sprintf(HIC"在这场战斗中，你的实战经验提高了%s点，潜能增长了%s点。\n"NOR,
		chinese_number(e),chinese_number(p)));
	}
	if(!random(7) && NATURE_D->is_night() && random(5) > 2){
		obj=new(__DIR__"obj/jifeng_xue");
		if(obj->move(killer))
			tell_object(killer,HIC"恭喜！你获得了战利品"+ clean_color(obj->short()) +HIC"一件。\n"NOR);
		else
			destruct(obj);
	}

}
