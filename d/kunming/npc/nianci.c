// nianci.c 念慈

#include <ansi.h>

inherit NPC;
int ask_me();
int ask_armor();
int ask_job();
int ask_changename();

void create()
{
	set_name("念慈",({"nian ci","ci"}));
	set("long",@LONG
她是这家防具店的老板念慈，年纪轻轻，脸上总是带着一种关爱的笑容。
LONG
);
	set("gender","女性");
	set("attitude", "friendly");
	set("rank_info/respect","姑娘");
	set("str", 20 + random(11));
	set("per", 30 + random(11));
	set("int", 20 + random(11));
	set("con", 20 + random(11));
	set("dex", 500);
	set("kar", 40 + random(11));
	set("inquiry",([
		"定制": (: ask_me :),
		"防具": "我们这里各式各样的防具都有，还可以定制你喜爱的服饰呢！",
		"定制防具": (: ask_me :),
		"制作": (: ask_me :),
		"新防具": (: ask_armor :),
		"job" : (: ask_job :),
		"工作" : (: ask_job :),
		"改名": (: ask_changename :),
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 20);
}

void init()
{
	add_action("do_make","制作");
	add_action("do_make","make");
	add_action("do_changename","改");
}

int accept_object(object who, object ob)
{
	int e,p,n;
	object money;

	if(ob->query("money_id")){
		if( who->query("armor/make")) {
			command("say "+ RANK_D->query_respect(who)+"已经有防具了，就不用再给钱了。");
			return 0;
		}

		if( who->query_temp("ask_make_armor") && ob->value() >= 1000000 ) {
			command("nod");
			command("say 那好吧，请输入你定制的防具名称。make (防具中文名)");
			who->set_temp("give_make_paid",1);
			return 1;
		}

		command("say 这点钱，还抵不上我们的布料和工费呢？！");
		return 0;
	}

	else if((string)ob->query("name") == "干净衣服") {
		if(who->query_temp("jobcloth") != 2){
			command("hmm");
			command("say 你不愿意干就不要干，拿别人洗好的衣服来交差，这又何必呢？。");
			return 1;
		}
		else {
			command("say 多谢，多谢，辛苦了，你去休息休息吧。");
			p = 40 + random(20);
			e = 30 + random(20);
			n = random(5) + 1;
			tell_object(who,"念慈给了你"+ chinese_number(e)+"点的实战经验和"+ chinese_number(p)+"点的潜能做为奖励。\n");
			tell_object(who,"你还获得了一些银两做为报酬！\n");
			money = new("/clone/money/silver");
			money->set_amount(n);
			money->move(who,1);
			who->add("potential",p);
			who->add("combat_exp",e);
			who->delete_temp("jobcloth");
			who->delete_temp("wash_job");
			return 1;
		}
	}
	else if ((string)ob->query("name") == "破衣服") {
		if (who->query_temp("jobcloth") != 3)
		{
			command("say 真是的，不知道又是谁丢的。");
			command("thank "+who->query("id"));
			return 1;
		}
		else{
			command("say 你也真是的，连洗衣服都洗不好！");
			who->delete_temp("jobcloth");
			who->delete_temp("wash_job");
			return 1;
		}
	}
	else
	{
		command("say 你给我这个干什么?");
		return 0;
	}
}

int ask_armor()
{
	object me,ob;
	me = this_player();

	if( !me->query("armor")){
		command("say 你还没有做过防具，哪来的新防具呀？");
		return 1;
	}

	if(present("my armor",me)){
		command("say "+ RANK_D->query_respect(me)+"不是已经有了防具了吗？");
		return 1;
	}
	command("say 这么重要的东西都丢了呀？好吧，我再给你一件。");
	ob =new("/clone/misc/m_cloth");
	ob->move(me,1);
	command("say 小心点哦，别再搞丢了。");
	return 1;
}

int ask_me()
{
	object me;
	me = this_player();

	if( me->query("armor/make")) {
		command("say "+ RANK_D->query_respect(me)+"不是已经有了防具了吗？");
		return 1;
	}

	if(!me->query_temp("give_make_paid")){
		command("say 要定制防具可要交钱的，一件服饰要100两黄金。");
		me->set_temp("ask_make_armor",1);
		return 1;
	}
		else{
		command("say 请输入你定制的防具名称。make (防具中文名)");
		return 1;
	}
	return 0;
}

int do_make(string arg)
{
	object me,ob,obj;
	string a_name;
	me = this_player();
	ob = this_object();

	if(!me->query_temp("give_make_paid")) return 0;
	if( !arg || sscanf(arg,"%s",a_name) != 1)
		return notify_fail("请输入你定制的防具名称。make (防具中文名)\n");
	if( !a_name || a_name == " ")
		return notify_fail("请输入你定制的防具名称。make (防具中文名)\n");

	if(!CHECK_D->check_obj_name(arg)) return notify_fail(ob->query("name")+"摇了摇头道：抱歉！你不能使用这种名字！\n");

	me->set("armor/name",convert_color(a_name)+NOR);
	me->set("armor/lv",1);
	me->set("armor/make",1);
	me->set("armor/or",1);
	obj = new("/clone/misc/m_cloth");
	obj->move(me,1);
	me->delete_temp("give_make_paid");
	command("say 好了，你可以用[lianzao my armor]来提高"+ convert_color(a_name) + NOR + CYN"的坚韧度。");
	command("say 如果不满意，可以用[hui my armor]将它毁灭。");
	message_vision("$N给$n一件"+convert_color(a_name)+"。\n"NOR,ob,me);
	return 1;
}


int ask_job()
{
	object me, ob;
	me = this_player();

	if (me->query("combat_exp")< 10000){
		command("shake");
		command("say 你是新来的，我这里的衣服那么贵重，怎么放心让你洗呢？");
		return 1;
	}

	else if ((int)me->query("combat_exp") > 100000)
	{
		command("shake " + me->query("id"));
		command("say "+RANK_D->query_respect(me)+"现在武功高强，这些活应该让下人去做吧？");
		return 1;
	}

	else if ((me->query_temp("jobcloth")== 1 ) || (me->query_temp("jobcloth") == 2)){
		command("hmm");
		command("say 有工作还来要，真是一个不安分的家伙。");
		return 1;
	}

	else if (me->query_temp("jobcloth")== 3)
	{
		command("sigh");
		command("say 衣服丢了就算了吧,这里还有一件,你去洗洗吧。");
		me->set_temp("jobcloth",1);
		ob = new("/d/kunming/obj/jobcloth1");
		ob->move(me,1);
		return 1;
	}

	me->set_temp("jobcloth",1);
	me->set_temp("wash_job",1);
	ob = new("/d/kunming/obj/jobcloth1");
	ob->move(me,1);
	command("say 你愿意帮我们下人干活真是太好了。");
	command("say 这里有一些脏衣服，你拿到东门的小溪边去洗洗吧！");
	return 1;
}
int ask_changename()
{
	object me;
	mapping armor;
	me = this_player();
	armor = me->query("armor");

	if(!me->query("armor")) {
		command("say 你还没有自造防具呢！");
		return 1;
	}
	if(armor["lv"] <= 1){
		command("say 由于等级太低，你的"+ armor["name"] + CYN"已经不能再改名了。");
		return 1;
	}
	command("say 如果想改"+ armor["name"] +CYN"的名称，会造成"+ armor["name"]+CYN"降低一个等级。");
	command("say 要是你想清楚了，就请输入（改 新防具的名称）");
	me->set_temp("change_aname",1);
	return 1;
}

int do_changename(string arg)
{
	string w_name;
	object me,ob;
	me = this_player();
	ob = this_object();
	w_name= me->query("armor/name");

	if(!me->query_temp("change_aname")) return 0;

	if( !arg || arg ==" ")
		return notify_fail(ob->name()+"说道：请输入：改 <新名字> \n");

	if(arg == w_name)
		return notify_fail(ob->name()+"说道：你这不是没事找事做吗？\n");

	if(!CHECK_D->check_obj_name(arg)) return notify_fail(ob->query("name")+"摇了摇头道：抱歉！你不能使用这种名字！\n");

	message_vision("$N将$n的"+ w_name +"接过，瞬刻间将剑身上的字迹擦去，刻上了"+ convert_color(arg) + NOR"。\n",ob,me);
	me->delete_temp("change_aname");
	me->set("armor/name",convert_color(arg) +NOR);
	me->add("armor/lv",-1);
	me->save();
	message_vision("$N将"+ convert_color(arg) +NOR"交给$n说道：好了，拿去吧！\n",ob,me);
	tell_object(me,"你的防具新名称将在下次连线生效。\n");
	return 1;
}
