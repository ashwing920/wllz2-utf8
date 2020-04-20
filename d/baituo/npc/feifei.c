//feifei.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

string ask_food();

void create()
{
	set_name("肥肥", ({ "fei fei","fei" }) );
	set("attitude", "friendly");
	set("gender", "男性" );
	set("long", "一个肥头大耳的厨师，两只小眼睛不停地眨巴着。\n");
	set("age",35);
	set("str",20);
	set("dex",22);
	set("con",20);
	set("int",21);
	set("cor",20);
	set("kar",20);

	set("shen_type", -1);
	set("combat_exp",10000);
	set("inquiry",([
		"食物": (: ask_food() :),
		"food": (: ask_food() :),
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",10);
}
void init()
{
	object ob;
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment()) return;
	say("肥肥小眼一眨，笑吟吟地说道：这位" + RANK_D->query_respect(ob)+ "，欢迎来参观，可不要偷吃哟。\n");
	return;

}
string ask_food()
{
	object me,ob;
	mapping family;

	me = this_player();

	if(mapp(family = me->query("family")) && family["family_name"] =="白驼山派"){
		if( me->query_temp("ask_food") < 5 ){
			ob = new("/d/baituo/obj/cake");
			ob->move(me);
			me->add_temp("ask_food",1);
			message_vision("$N给$n一块蛋糕。\n",this_object(),me);
			return "这是我精心制作的蛋糕，拿去吧。";
		}
		else {
			return "你就别那么贪心了，拿了那么多还要。";
		}
	}
	return "这位"+ RANK_D->query_respect(me) +"与我素无来往，我们不提供食物。";
}