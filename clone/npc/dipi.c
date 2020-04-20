// robber.c

#include <ansi.h>
inherit	NPC;
void create()
{
	switch(random(4)){
		case 1: 
			set_name("强盗",({"robber","qiang dao"}));
			break;
		case 2: 
			set_name("地痞",({"di pi","dipi","rascal"}));
			break;
		case 3: 
			set_name("流氓",({"liu mang","rascal"}));
			break;
		default: 
			set_name("无赖",({"wu lai","rascal"}));
			break;	
	}
	set("long",sprintf("这是一名%s，满脸横肉，十分凶悍。\n",this_object()->query("name")));
	set("attitude",	"heroism");
	set("str", 20 +	random(11));	    
	set("per", 20 +	random(11));	    
	set("int", 20 +	random(11));	    
	set("con", 20 +	random(11));	    
	set("dex", 100 + random(11));	    
	set("kar", 20 +	random(11));	
	set("no_suck",1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver", 20);
}
void init()
{	
	object me,ob;
	int n;
	me=this_object();
	ob=this_player();

	if(!me->is_fighting())
	if(present("gold",ob)
	|| present("thousand-gold",ob)
	|| present("silver",ob)
	|| present("coin",ob)
	|| present("thousand-cash",ob)
	&& ob->query_temp("do_vendors")){
	if (!me->is_killing(ob->query("id"))){
		set_leader(ob);
		kill_ob(ob);
		n = ob->query("max_qi");
		if( n <= 0 ) n = random(3000) +1;
			set("qi",n);
		n = ob->query("jing");
		if( n <= 0 ) n = random(3000) +1;
			set("max_jing",n);
		n = ob->query("max_qi");
		if( n <= 0 ) n = random(3000) +1;
			set("eff_qi",n);
		n = ob->query("max_jing");
		if( n <= 0 ) n = random(3000) +1;
			set("eff_jing",n);
		n = ob->query("max_neili");
		if( n <= 0 ) n = random(3000) +1;
			set("max_neili",n);
		n = ob->query("neili");
		if( n <= 0 ) n = random(3000) +1;
			set("neili",n);
		n = ob->query("jiali");
		if( n <= 0 ) n = random(30) +1;
			set("jiali",n);
		n = ob->query("combat_exp") + ( ob->query("combat_exp") / 2 );
		if( n <= 0 ) n = random(30000) +1;
			set("combat_exp", n );
		n = ob->query_skill("force", 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("force", n );
		n = ob->query_skill("unarmed", 1) + random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("unarmed", n );
		n = ob->query_skill("force", 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("blade", n );	
		n = ob->query_skill("parry", 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("parry", n );
		n = ob->query_skill("dodge", 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("dodge", n );
		n = ob->query_skill(ob->query_skill_mapped("force"), 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("taiji-shengong", n );
		n = ob->query_skill(ob->query_skill_mapped("force"), 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
			set_skill("wuhu-duanmendao", n );
		n = ob->query_skill(ob->query_skill_mapped("dodge"), 1)	+ random(10);
		if( n <= 0 ) n = random(3) + 1;
		set_skill("tiyunzong", n );
		map_skill("dodge", "tiyunzong");
		map_skill("force", "taiji-shengong");
		map_skill("blade", "wuhu-duanmendao");
		map_skill("parry", "wuhu-duanmendao");
		}
	}else	if (me->is_killing(ob) ){
		me->remove_killer(ob);
		me->set_leader(0);
	}
	if (living(ob))
	add_action("do_go","go");
	add_action("do_halt","halt");
}

int do_go(string arg)
{
	mapping	exit;
	if (!environment()) return 1;
	if( !mapp(exit = environment()->query("exits"))	|| undefinedp(exit[arg]) )
		return 0;
	if (is_killing(this_player()))
		if (random(10) > 8) {
			message_vision(YEL "$N见势不好，转身要走，被$n一把拦在前。想走？先放下银两！\n"NOR, this_player(), this_object());
			return 1;
	}
	return 0;
}
int do_halt(string arg)
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N想跳出战圈不打了，$n喝道：放下银两，老子就放你走路！\n",ob,me);
	return 1;
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
       if (!environment()) return;
	message("vision",name() +"见没有得手，忿忿的离开了。\n",environment(),this_object());
	destruct(this_object());
}
