// lishishi.c - 李师师

#include <ansi.h>
inherit NPC;
int ask_piao();
void create()
{
	set_name("李师师", ({ "li shishi", "li" }) );
	set("long", @LONG
她是是千金楼的名妓，精通琴棋书画。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per", 30);

	set("combat_exp",50000);
	set("env/wimpy", 30);

	set_skill("literate", 120);

	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
		"李师师秀眉微蹙，说道：喂！我哪里得罪您了？干嘛这样跟我拼死拼活？\n",
	}) );
	set("inquiry", ([
		"过夜": (: ask_piao :),
		"嫖妓": "官人可要洁身自好啊！",
		"学艺": "请您留件信物！",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();	
	add_money("gold", 3);
}
int recognize_apprentice(object ob)
{
	if( !ob->query("marks/李师师") ) {
		say("李师师说道：咦？我不记得您啊....\n");
		return 0;
	}
	return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value() ){
		command("say 我对钱没兴趣！");
		return 0;
	}

	if( (this_player()->query("per") < 25) 
		|| ( (string)this_player()->query("gender") == "女性") ){
		command("say 我对您没兴趣！");
		return 0;
	}
	command("say 能做相公的老师，真是三生有幸。");
	who->set("marks/李师师", 1);
	return 1;
}
int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int ask_piao()
{
	object me,ob;
	me = this_player();

	me->add_temp("ask",1);	
	if( me->query_temp("ask") > 3){
		command("heng "+ me->query("id"));
		return 1;
	}
	
	if( me->query("age") < 18){
		command("chat 这位"+ RANK_D->query_close(me) +"年纪还小，这些事情以后再说吧。");
		command("chat* goodkid "+ me->query("id"));
		return 1;
	}
	if( me->query("gender") == "女性"){
		command("chat 这位"+ RANK_D->query_close(me)+"怎么拿我开心了。");
		command("blush");
		return 1;
	}
	if( me->query("gender") == "无性"){
		command("chat 这位公公已是阴阳之人，恐怕有心无力吧？");
		command("chat* snicker "+ me->query("id"));
		return 1;
	}
	if( me->query("class") == "bonze" || me->query("class") == "lama"){
		command("chat 这位大师乃是出家之人，还请洁身自爱才是。");
		return 1;
	}
	if( me->query("per") <= 20) {
		command("chat 嘻，癞蛤蟆想吃天鹅肉呀？");
		return 1;
	}
	message_vision("$N喝退旁人，来到$n的身边。\n",this_object(),me);
	ob = present("xia ju",environment(this_object()));
	if(ob) destruct(ob);
	ob = present("ya huan",environment(this_object()));
	if(ob) destruct(ob);
	command("chat* blush "+ me->query("id"));
	command("chat 春宵一刻值千金，"+ RANK_D->query_close(me)+"快快更衣就寝吧！");
	command("makelove "+ me->query("id"));
	return 1;
}