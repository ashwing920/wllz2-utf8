// rascal.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(npc_name("男性"),({"qiang dao","robber"}));
	set("title","强盗");
	set("long",@LONG
一个身着粗布衣，要挂单刀的强盗。
LONG
);

	set("attitude", "heroism");
	set("age", random(20) + 30);
	set("str", 20 + random(11));
	set("cps", 20 + random(11));
	set("cor", 20 + random(11));
	set("per", 20 + random(11));
	set("int", 20 + random(11));
	set("con", 20 + random(11));
	set("spi", 20 + random(11));
	set("kar", 20 + random(11));

	set("chat_chance",5);
	set("chat_msg", ({
		(: random_move :)
	}));

	add_temp("apply/armor",400);
	add_temp("apply/unarmed_damage",250);

	set("jing",2000);
	set("max_jing",2000);
	set("max_qi",4000);
	set("qi",4000);
	set("neili",5000);
	set("max_neili",5000);
	set("jiali",200);
	set("shen_type",-1);
	set("bellicosity",8000);
	set("combat_exp",500000 + (100000 * random(10)));
	set("family/family_name","血刀门");

	setup();

	carry_object("/clone/cloth/junfu")->wear();
	carry_object("/clone/weapon/blade")->wield();

}
void init()
{
	add_action("do_halt","halt");
	add_action("do_halt","surrender");
}
void create_skill(object ob)
{
	
	if(!ob || !environment(ob)) return;
	set("combat_exp",ob->query("combat_exp"));
	NPC_D->full_init(this_object());
}
int do_halt(string arg)
{
	object me,ob;
	ob = this_object();
	me = this_player();
	
	if(!me->is_fighting(ob) || !ob->is_fighting(me)) return 0;
	say(name()+"喝道：想逃？没那么容易！\n");
	return 1;
}
void scan()
{
	if(environment() && !is_fighting())
	destruct(this_object());
	return;
}
