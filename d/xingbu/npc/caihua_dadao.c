// /d/beijing2/xingbu/npc/caihua.c

inherit NPC;

void create()
{
	set_name("采花大盗", ({ "caihua dadao","caihua","dadao" }) );
	set("gender", "男性" );
	set("age", 20);
	set("title","一枝梅");
	set("long", "江湖上人人喊打的采花大盗。\n");
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
