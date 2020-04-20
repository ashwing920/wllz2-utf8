//polan.c

inherit NPC;

void create()
{
	set_name("收破烂的", ({ "scavenger" }));
	set("long", @LONG
他是一个靠收破烂为生的人。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 48);
	set("str", 30);
	set("con", 30);
	set("per", 30);
	set("int", 30);
	set("kar", 30);
	set("combat_exp",random(30000)+10000);
	set("shen_type",1);
	set("chat_chance",100);
	set("chat_msg", ({
		"收破烂的吆喝道：收～破～烂～哪～\n",
		(: random_move :),
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 50);

}
void init()
{
	remove_call_out("dest_object");
	call_out("dest_object",1);
}
void dest_object()
{
	object env,ob;
	object *obj;
	int i;
	
	ob = this_object();
	env = environment(ob);

	if(!env) return;
	obj = all_inventory(env);
	for(i=0;i<sizeof(obj);i++){
		if( living(obj[i]) && userp(obj[i]) && obj[i] == ob) continue;
		if( obj[i]->is_character()) continue;
		destruct(obj[i]);
	}
}
int accept_object(object me, object obj)
{
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "！");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	random_move();
	return 0;
}
int heal_up(){ return ::heal_up() + 1;}