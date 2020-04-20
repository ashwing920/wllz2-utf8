// seller-bz.c - 布庄老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit NPC;
inherit F_VENDOR;

int do_gongzuo();
void create()
{
	set_name("杨老四",({ "yang laosi","waiter","yang"}) );
	set("long", @LONG
他是这间布庄的老板，三十多岁的人了，到现在还没有娶妻。
一心扑在打理布庄的生意上。
LONG
);
	set("title","布庄老板");
	set("rank_info/respect", "老板");
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 36);
	set("combat_exp",10000+random(30000));
	set("env/wimpy", 30);
	set("inquiry", ([
		"工作" : (: do_gongzuo :),
		"job" : (: do_gongzuo :),
	]) );
	set("vendor_goods", ([
		"/clone/obj/twine":1,
		"/clone/cloth/xiaoyao-jin": 1,
		"/clone/cloth/xiaozhan-boots": 1,
		"/clone/cloth/xiu-cloth": 1,
		"/clone/cloth/xiu-scarf": 1,
		"/clone/cloth/yan-dress": 1,
		"/clone/cloth/yellow-pao": 1,
		"/clone/cloth/yin-kui": 1,
		"/clone/cloth/yu-hat": 1,
		"/clone/cloth/zhan-boots": 1,
		"/clone/cloth/zhan-hat": 1,
		"/clone/cloth/zhitao": 1,
		"/clone/cloth/zhu-hat": 1,
		"/clone/cloth/zi-dress": 1,
		"/clone/cloth/ao-dress": 1,
		"/clone/cloth/baolan-duanshan": 1,
		"/clone/cloth/binding-cloth": 1,
		"/clone/cloth/blue-cloth": 1,
		"/clone/cloth/boots": 1,
		"/clone/cloth/bu-shoes": 1,
		"/clone/cloth/cao-hat": 1,
		"/clone/cloth/chang-silk": 1,
	]) );
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;


	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		if( this_object()->query_temp("unconcious") ) return;
	switch( random(1) ) {
		case 0:
			say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，想买防具吗？\n");
			break;
	}
}
int do_gongzuo()
{
	object me;
	me = this_player();

	if(me->query("combat_exp") < 10000){
		command("say 这位"+ RANK_D->query_respect(me)+"怎么看起来好象很面生呀？");
		return 1;
	}
	if(me->query("combat_exp") > 100000){
		command("say 这位"+ RANK_D->query_respect(me)+"武艺高强，小的怎敢劳烦？");
		return 1;
	}
	if( me->query_temp("gongzuo/yunbu")>0){
		command("say 你还是快去后堂帮我把布匹熨好吧。");
		return 1;
	}
	message_vision("$N对$n说道：现在熨好的布匹不够用了，你去后堂帮我熨些布来吧。\n",this_object(),me);
	me->set_temp("gongzuo/yunbu", 1);
	return 1;
}
int accept_object(object me, object ob)
{
	object money;
	int t,exp,pot;

	if((string)ob->query("name") == "熨好的布") {
		if(ob->query_temp("work_by") != me){
			command("say 叫你去做事，你竟然叫人顶替？哼！");
			me->delete_temp("gongzuo");
			return 1;
		}
		else
			{
			message_vision("$N点了点头，对$n说道：辛苦了，这是你的工钱。\n",this_object(),me);
			exp = 20+random(40);
			pot = 30+random(40);
			me->add("combat_exp",exp);
			me->add("potential",pot);
			tell_object(me,"你被奖励了：" + chinese_number(exp) + "点经验，"+ chinese_number(pot) +"点潜能和一些白银。 \n");
			t = (int)me->query_temp("gongzuo/times") / 3;
			money=new("/clone/money/silver");
			money->set_amount(t);
			money->move(me,1);
			me->delete_temp("gongzuo");
			return 1;
		}
	}
	return 0;
}
