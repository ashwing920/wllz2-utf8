// caifan.c - 菜贩

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("鱼贩子", ({ "yu fan","seller" }) );
	set("long", @LONG
一个渔民打扮的鱼贩子，除了贩卖鲜鱼之外，还收购一些捕捉来的鱼。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 35);
	set("str", 30);
	set("combat_exp",10000);
	set("env/wimpy", 30);
	set_skill("unarmed",40); 
	set_skill("parry",40);
	set_skill("dodge",40);

	set("inquiry",([
		"卖鱼": "你有鱼要卖？先拿来让我瞧瞧(value fish)吧。",
	]));
	
	set("vendor_goods",([
		"/d/shaolin/fish/fish":1,
		"/d/shaolin/fish/fish3":1,
		"/d/shaolin/fish/fish5":1,
		"/d/shaolin/fish/fish7":1,
		"/d/shaolin/fish/fish9":1,
	]));

	setup();

	carry_object("/clone/cloth/cao-hat")->wear();	// 装备
	carry_object("/clone/cloth/cloth")->wear();	

	add_money("silver", 10);			// 金钱
}
void init()
{
	add_action("do_value","value");
	add_action("do_vendor_list", "list");
}
int accept_object(object who, object ob)
{
	int value;

	if(ob->is_fish() && who->query_temp("ask_value"))
	{
		value = (int)ob->query("value");
		MONEY_D->pay_player(who,value);
		write(sprintf("%s将身上的%s卖给了%s，获得了%s。\n",
			who->name(),ob->name(),this_object()->name(),MONEY_D->price_str(value)));
		who->delete_temp("ask_value");
		return 1;
	}
	return 0;
}
int do_value(string arg)
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	
	if(!arg || arg == "" || !objectp(obj = present(arg,me))){
		message_vision("$N一脸疑惑：你要我帮你估价什么东西？\n",ob);
		return 1;
	}
	if(NATURE_D->is_night()){
		message_vision("$N懒洋洋的打打哈欠，说道：晚了，该休息了，你明天再来吧。\n",ob);
		return 1;
	}
	if(obj->is_fish() && !obj->is_character()){
		message_vision("$N接过$n，在手里掂量了掂量，甚是老道的说：这条$n，值"
		+ MONEY_D->price_str(obj->query("value")) +"。\n"
		"你若是想卖，就把它给我吧。\n",ob,obj);
		me->set_temp("ask_value",1);
		return 1;
	}
	else {
		message_vision("$N脸上一怔，不耐烦的说：去去去，没事别这里糊弄我，我怎么知道$n值多少钱啊！\n",ob,obj);
		return 1;
	}
}