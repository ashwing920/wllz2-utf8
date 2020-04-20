// zhao.c

#include <ansi.h>

inherit NPC;

int checking(object me, object ob);

void create()
{
	set_name("阿二", ({ "a er","er"}));
	set("title", HIC"汝阳王府侍卫" NOR);
	set("long",@LONG
他是汝阳王府的侍卫阿二，常年跟在赵敏的身边，此人身着怪异，
长发披肩，一看就知道不是一个简单的角色。
LONG);
	set("gender","男性");
	set("age",25);
	set("attitude", "peaceful");
	set("shen_type",-1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_qi",50000);
	set("max_jing",20000);
	set("max_jingli",20000);
	set("max_neili",90000);
	set("neili",90000);
	set("combat_exp",6400000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	set_temp("apply/armor",500);
	set_temp("apply/damage",300);

	set_skill("dodge",400);
	set_skill("unarmed",400);
	set_skill("throwing",400);
	set_skill("xuanyuan-arrow",400);
	set_skill("changquan",400);
	set_skill("xuanming-shenzhang",400);
	set_skill("lingxu-bu",400);
	set_skill("force",400);
	set_skill("hunyuan-yiqi",400);

	map_skill("force","hunyuan-yiqi");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "changquan");
	map_skill("unarmed","xuanming-shenzhang");

	setup();
	carry_object("/clone/cloth/male4-cloth")->wear();
	add_money("gold",1);
}
int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting(ob)) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say 张大教主果然厉害，在下佩服！！");
		ob->add_temp("fight_win_zhao",1);
		destruct(this_object());
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 哼哼，堂堂明教张大教主，武功也不过如此，真是浪得虚名。");
		destruct(this_object());
		return 1;
	}

	return 1;  
}
