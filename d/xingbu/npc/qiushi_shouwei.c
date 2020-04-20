// /d/xingbu/npc/qiushi_shouwei.c

inherit NPC;
int ask_into();
void create()
{
	set_name("囚室守卫", ({ "qiushi shouwei", "shouwei" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "负责看守犯人的官兵。\n");
	set("attitude", "heroism");
	set("inquiry",([
		"探监": (: ask_into :),
		"送饭": (: ask_into :),
	]));
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("combat_exp", 50000);
	setup();
	NPC_D->full_init(this_object());
	
}
int ask_into()
{
	object me; 
	me = this_player();
	if(wizardp(me)) {
		me->set_temp("give_parsion_money",1);
		command("say 小的该死，大人里面请.......");
	}
		else  {
		me->set_temp("ask_parsion_money",1);
		command("say 嘿嘿！那要看你......识相....");
	}
	return 1;
}
int accept_object(object who, object ob)
{
	if( who->query_temp("ask_parsion_money")){
	if( ob->value() >= 10000 ) {
		command("say 嘿嘿！好吧，你进去吧！");
		who->set_temp("give_parsion_money",1);
		} 
	else   {
		command("say 就这点，哪够本大爷喝酒？ ");
		return 1;
	}
	return 1;
	}
}
