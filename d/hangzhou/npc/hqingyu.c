// hqingyu.c 胡庆余
// Design By Ymh 飞影 email:stcoolman@163.ent

#include <ansi.h>
inherit NPC;
string ask_per();
string change_name();
int check_legal_name(string arg);

string *banned_name = ({
	"你","我","他","她","它","爸","妈","操","干","测试","使用者",
	"扑","爷","奶","婆","叔","姨","爹","做爱","色狼","交","嫖","强奸","调戏","尝试",
	"性","的","妓","哥","姐","哈","嘻","呵","巫师","天神","神仙","大圣","大帝",
	"天帝"," ",MUD_NAME,code_name(),
});

void create()
{
	set_name("胡庆余",({ "hu qingyu","hu","qingyu" }));
	set("title","药店老板");
	set("long",@LONG
他是这家药店的老板，除了高超的医术之外，私底下还帮人家做一些其他
的事情，比如：改名、整容。不过收费当然是非常昂贵的了。
LONG
);
	set("gender","男性");
	set("age",40);
	set("per",40);
	set("int",40);
	set("str",40);
	set("cps",40);
	set("con",40);
	set("kar",40);

	set("combat_exp",30000);
	set("inquiry",([
		"整容": (: ask_per :),
		"改名": (: change_name :),
		"费用" : "嘿嘿，不多，一次一百两而已！",
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",20);
}

void init()
{
	object ob;
	ob = this_player();

	if(ob->query_temp("unconcious")) return;
	if(interactive(ob) && !is_fighting() ) {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
	}
	add_action("do_name","改");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(1) ) {
		case 0:
			say( "胡庆余笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来随便看看吧。\n");
			break;
		}
}

string change_name()
{
	object ob;
	ob = this_player();

	ob->set_temp("ask_name",1);
	return"你要改名换姓？！这好办，每次一千两黄金就给你改！";

}

string ask_per()
{
	object ob;
	ob = this_player();

	if( ob->query("per") > 40)
		return "你的容貌简直无人可比，老夫帮不了你了。";

	command("look "+ ob->query("id"));
	command("say 太可怜了，长得这个样子.....");
	command("whisper "+ ob->query("id") +"  整容一次须给一百两黄金，你付得起吗？嘿嘿！");
	ob->set_temp("ask_per",1);
		return "天下没有不要钱的午餐，你可要慎重考虑哟！";
}

int accept_object(object who, object ob)
{
	who = this_player();

	if( who->query_temp("ask_per")) {

	if(ob->query("money_id") && ob->value() >= 1000000){
		tell_object(who, "胡庆余说道：好好！请稍等一会！\n");
		who->set_temp("give_per_money",1);
		remove_call_out("changeing");
		call_out("changeing",5,who);
		return 1;
	}
}

	if( who->query_temp("ask_name")) {
	if( ob->query("money_id") && ob->value() >= 10000000)

	{
		tell_object(who, "胡庆余低头沉思了一会儿，说道：好吧，那您想取个什么样的名字呢？\n");
		tell_object(who, "请您自己输入：改 新的中文名字\n");
		who->set_temp("fee_paid",1);
		return 1;
	}
}
	command("say 哎呀！可真是谢谢你了！");
	return 1;
}

void changeing()
{
	object ob;
	ob = this_player();

	if(!ob) return;
	if( ob->query_temp("give_per_money") && ob->query_temp("ask_per")){
	message_vision("胡庆余拿出一罐紫红色的胭脂，轻轻的往$N脸上抹去。\n",ob);
	ob->delete_temp("give_per_money");
	ob->delete_temp("ask_per");
	ob->add("per",1);
	tell_object(ob,HIG"你只觉得脸上一阵麻痹过后，又舒服了许多......\n"NOR);
	tell_object(ob,HIC"你的魅力增加了，你现在的魅力值是"+chinese_number(ob->query("per"))+"点！\n"NOR);
	return;
	}

}

int do_name(string target)
{
	int i;
	mapping name;
	object me;
	string old_name;


	me = this_player();
	old_name = me->query("name");
	i = strlen(target);

	if( (strlen(target) < 2) || (strlen(target) > 8 ) )
		return notify_fail("胡庆余一脸遗憾的说道：对不起，你的中文名字必须是 1 到 4 个中文字。\n");

	while(i--){
		if( target[i]<=' ' )
			return notify_fail("胡庆余摇了摇头，说道：对不起，你的中文名字不能用控制字元。\n");


		if( i%2==0 && !is_chinese(target[i..<0]) )
			return notify_fail("胡庆余遗憾的说道：对不起，请您用「中文」取名字。\n");

	}

	for(i=0; i<sizeof(banned_name); i++) {
		if( strsrch(target, banned_name[i]) == -1) continue;
		return notify_fail("胡庆余严肃的说：对不起，这种名字会造成其他人的困扰。\n");

	}

	if( !me->query_temp("fee_paid") )
		return notify_fail("胡庆余笑道：想改名字必须先给钱的哦！\n");

	if( !target || target==" ")
		return notify_fail("胡庆余说道：改名字要这样打：改 <新名字> \n");

	if( old_name == target )
		return notify_fail("胡庆余惊讶的说道：您的钱是不是想送给我？\n");

	if( target == "胡庆余")
		return notify_fail("胡庆余笑道：莫非您是喜欢在下的名字？\n");

	if(!PNAME_D->check_name(target))
		return notify_fail("胡庆余摇了摇头说：这个名字已经有人使用了，想个别的吧。\n");

	PNAME_D->del_name(me->query("id"),old_name);

	CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s从今日起已经改名为「%s」，大家以后可别认错了人啦！......",me->name(),target));
	me->delete_temp("fee_paid");
	me->delete_temp("ask_name");
	me->set("name", target);
	PNAME_D->add_name(me->query("id"),target);
	return 1;

}
