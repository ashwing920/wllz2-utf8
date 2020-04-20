// baby.c 玩家的小孩
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

#ifndef NPCDATA
#define NPCDATA         "/data/baby/"
#endif
#define OUR_BABY   NPCDATA + query("id");

#include <ansi.h>
inherit NPC;
inherit F_SAVE;

static int last_age_set;
void update_age();

string query_save_file()
{
	return OUR_BABY;
}
private string *banned_name = ({
	"你","我","他","她","它","爸","妈","操","干","测试","蝴蝶君","蝴蝶","使用者",
	"扑","爷","奶","婆","叔","姨","爹","做爱","色狼","交","嫖","强奸","调戏","尝试",
	"性","的","妓","哥","姐","哈","嘻","呵","巫师","天神","神仙","大圣","大帝","看看",
	"天帝",MUD_NAME,code_name(),"伟哥","春药","鸡巴","武林","列传","周恩来","毛泽东","邓小平"," ","　",
	"江泽民","蒋介石","测试","试试","看看","黑客","捣蛋","破坏","搞","大米","沈嘉","姚宇斌",
	"　 "
});
void create()
{
	if(!restore()){
	set_name("玩家的小孩",({"baby"}));
	set("gender","男性");
	set("long","玩家的孩子，长得十分可爱。\n");
	set("age",1);
	set("player_baby",1);
	set("chat_chance",2);
	set("chat_msg",({
		(: random_move :),
	}));
	set("max_qi",100);
	set("qi",100);
	set("jing",100);
	set("max_jing",100);
	setup();
	}
	else {
		set("father_name",query("father_name"));
		set("mather_name",query("mather_name"));
		set("mather_id",query("mather_id"));
		set("father_id",query("mather_id"));
		set("per",query("per"));
		set("con",query("con"));
		set("kar",query("kar"));
		set("int",query("int"));
		set("dex",query("dex"));
		set("spi",query("spi"));
		set("str",query("str"));
		set("cor",query("cor"));
		set("gender",query("gender"));
		set_name(query("name"),({ query("id") }));
		setup();
		save();
		set_heart_beat(1);
	}
	carry_object("/clone/cloth/cloth")->wear();
}
void update_age()
{
	if(!environment()) return;
	if(environment(this_object())->query("chat_room") ) {
		last_age_set = time();
		return;
	}
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 1+ (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void init()
{
	object ob;

	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_name","name");
	add_action("do_try","try");
	add_action("do_let","let");
	add_action("do_bao","bao");
	add_action("do_babysave","babysave");
	add_action("do_ask","ask");
	add_action("do_babynick","babynick");
	add_action("do_babytitle","babytitle");
}
void greeting(object ob)
{
	object me;

	me = this_object();

	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("name") == me->query("father_name")){
		say(me->name()+"抬起头，天真的望了"+ ob->query("name") +"一眼，甜甜的叫道：爹！爹！\n");
		command("cat "+ ob->query("id"));
		return;
	}
	else if( ob->query("name") == me->query("mather_name")) {
		say(me->name()+"抬起头，天真的望了"+ ob->query("name") +"一眼，甜甜的叫道：娘！娘\n");
		command("cat "+ ob->query("id"));
		return;
	}

}
int do_bao(string arg)
{
	object me;
	me = this_player();

	if(!id(arg)) return 0;
	if(environment(me) != environment()) return 0;
	if(environment(this_object()) == me)
		return notify_fail("孩子不正在你的身上吗？\n");

	message_vision("$N一把将$n抱了起来，$n「呵呵」的甜甜一笑。\n",this_player(),this_object());

	if( me->query("id") == this_object()->query("father_id")){
		message_vision(HIM"$n甜甜一笑，给了$N轻轻的一个吻，亲切的叫了声：爹～～。\n"NOR,me,this_object());
	}
	else if( me->query("id") == this_object()->query("mather_id")){
		message_vision(HIM"$n象只小猫一般钻到$N怀里撒娇，甜甜的叫了声：娘～～。\n"NOR,me,this_object());
	}
	this_object()->move(this_player());
	return 1;

}
int do_babysave(string arg)
{
	object me;
	me = this_player();

	if(me->query("id") != this_object()->query("father_id")
	&& me->query("id") != this_object()->query("mather_id"))
		return notify_fail("你没有权利将这个孩子进行存档！\n");

	this_object()->save();
	write(this_object()->name()+"存档完毕！\n");
	return 1;
}
int do_babynick(string arg)
{
	object me;
	me = this_player();

	if( me->query("id") != query("father_id")
	&& me->query("id") != query("mather_id"))
		return notify_fail("你没有权利给这个孩子设置绰号。\n");

	if( !arg )
		return notify_fail("你要给孩子取什么绰号？\n");

	if(strlen(arg) > 36)
		return notify_fail("绰号长度太长了，还是想一个简短而响亮的绰号吧！\n");

	if(arg == "none") {
		this_object()->delete("nickname");
		write(this_object()->query("name")+"的绰号删除成功！\n");
		return 1;
	}
		else {
		this_object()->set("nickname", convert_color(arg) + NOR);
		write(this_object()->query("name")+"的绰号设置完成！\n");
		return 1;
	}
}
int do_babytitle(string arg)
{
	object me;
	me = this_player();

	if( me->query("id") != query("father_id")
	&& me->query("id") != query("mather_id"))
		return notify_fail("你没有权利给这个孩子设置头衔。\n");

	if( !arg )
		return notify_fail("你要给孩子取什么样的头衔？\n");

	if(strlen(arg) > 24)
		return notify_fail("头衔长度太长了！\n");

	if(arg == "none") {
		this_object()->delete("title");
		write(this_object()->query("name")+"的头衔删除成功！\n");
		return 1;
	}
	else {
		this_object()->set("title", convert_color(arg) + NOR);
		write(this_object()->query("name")+"的头衔设置完成了！\n");
		return 1;
	}
}
int do_name(string target)
{
	int i;
	object me,ob;
	string old_name,name;
	me = this_player();
	ob = this_object();
	old_name = query("name");
	i = strlen(target);

	if( !target || target=="")
		return notify_fail("命令格式：起 <名字> \n");

	if( ob->query("father_id") != me->query("id")
	&& ob->query("mather_id") != me->query("id"))
		return notify_fail("只有孩子的父母才能为孩子命名。\n");

	if( (strlen(target) < 2) || (strlen(target) > 8 ) )
		return notify_fail("名字不能太长，最多也只有四个中文字。\n");

	while(i--){
		if( target[i]<=' ' )
			return notify_fail("孩子的中文名字不能用控制字元。\n");


		if( i%2==0 && !is_chinese(target[i..<0]) )
			return notify_fail("你只能用「中文」取名字。\n");

	}

	for(i=0; i<sizeof(banned_name); i++) {
		if( strsrch(target, banned_name[i]) == -1) continue;
		return notify_fail("这种名字会造成其他人的困扰。\n");

	}
	if(!PNAME_D->check_name(target))
		return notify_fail("拿玩家的名字做你孩子的名字？不行！\n");

	if( old_name == target )
		return notify_fail("你是吃饱了撑着了？\n");

	if( me->query("name") == target)
		return notify_fail("孩子不能和你同名。\n");

	ob->set("name", target);
	message_vision("$N将孩子命名为："+ target +"了。\n",me);
	return 1;
}
int heal_up()
{
	object ob,me;
	string rank;
	ob = this_object();
	me = this_player();
	if(me->query("gender") == "男性")
		rank = "爹";
	else
		rank = "娘";

	if(random(5) == 2) {
		if((base_name(environment(ob)) != ob->query("startroom"))
		&& ( !present(query("father_id"),environment(ob)))
		&& ( !present(query("mather_id"),environment(ob)))
		&& environment(ob) && ob->is_character()
		&& environment()) {
			if(environment(ob)->query("id") != ob->query("father_id")
			&& environment(ob)->query("id") != ob->query("mather_id")
			&& environment(ob)->is_character()
			&& living(environment(ob))){
				CHANNEL_D->do_channel(ob,"chat",sprintf("爹、娘，你们在哪里？%s不知道要把我带哪去！",
				environment(ob)->query("name")));
				return 1;
			}
			else {
				if(!environment(ob)->is_character() && environment(ob)->query("exits")) {
				command("wuwu");
				command("say 爹、娘，你们在哪里呀？"+ query("name")+"迷路了. . . ");
				CHANNEL_D->do_channel(ob,"rumor",sprintf("有人发现%s正在%s徘徊，好象已经迷路了。",
				ob->name(1),environment(ob)->query("short")));
				return 1;
				}
			}
		}

		if(ob->query("food") < 10 || ob->query("water") < 10 ) {
			command("cry");
			command("say 爹、娘，"+ query("name")+"饿了. . . ");
			return 1;
		}
	}
	update_age();
	return ::heal_up() + 1;
}
int accept_object(object me, object obj)
{
	me = this_player();

	command("smile");
	if( me->query("name") != this_object()->query("father_name")
	&&  me->query("name") != this_object()->query("mather_name"))
	command("answer "+ me->query("id")+" 多谢" + RANK_D->query_close(me) + "！");
	else
	command("face "+ me->query("id"));
	return 1;
}

int accept_fight(object me)
{
	command("wuwu");
	command("say 爹爹娘亲快来呀，有人欺负我！\n");
	return 0;
}
int do_ask(string arg)
{
	object me = this_player();
	string tempstr, name;
	string result_name;

	if(!arg
	|| sscanf(arg, "%s about %s", tempstr, name) != 2
	|| tempstr != query("id"))   return 0;
	message_vision(CYN"$N向$n打听关『"HIG + name +NOR+CYN"』的消息。\n"NOR,me,this_object());
	if( name == "你爸爸" || name == "你爹" || name == "你爸爸是谁？" || name == "你爸？"){
		command("smile "+ me->query("id"));
		command("answer "+ me->query("id")+" 我爹就是大名鼎鼎的"+ query("father_name")+"了！我爹的武功好棒的哦！");
		return 1;
	}
	if( name == "你妈妈" || name == "你娘" || name == "你妈妈是谁？" || name == "你娘？"){
		command("xixi "+ me->query("id"));
		command("answer "+ me->query("id")+" 我娘就是"+ query("mather_name")+"呀！我娘对我可好了。");
		return 1;
	}
	if( name == "你是谁生的？" || name == "你是谁的孩子？"){
		command("?");
		command("answer "+ me->query("id")+" 我是"+ query("father_name")+"和"+ query("mather_name")+"的孩子呀！");
		return 1;
	}
	if( name == "你多大？" || name == "多大？" || name == "几岁？" || name == "你今年几岁？"){
		command("think");
		command("answer "+ me->query("id")+" 我今年已经"+ chinese_number(1+ (query("mud_age") / 86400))+"岁了！");
		return 1;
	}
	if( name == "性别" ){
		if( query("gender") == "男性")
			command("answer "+ me->query("id")+" 我是男孩子啊，你看不出来吗？");
		else
			command("answer "+ me->query("id")+" 我是女孩子，你看不出来吗？");
		return 1;
	}
	if( name == "你家在哪？" || name == "你家呢？" || name == "家在哪？" ) {
		command("answer "+ me->query("id")+" 我不告诉你！");
		command("face");
		return 1;
	}
	if( name == "叫爸爸！" || name == "叫爹？" || name == "叫爹" ) {
		if( me->query("id") != query("father_id")
		&& me->query("id") != query("mather_id")){
			if(me->query("gender")!="女性") {
				command("answer "+ me->query("id")+" 叔叔，你很喜欢做我爸爸吗？");
				return 1;
			}else{
				command("answer "+ me->query("id")+" 叔叔，你为什么对爸爸那么感兴趣？");
				return 1;
			}
		}
		else if( me->query("id") == query("mather_id")){
			command("?");
			command("answer "+ me->query("id")+" 娘，你为什么要我管你叫爹呢？");
			return 1;
		}
		command("answer "+ me->query("id")+" 爹！");
		return 1;
	}
	if( name == "叫妈妈！" || name == "叫娘？" || name == "叫娘" ) {
		if( me->query("id") != query("mather_id")
		&& me->query("id") != query("father_id")){
			if(me->query("gender")!="男性") {
				command("answer "+ me->query("id")+" 阿姨，你很喜欢做我妈妈吗？");
				return 1;
			}else{
				command("answer "+ me->query("id")+" 叔叔，你为什么对我娘那么感兴趣？");
				return 1;
			}
		}
		else if( me->query("id") == query("father_id")){
			command("?");
			command("answer "+ me->query("id")+" 爹，你为什么要我管你叫娘呢？");
			return 1;
		}
		command("answer "+ me->query("id")+" 娘！");
		return 1;
	}
	if( name == "叫舅舅" || name == "叫叔叔" || name == "叫伯伯"){
		if( me->query("id") == query("father_id"))
			command("answer "+ me->query("id")+" 爸爸，你不要我了吗？");
		else if( me->query("id") == query("mather_id"))
			command("answer "+ me->query("id")+" 妈妈，你这是怎么了？为什么要我"+ name+"？");
		else if( me->query("gender") == "女性")
			command("answer "+ me->query("id")+" 阿姨，你为什么要我"+ name +"呢？");
		else {
			result_name = name;
			result_name = replace_string(result_name, "叫","");
			command("bow");
			command("answer "+ me->query("id")+" "+ result_name +"好呀！");
		}
		return 1;
	}
	if( name == "叫阿姨" || name == "叫婶婶" || name == "叫姑姑" ){
		if( me->query("id") == query("mather_id"))
			command("answer "+ me->query("id")+" 娘，你不要我了吗？");
		else if( me->query("id") == query("father_id"))
			command("answer "+ me->query("id")+" 爸爸，你这是怎么了？为什么要我"+ name+"？");
		else if( me->query("gender") != "女性")
			command("answer "+ me->query("id")+" 叔叔，你为什么要我"+ name +"呢？");
		else {
			result_name = name;
			result_name = replace_string(result_name, "叫","");
			command("bow");
			command("answer "+ me->query("id")+" "+ result_name +"好呀！");
		}
		return 1;
	}
}
int do_try(string arg)
{
	object me,ob;
	string rank;

	me = this_player();
	ob = this_object();

	if(ob->query("father_id") != me->query("id")
	&& ob->query("mather_id") != me->query("id"))
		return notify_fail("你只能带自己的孩子出去。\n");

	if( !id(arg))
		return notify_fail("你只能带自己的孩子出去玩。\n");

	if(ob->query_temp("sleeping"))
		return notify_fail("你没见孩子睡着了吗？\n");

	if(!environment() || !present(this_object(),environment(me)))
		return notify_fail("孩子都不知道跑哪里去了，还不快去找找？\n");

	if(me->query("gender") == "男性")
		rank = "爹";
	else
		rank = "娘";

	message_vision("$N说道：宝宝乖，"+ rank +"带你出去玩哦！\n",me);
	message_vision("$N高兴的跳了起来，笑道：好呀！"+ rank +"真好。\n",ob);
	message_vision("$N牵着$n的小手，决定带$n出去逛逛街，$n乐得露出了两个小酒窝。\n",me,ob);
	ob->set_leader(me);
	return 1;
}
int do_let(string arg)
{
	object me,ob;

	ob = this_object();
	me = this_player();

	if( ob->query("father_id") != me->query("id")
	&&  ob->query("mather_id") != me->query("id"))
		return notify_fail("你只能控制你的孩子的一切行动。\n");

	if(!present(ob,environment(me)))
		return notify_fail("你的孩子已经不知道跑哪里去了。\n");

	if(!arg || arg == "")
		return notify_fail("你要你的孩子做什么动作？\n");

	command(arg);
	return 1;
}

void die()
{
	object ob;

	message("channel:rumor",HIM"【武林传奇】某人："+ query("father_name")+"和"+ query("mather_name")+"的孩子"+ query("name") +"被杀死了。\n"NOR,users());
	rm(this_object()->query_save_file());
	ob =find_player(query("mather_id"));
	ob->set("baby/die",1);
	ob->save();
	tell_object(ob,"你的孩子"+ query("name")+"死掉了。\n");
	::die();
}
void reset()
{
	save();
}