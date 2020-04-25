// nianci.c 念慈

#include <ansi.h>

inherit NPC;
int ask_me();
int ask_armor();
int ask_glove();
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
		"手套"	:(:ask_glove:),
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
	add_action("do_weave","编织");
	add_action("do_weave","weave");
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
	else if ((string)ob->query("id") == "yinjiao si") {
		if(!who->query_temp("glove"))  {
			command("say 你我素不相识这样不好，您请回吧！");
			return 0;
		}
		who->set_temp("m_glove",1);
		who->add_temp("panlong",1);
		message("vision","念慈低头检视了一下手中的"+(string)ob->query("name")+"点了点头说：那好，我们现在就开始缝制。\n", who);
		write("请这位"+RANK_D->query_respect(who)+"给手套起名字吧！(weave 手套的名字)\n");		
		return 1;
	}
	else
	{
		write(ob->query("name")+"\n");
		command("say 你给我这个干什么?");
		return 0;
	}
}

int do_weave(string arg)
{
	string o_name,w_name,tmp;
	object glove,make_time;
	object me;
	int i;

	me = this_player();
	
	if(!me->query_temp("m_glove")) return 0;
	
	if((me->query("weapon/make")) ){
		say("念慈一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
		return 1;
	}
	if( !arg )
		return notify_fail("念慈认真的说：想好手套的名称及代号后在对我说。\n");

	sscanf(arg ,"%s" ,w_name);
	if(!w_name)
		return notify_fail(name() +"说道：使用weave 手套的名字。\n");

	tmp = clean_color(w_name);
	
	if(strlen(tmp) > 4 || strlen(tmp) < 1)
		return notify_fail(name() +"说道：兵器的名字必须为 1 到 4 个字。\n");
	
	i=strlen(tmp);

	while(i--){
		if( tmp[i]<=' ' )
			return notify_fail(name() +"说道：对不起，你的中文名字不能用控制字元。\n");
		if( i%2==0 && !is_chinese(tmp[i..<0]) )
			return notify_fail(name() +"说道：对不起，请您用「中文」取名字。\n");
	}

	me->delete_temp("m_glove");

	if(me->query_temp("panlong") ) o_name="盘龙银绞丝";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对念慈悄声说了几句话。念慈点了点头。说：好吧！\n",me );
	if((me->query("qi"))<(me->query("max_qi"))
	|| (me->query("jing"))<(me->query("max_jing"))
	|| (me->query("neili"))<(me->query("max_neili"))){
		message_vision(HIR"\n\n突然$N觉得气血一阵翻涌，一口真气接不上来......\n" NOR, me);
		me->set("neili",0);
		me->delete_temp("glove");
		me->unconcious();
		return 1;
	}
	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("glove/make",1);
	me->set("glove/name",convert_color(w_name)+NOR);
	me->set("glove/lv",1);
	me->set("glove/or",o_name);
	me->set("glove/value",0);
	me->set("glove/type","glove");
	me->set("glove/time",make_time);

	glove=new("/d/npc/m_weapon/weapon/m_glove",1);
	glove->move(this_player());
	message_vision(CYN"\n念慈抹净嘴边的鲜血,不负所望,总算做好了!\n"NOR,me );
	return 1;
}
int ask_glove()
{
	object me;
	me = this_player();

	if(!(int)(me->query("glove/make")) ){
		me->add_temp("glove",1);
		command("say 据说嘉兴湖心小洞里有外太空陨石消息,如果能弄来炼出传说中的盘龙丝就好了\n。");
		return 1;
	} 
	if(present("my glove",me)){
		command("say "+ RANK_D->query_respect(me)+"不是已经有了手套了吗？");
		return 1;
	}
	command("say 这么重要的东西都丢了呀？好吧，我再给你一件。");
	ob =new("/d/npc/m_weapon/weapon/m_glove",1);
	ob->move(me,1);
	command("say 小心点哦，别再搞丢了。");
	return 1;
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
