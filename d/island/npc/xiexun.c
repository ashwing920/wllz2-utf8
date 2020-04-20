//Npc: 谢逊

#include <ansi.h>
inherit NPC;

int ask_for_dao();
int ask_for_book();

void create()
{
	set_name("谢逊", ({ "xie xun", "xie", "xun" }));
	set("long", @LONG
他就是明教四大护教法王之一的金毛狮王。他身材魁伟异常，满头黄发，
散披肩头，眼睛碧油油的发光，威风凛凛，真如天神天将一般。
LONG
);
	set("nickname", HIY"金毛狮王"NOR);
	set("gender", "男性");
	set("attitude", "heroism");
	set("inquiry",([
		"屠龙刀"  : (: ask_for_dao :),
		"七伤拳"  : (: ask_for_book :),
		"qs-jing" : (: ask_for_book :),
		"七伤拳经"  : (: ask_for_book :),
		"七伤拳谱"  : (: ask_for_book :),
		"成昆" :"此人与我有血海深仇，如能得他首级，谢逊死而无憾。",
		"张无忌" : "啊？！你难道知道我那无忌孩儿的下落？！",
		"明教" : "这都是过去的事了，提它作甚？",
	]));
	set("age", 45);
	set("shen_type", -1);
	set("str", 30);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("give_book",1);
	set_temp("apply/armor", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/damage", 50);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("shen_type",1);
	set("score", 80000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("buddhism",400);
	set_skill("sword", 400);
	set_skill("blade", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("blade", 400);
	set_skill("jinwu-daofa", 400);
	set_skill("hunyuan-yiqi",400);
	set_skill("jiuyang-shengong", 400);
	set_skill("lingxu-bu", 400);
	set_skill("damo-jian", 400);
	set_skill("qishang-quan", 400);
	set_skill("hunyuan-zhang", 400);
	set_skill("literate", 400);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "hunyuan-zhang");
	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
	}) );
	setup();

	carry_object("/clone/weapon/tulongdao")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();

}

int ask_for_dao()
{
	object  me = this_player();
	command("shout");
	command("stare "+me->name());
	command("say "+RANK_D->query_rude(me)+"既然已知道屠龙刀在我手中，乖乖受死吧！\n");

	if(present("tulong dao", this_object())){
		command("wield tulong dao");
	}
	kill_ob(me);
	return 1;
}
int ask_for_book()
{
	object  me, book;

	me = this_player();
	book = new("/clone/book/qs-jing");
	if( !me->query_temp("xiexun_thank") ) {
		command("grin "+me->name());
		command("stare "+me->name());
		command("say "+RANK_D->query_rude(me)+"既然已知道七伤拳经在我手中，就尝尝七伤拳的厉害吧！");
		kill_ob(me);
	}
	else if(book && query("give_book") > 0) {
		book->move(me);
		add("give_book",-1);
		command("say 谢某大仇已报，此生已再无牵挂，这本七伤拳经对我已无大用，"+RANK_D->query_respect(me)+"若看得起，尽管取去无妨！");
		message_vision("谢逊给$N一本" + book->query("name") +"。\n", me);
	}
	else {
		command("say 实在对不住，七伤拳经已经不在我这里了！");
	}
	return 1;
}

int accept_kill(object me)
{
	command("shout");
	if (present("tulong dao", this_object())){
		command("wield tulong dao");
	}
	kill_ob(me);
	return 1;
}

int accept_object(object me, object obj)
{
	if((string)obj->query("name") == HIR"成昆的头颅"NOR
	&& me->query_temp("kill_chengkun") ) {
		command("ah");
		command("shout");
		command("say "+RANK_D->query_respect(me)+"武功果然高明，使谢某报此血海深仇，若有所求，谢某肝脑涂地，在所不辞！\n");
		me->set_temp("xiexun_thank",1);
		return 1;
	}
	else if((string)obj->query("name") == HIR"成昆的头颅"NOR
	&& !me->query_temp("kill_chengkun") ) {
		command("slap "+me->query("id"));
		command("say 老夫眼虽盲了，心却是不盲！");
		if (present("tulong dao", this_object())){
			command("wield tulong dao");
		}
		kill_ob(me);
	}

	return 0;
}
