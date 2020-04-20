// zhao.c

#include <ansi.h>

inherit NPC;

string ask_gao();

void create()
{
	set_name("赵敏", ({ "zhao min", "min", "zhao"}));
	set("title", HIY "大元绍敏郡主" NOR);
	set("long",
"她脸泛红霞，容色丽都。十分美丽之中，更带着三分英气，三分豪态，同
时雍容华贵，自有一副端严之致，令人肃然起敬，不敢逼视。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 500);
	set("max_jing", 200);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ren" :),
	}) );

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("liangyi-jian", 80);
	set_skill("huifeng-jian", 80);
	set_skill("taiji-shengong", 90);
	set_skill("changquan", 80);
	set_skill("lingxu-bu", 80);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
	map_skill("unarmed", "changquan");
	set_temp("is_riding", HIM"紫骝马"NOR);
	set("chat_chance",5);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("inquiry", ([
		"张无忌" :  "张公子远在昆仑，不知他近来可好？秋冷春寒，可有寒衣？\n",
		"倚天剑" :  "倚天为天下神兵。\n",
		"黑玉断续膏":(:ask_gao():),
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/female2-cloth")->wear();
	add_money("gold",1);
}
string ask_gao()
{
	object me,npc1,npc2,yao;
	me = this_player();
	
	if(!me->query_temp("ask_zhangsanfeng")
	|| query("get_yao") || query("fight"))
		return "黑玉断续膏是疗伤圣药，具有起死回生的功效，你要来有何用？";
	
	if((string)me->name() != "张无忌")
		return "黑玉断续膏不可多得，凭什么你要我就给？";
	
	if((int)me->query_temp("fight_win_zhao") < 2){
		message_vision("$N诡秘一笑，素闻明教张大教主为人侠义，武功盖世，我倒未曾领教。\n"
		"如果张大教主能够打败我的这两个侍卫，黑玉断续膏自然会为教主献上。\n"
		"$N说完，轻轻一击掌，两个衣着怪异的男子出现在$n的眼前。\n",this_object(),me);
		npc1 = new("/d/mingjiao/yuan/ada");
		npc1->move(environment(this_object()));
		npc2 = new("/d/mingjiao/yuan/aer");
		npc2->move(environment(this_object()));
		message_vision("那两个男子一抱拳，对$N喝道："+ RANK_D->query_respect(me)+"，接招吧！\n",me);
		npc1->fight_ob(me);
		npc1->checking(npc1,me);
		npc2->fight_ob(me);
		npc2->checking(npc1,me);
		me->fight_ob(npc1);
		me->fight_ob(npc2);
		delete("chat_chance");
		delete("chat_msg");
		set("fight",1);
		return "张教主，当心了。";
	}
	yao = new("/d/mingjiao/yuan/obj/duanxugao");
	yao->move(me);
	yao->set("give_to",me);
	set("get_yao",1);
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)打败阿大阿二，拿到了黑玉断续膏。",me->name(1),me->query("id")));
	return "张大教主果然名不虚传，小女子佩服！佩服！";
}

void reset()
{
	if(query("get_yao"))
	delete("get_yao");
	delete("fight");
}