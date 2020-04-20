// /d/beijing2/xingbu/npc/caihua.c

inherit NPC;

void create()
{
	set_name(npc_name("男性"), ({"qiu fan","qiu",}) );
	set("title","囚犯");
	set("gender", "男性" );
	set("age", 20);
	set("long", "一个惯犯，终日游手好闲，专干些见不得人的勾当。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("kar",30);  
	set("per",30);

	set("combat_exp",500000);
	setup();
	NPC_D->full_init(this_object());
	
}
