// zeng.c

inherit NPC;
inherit F_VENDOR;
int job();
int ask_xiu();
int ask_learn();
void create()
{
	set_name("曾柔", ({ "zeng rou", "zeng", "rou" }));
	set("shen_type", 1);
	set("gender", "女性");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("long",@LONG
她是韦爵爷不知道第几房的小妾，在这里开个成衣铺，卖些不知道
哪来的衣服。有人说那都是韦爵爷从宫中弄出来的禁品。话这么说，
生意照样红活。
LONG
);
	set("inquiry", ([
		"job"  : (: job :),
		"修理防具": (: ask_xiu :),
		"修补防具": (: ask_xiu :),
		"缝纫之技": (: ask_learn :),
		"缝纫技术": (: ask_learn :),
		"手艺": (: ask_learn :),
	]));
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/clone/obj/twine":1,
		"/clone/cloth/belt" : 1,
		"/clone/cloth/boots": 1,
		"/clone/cloth/bu-shoes": 1,
		"/clone/cloth/color-dress": 1,
		"/clone/cloth/fu-cloth": 1,
		"/clone/cloth/gui-dress": 1,
		"/clone/cloth/hat": 1,
		"/clone/cloth/jade-belt": 1,
		"/clone/cloth/liu-dress": 1,
		"/clone/cloth/marry-dress": 1,
		"/clone/cloth/mini-dress": 1,
		"/clone/cloth/moon-dress": 1,
		"/clone/cloth/pink-dress": 1,
		"/clone/cloth/qi-dress": 1,
		"/clone/cloth/red-dress": 1,
		"/clone/cloth/scarf": 1,
		"/clone/cloth/sha-dress": 1,
		"/clone/cloth/shoes": 1,
		"/clone/cloth/xian-cloth": 1,
		"/clone/cloth/xiu-cloth": 1,
		"/clone/cloth/xiu-scarf": 1,
		"/clone/cloth/yan-dress": 1,
		"/clone/cloth/zi-dress": 1,
	]));
	set_skill("tailor",200);
	setup();
}

void init()
{
	add_action("do_vendor_list", "list");
}
int ask_learn()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if((string)me->query("gender") == "男性"){
		command("snicker");
		say(ob->name()+"笑道：这位"+ RANK_D->query_respect(me)+"怎么也想学女儿家的手艺呢？\n");
		return 1;
	}
	me->set_temp("ask_zeng_tailor",1);
	say(ob->name()+"点了点头道：好吧，从今天开始，你可以到我这里来学一些缝纫的手艺。\n");
	return 1;
}
int job()
{
	object me,obj,ob;
	me = this_player();
	obj = this_object();

	if (me->query("combat_exp") >= 10000) {
		command("shake "+ me->query("id"));
		command("say "  + RANK_D->query_respect(me) +"德高望重，怎敢牢烦您呢？！");
		return 1;
}
	if (me->query_temp("xiu_job")){
		command("? "+ me->query("id"));
		command("say 你的丝绢绣好了吗？");
		return 1;

}
	if( me->query("gender") != "女性") {
		command("faint");
		command("say 这种女人家的手艺恐怕不适合你做吧？");
		return 1;
}
	if( me->query("jing") < 50
	|| me->query("qi") < 50){
		command("say 你现在太累了，可别把我的料子搞砸了。");
		return 1;
}
	ob=new("clone/misc/juan");
	ob->move(me,1);
	message_vision("$N给了$n一条丝绢和一根绣花针。\n",obj,me);
	command("say 好吧，你就帮我做点针线活，东西都在这呢。");
	me->set_temp("xiu_job",1);
	return 1;
}

int accept_object(object me, object obj)
{
	object ob,armor;
	int n;

	if(me->query_temp("xiu_job")
	&& obj->query("id") == "si juan") {
		if( !me->query_temp("xiu_job_finish")){
			command("angry");
			command("say 这条丝绢还没绣好呢，怎么就送来了呢？");
			return 0;
		}
		else {
			command("smile");
			command("say 太好了，做得真漂亮。喏，这是给你的。");
			n = random(30) + 40;
			tell_object(me,"曾柔给了你一些实战经验和点潜能做为奖励。\n");
			me->add("combat_exp",n);
			me->add("potential",n);
			ob = new("/clone/money/silver");
			ob->set_amount(5+random(5));
			ob->move(me,1);
			message_vision("$N给了$n一些"+ ob->name()+"。\n",this_object(),me);
			me->delete_temp("xiu_job");
			me->delete_temp("xiu_finish");
			me->delete_temp("xiu_job_finish");
			return 1;
		}
	}
	else if((int)me->query_temp("xiufu_value")
	&& obj->query("money_id")){
		if(obj->value() < (int)me->query_temp("xiufu_value")){
			command("say 你就这点钱，怎么够呀？");
			return 0;
		}
		if(!objectp(armor = present("my armor",me))){
			command("say 你不把防具拿来，我怎么帮你修补呀？");
			return 0;
		}
		message_vision("$N点了点头说道：好吧，我这就帮你把"+ armor->name() +"修补一下。\n",this_object());
		message_vision("$N说完，从$n手中接过"+ armor->name()+"，拿起绣花针仔细的修补着"+ armor->name()+"每一个损坏的地方。\n",this_object(),me);
		message_vision("不一会儿，"+ armor->name()+"又完美如初了。\n",me);
		me->set("armor/bad",0);
		armor->unequip();
		reload_object(armor);
		me->delete_temp("xiufu_value");
		return 1;
	}
	
	return 0;
}
int ask_xiu()
{
	object me,armor;
	int money,bad;
	
	me = this_player();
	
	if(!me->query("armor")) {
		say(this_object()->name()+"呵呵一笑道：你还没有定制防具。\n");
		return 1;
	}
	if(!objectp(armor = present("my armor",me))){
		say(this_object()->name()+"点点头，说道：将你的防具拿来给我看看吧。\n");
		return 1;
	}
	if( armor->query("equipped")){
		say(this_object()->name()+"疑道：你不把"+ armor->name()+"脱下来，要我怎么帮你看呢？\n");
		return 1;
	}
	bad = (int)armor->query("armor_prop/bad");
	if( bad <= 0){
		say(this_object()->name()+"疑道：你的"+ armor->name() +"不还是好好的吗？\n");
		return 1;
	}
	money =  bad * 3 / 2;
	if(money < 1000) money = 500;
	say(this_object()->name()+"说道："+ armor->name() +"损坏度达到："+ bad +"，如果想修复的话，你必须支付"+ MONEY_D->price_str(money)+"。\n");
	me->set_temp("xiufu_value",money);
	return 1;
}
int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("ask_zeng_tailor")) return 0;
	return 1;
}
