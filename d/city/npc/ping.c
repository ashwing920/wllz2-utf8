// ping.c 平一指

inherit NPC;

int ask_wu();
int ask_over();
int ask_working();

void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);
	set("int", 30);
	set("jing", 3000);
	set("max_jing", 3000);
	set("shen_type", 1);

	set("combat_exp",500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
	set("inquiry", ([
		"何首乌" : (: ask_wu :),
		"job" : (: ask_working :),
		"报酬" : (: ask_over :),
		"finish" : (: ask_over :),
	]));

	setup();
	add_money("gold", 1);
	carry_object("/clone/cloth/cloth")->wear();
}
int ask_wu()
{
	object ob;
	ob = this_player ( ) ;
	message_vision("平一指上上下下打量了$N一下：什么！何首乌？拿十两黄金来！\n",ob);
	ob->set_temp ("何首乌" , 1 );
	return 1;
}
int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("何首乌"))
	{
	message_vision("平一指对$N说：医一人，杀一人，老夫不收钱！\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 100000)
	{
		message_vision("平一指给了$N何首乌！\n" , who);
		this_player()->delete_temp("何首乌" );
		obj=new("/clone/yaowu/shouwu");
		obj->move(this_player());
	}
	return 1;
}


int ask_over()
{
	object me,silver;
	int exp,pot;
	me = this_player();

	if(!me->query_temp("fenyaobegin")) {
		command("say 我好象还没有给你工作吧？");
		return 1;
	}
	if(me->query_temp("fenyaobegin")
	&& !me->query_temp("fenyaoover")) {
		command("say 你在说什么呀？你好象还没完成工作呢。");
		return 1;
	}
	me->delete_temp("fenyaobegin");
	me->delete_temp("fenyaoover");
	me->delete_temp("fenyao_times");
	message_vision("平一指笑着对$N说：“不错，不错！这是你应该得的报酬。”\n",me);
	exp = 20 + random(40);
	pot = 30 + random(40);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	silver = new("/clone/money/silver");
	silver->set_amount(5+random(5));
	silver->move(me,1);
	tell_object(me,"你被奖励了：" + chinese_number(exp) + "点经验，"+ chinese_number(pot) +"点潜能一些白银。 \n");
	return 1;
}
int ask_working()
{
	object me;
	me = this_player();

	if((int)me->query("combat_exp") < 10000){
		message_vision("平一指说道：这位"+ RANK_D->query_respect(me)+"好象还很面生呀。\n",me);
		return 1;
	}
	if((int)me->query("combat_exp") > 100000){
		message_vision("平一指对$N说道：“这位"+ RANK_D->query_respect(me)+"见笑了，小店劳烦不起。”\n",me);
		return 1;
	}
	if(me->query_temp("fenyaobegin")){
		message_vision("平一指对$N说道：“你不是已经要了工作了，还不去干！”\n",me);
		return 1;
	}
	if((int)me->query("qi") < 30){
		message_vision("平一指对$N说道：算了吧，累成了这样还想工作，把药分错了会出人命的。\n",me);
		return 1;
	}
	if (me->query_temp("fenyaoover")){
		message_vision("平一指对$N说道：“哦？ 你连自己的工资也不要。”\n",me);
		message_vision("平一指对$N说道：“好吧，既然这样我也就不勉强你了。”\n",me);
		message_vision("平一指对$N说道：“那你就到内室去帮我再分次药吧。”\n",me);
		me->delete_temp("fenyaoover");
		me->delete_temp("fenyao_times");
		me->set_temp("fenyaobegin",1);
		return 1;
	}
	message_vision("平一指对$N说道：“好吧，那你就到内室去帮我分分药吧。”\n",me);
	me->set_temp("fenyaobegin",1);
	return 1;
}
