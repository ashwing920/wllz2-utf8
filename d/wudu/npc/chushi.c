// chushi

inherit NPC;

int ask_food();

void create()
{
	set_name("厨师", ({ "chushi", "chu" }));
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "这是一个和蔼可亲的胖厨师，随时笑眯眯的。\n");
	set("combat_exp", 100);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("sword", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	set("inquiry", ([
		"食物" : (: ask_food :),
		]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_food()
{ 
	object me=this_player(),food;
	if(me->query("food") > me->max_food_capacity()*0.8 
	&& me->query("water") > me->max_water_capacity()*0.8){
		command("say 你又不饿，要什么食物，留给其他的人吧！");
		return 1;
	}
	if ( me->query_temp("noask") ){
		command("say 你不是才来要过吗，食物有限，饿了在来吧！");
		return 1;
	}
	command( "say 好吧，这些你就拿去吃吧！");
	food=new("/d/wudu/obj/erkuai");
	food->move(me);
	food=new("/d/wudu/obj/mixian");
	food->move(me);
	food=new("/d/wudu/obj/dawan");
	food->move(me);
	message_vision("厨师给$N一些食物。\n",me);
	me->set_temp("noask",1);
	call_out("del_ask",20,me);
	return 1;
}

void del_ask(object me)
{	
	if(!me) return;
	me->delete_temp("noask");
}
