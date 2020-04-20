// xiaoer2.c 老何
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
string ask_me();
int do_back(object me);

void create()
{
	set_name("老何", ({ "lao he", "he", "xiao er", "waiter" }) );
	set("gender", "男性" );
	set("age", 92);
	set("neili",10000);
	set("jing",5000);
	set("max_jing",5000);
	set("jiali",500);
	set("max_neili",10000);
	set("dex",180);
	set("str",100);
	set("long",@LONG
老何正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。
LONG
);
	set("combat_exp",1250000);
	set("attitude", "friendly");
	set("demogorgon",1);
	set("rank_info/respect", "老何");
	set("inquiry", ([
		"昆仑派" : "从这上去就是了，不过这位客官路上可要小心。\n",
		"何足道" : (: ask_me :),
		"何太冲" : "那小子最没出息了，哼，就知道怕老婆。\n",
		"何三圣" : "他老人家好久没来过我这喝酒了，当年他老人家常来我这喝酒。他老人家曾以一手满天花雨连败几十位武林高手。\n",
		"生意" : "这个么……马马乎乎，不过我也不在乎！\n",
	]));
	set("vendor_goods", ([
		"/clone/food/jitui": 20,
		"/clone/food/jiudai": 20,
		"/clone/food/baozi": 20,
	]));
	set_skill("force", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("yan-shuangfei",500);
	set_skill("ding-unarmed",500);
	set_skill("unarmed", 500);
	set_skill("blade",500);
	set_skill("wuhu-duanmendao",500);
	map_skill("dodge", "yan-shuangfei");
	map_skill("unarmed", "ding-unarmed");
	map_skill("parry","ding-unarmed");
	map_skill("blade","wuhu-duanmendao");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();
}
string ask_me()
{
	object me; 
	me = this_player();
	
	me->add_temp("hezuodao_ask",1);
	message("vision", HIY "老何大喝一声：他老人家的大名也是你能叫的吗？\n"NOR, environment(), this_object() );

	if (me->query_temp("hezuodao_ask") > 2){
			kill_ob(this_player());
			this_player()->kill(this_object());
			me->delete_temp("hezuodao_ask");
				return "我这把老骨头和你拼了！";
		}else
				return "你再说一次我杀了你！";
}               
void init()
{          
	object ob,me; 
	mapping myfam; 
	ob = this_player();
	me = this_object();

	if( !me->query("waiting_target") && ob->query_temp("fee_paid") ) 
		ob->delete_temp("fee_paid");
	if (me->query("startroom")!=base_name(environment())) return;
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
			&& myfam["family_name"] == "丐帮" 
			&& ob->query_skill("begging",1) > 60 ){
				remove_call_out("saying");
				call_out("saying", 0, ob);
		}else { 
				remove_call_out("greeting");
				call_out("greeting", 1, ob);
	}
	add_action("do_name","杀");
	add_action("do_vendor_list", "list");
}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		switch( random(2) ) {
			case 0:
			say( "老何笑咪咪地说道：这位" + RANK_D->query_respect(ob)+ "，进来喝几盅酒，歇歇腿吧。\n");
			break;
			case 1:
			say( "老何用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)+ "，请进请进。\n");
			break;
	}
	if( ob == this_object()->query("waiting_target")){
		this_object()->kill_ob(ob);
		ob->kill_ob(this_object());
	}
	
}
void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	say("\n老何大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
		
}
void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	ob->move("/d/mingjiao/shanjiao");
	message("vision","只听“乒”地一声，" +  ob->query("name") +"被人从小店里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
int do_name(string target)
{
	object me, dest, *all,ob;
 
	me = this_object();
	all = livings();
	if(me->query("waiting_target"))
		return notify_fail(me->name()+"嘿嘿一笑：我现在正忙着哪，您呆会儿在来吧！\n");
	
	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail(me->name()+"大声叫到：杀人啦，救命呀！\n");
	if (base_name(environment())!=query("startroom")){
		return notify_fail(me->name()+"四下望了望，说道：这种事在这里说不太妥当吧！\n");
	 }
	if( !target || target==" ") 
		return notify_fail(me->name()+"恶狠狠地说道：快告诉我那家伙的名字，我可没功夫听你闲聊！\n");
	foreach (dest in livings()) {
		if( target == dest->name(1) || dest->id(target) ) 
		break;
	}
	
	if( !dest || !environment(dest))
		return notify_fail(me->name()+"一声冷笑：他现在不在游戏中，过会再来吧。\n");
		
		if(!(target == dest->name(1) || dest->id(target)) )
		return notify_fail(me->name()+"一声冷笑：他现在不在游戏中，过会再来吧。\n");
	if (dest->is_ghost())
		return notify_fail(me->name()+"很不高兴：他已经是个死鬼了，你还来找我干什么！\n");
	this_player()->delete_temp("fee_paid");
	me->set("waiting_target", dest);
	me->set_temp("apply/attack", 10000);
	me->set_temp("apply/defense",10000);
	me->set_temp("apply/damage", 10000);
	me->set_temp("apply/armor",10000);
	me->delete("chat_chance");
	me->delete("chat_msg");
	if (dest==me){
		tell_object(this_player(),"你是来找岔的吧？\n");
		me->kill(this_player());
		me->set("waiting_target", this_player());
		call_out("do_chase", 1, me);
		return 1;
	}               
	if (dest==this_player()){
		tell_object(this_player(),"既然你活腻了，大爷就送你一程！\n");
		me->kill(this_player());
		this_player()->kill(me);
		me->set("waiting_target", this_player());
		call_out("do_chase", 1, me);
		return 1;
	}               
	if (userp(dest) && random(100)>35) { 
		me->delete("waiting_target"); return notify_fail(me->name()+"古怪地笑了笑，摇了摇头。\n"); 
	}
	tell_object(this_player(),"老何阴笑了几声，说道：杀"+dest->name()+"？您就在这儿静侯好音吧！\n");
	me->set("pursuer", 1);
	ob=this_player();
	if((ob->query_temp("pker_starttime")+900*ob->query_temp("pker_time")) <ob->query("mud_age")){
		ob->set_temp("pker_starttime",ob->query("mud_age"));
		ob->delete_temp("pker_time");
	}
	ob->add_temp("pker_time",1);

	set_name("雾中楼", ({ "wuzhong lou", "lou", }) );
	set("long","从雾中楼刀削的脸上你几乎看不出任何的喜怒哀乐。\n");
	delete("inquiry");
	command("go west");
	CHANNEL_D->do_channel(me,"arch",sprintf("%s雇佣"+me->name()+"杀%s",this_player()->query("name"),dest->query("name")));
	log_file("buykiller",sprintf("%s在"+ ctime(time())+"雇佣"+me->name()+"杀%s\n",this_player()->query("name"),dest->query("name")));
	call_out("do_chase", 1, me);
	return 1;
}
int accept_object(object who, object ob)
{
	object me=this_object();
	if (ob->query("money_id") && ob->value() >= 10000000
	&& !this_object()->query("waiting_target")) {
	if( this_player()->query("age")< 18 ) {
		tell_object(who, me->name()+"沉下脸来：小孩子的生意我不做，快回家找你爹妈吧。\n");
		return 1;
	}
		tell_object(who, me->name()+"沉下脸来：好，爽快说吧，你要我帮你杀谁？\n");
		tell_object(who, "请键入：杀 目标\n");
		who->set_temp("fee_paid",1);
		return 1;
	}
	else if (ob->query("money_id") && ob->value() < 10000000) 
	{
		tell_object(who, me->name()+"嘿嘿一笑，说道：给我这麽多钱？ 将来我可没法还你啊。\n");
		return 1;
	}
	return 0;
}
int do_chase(object me)
{
	
	object dest;
	dest = me->query("waiting_target");
	
	if( !objectp(dest) || !environment(dest) )  {
		call_out("waiting", 0, me);
		return 1;
	}
	if ( !environment(dest)->query("fight_room") || !environment(dest)->query("freeze") ){
		message("vision",me->name()+"走了出去。\n" NOR, environment(me));
		me->move(environment(dest));
		message_vision("$N走了过来。\n" NOR, me);
		me->set_leader(dest);
		command("look " + dest->query("id"));
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}
	return 1;
}
int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))){
		message_vision(HIR "$N闷声不吭，突然对$n发起攻击。\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->kill_ob(me);
	}
	else
		call_out("waiting", 1, me);      
	
	return 1;
}

void killed_enemy(object obj)
{
	object me=this_object();
	
	if (obj!=me->query("waiting_target"))
	call_out("do_chase",1,me);
	else
	call_out("do_back", 1, me);
}
int waiting(object me)
{
	object dest;
	dest = me->query("waiting_target");
	
	if ( objectp(dest) ){
		if (dest->is_ghost()){
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me))){
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight")){
			call_out("do_chase", 0, me);
			return 1;
		}
	}else return do_back(me);
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
	return 1;
}

int do_back(object me)
{
	me->move("/d/kunlun/sbxd");
	me->delete("waiting_target");
	set_name("老何", ({ "lao he", "he", "xiao er", "waiter" }) );
	set("long", "老何正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	message("vision", me->name(1)+"走了进来，拍了拍身上的尘土，把剑上的血迹抹拭干净，\n"
		"他接着一笑说道：老天爷保佑，活儿干得干净利落，您老以後有什麽事还可以找我。\n", 
	environment(), me );
	me->set_leader(0);
	me->set("inquiry", ([
		"昆仑派" : "从这上去就是了，不过这位客官路上可要小心。\n",
		"何足道" : (: ask_me :),
		"何太冲" : "那小子最没出息了，哼，就知道怕老婆。\n",
		"何三圣" : "他老人家好久没来过我这喝酒了，当年他老人家常来我这喝酒。他老人家曾以一手满天花雨连败几十位武林高手。\n",
		"生意" : "这个么……马马乎乎，不过我也不在乎!\n",
	]));
	return 1;
}
int return_home(object home)
{
	object me=this_object();
	if( !me->query("waiting_target") )
	return ::return_home(home);
	return 1;
}
