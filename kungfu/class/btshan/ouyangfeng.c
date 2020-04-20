///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

static int con = 25 + random(5);

void create()
{
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long",@LONG
他是白驼山庄主，号称“西毒”的欧阳锋。由于习练「九阴真经」走火入
魔，已变得精神错乱，整日披头散发。
LONG
);
	set("title", "老毒物");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIR "西毒" NOR);
	set("shen_type",-1);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 70);
	set("con", 50);
	set("dex", 100);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);
	set("ouyangfeng_son",1);

	set_skill("force",800);
	set_skill("unarmed",800);
	set_skill("dodge",800);
	set_skill("parry",800);
	set_skill("staff",800);
	set_skill("hamagong",800);
	set_skill("chanchu-bufa",800);
	set_skill("shexing-diaoshou",800);
	set_skill("lingshe-zhangfa",800);
	set_skill("training",800);
	set_skill("hand",800);
	set_skill("literate",800);
	set_skill("perception",800);
	set_skill("strike",800);
	set_skill("poison",800);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed","shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("strike","hamagong");
	map_skill("hand","shexing-diaoshou");
	prepare_skill("strike","hamagong");

	create_family("白驼山派",1, "开山祖师");

	set("chat_chance",5);
	set("chat_msg",({
		"欧阳锋道：江湖险恶，困难重重哪！\n",
	}));

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: perform_action, "unarmed.suo" :),
		(: perform_action, "strike.tuitian" :),
		(: perform_action, "dodge.jinchan" :),
		(: perform_action, "dodge.move" :),
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
}
void attempt_apprentice(object ob)
{
	string name,old_name,new_name;

	if((int)ob->query("combat_exp")<500000){
		command("say 你的经验太低了,我还不能收你！");
		return;
	}
	if((int)ob->query("shen") > -100000){
		command("say 白驼山庄向来不与正派人士交往，这位"+ RANK_D->query_respect(ob)+"还是请回吧！");
		return;
	}
	command("say 好！好！我就收下你吧！");
	command("recruit " + ob->query("id"));
	
	name = ob->query("name");
	name = replace_string(name,"欧阳","");

	switch(strlen(name)){
		case 2:	new_name = "欧阳" + name;break;
		case 4:	new_name = "欧阳" + name[2..4];break;
		case 6: new_name = "欧阳" + name[4..6];break;
		case 8: new_name = "欧阳" + name[6..8];break;
		default:
	}
	ob->set("name",new_name);
	return;
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
	add_action("do_callname","jiao");
}
void greeting(object ob)
{
	if(!ob || environment(ob) != environment()) return;
	
	if((int)ob->query("int") > con && (int)ob->query("con") > con
	&& (int)ob->query("age") < 20  && (string)ob->query("gender") == "男性"
	&& !ob->query("ouyangfeng_son")	&& ob->name() == "杨过"){
		message_vision("$N用一种赞许的眼神看了看$n，说道：这位小兄弟真是乖"
			"巧，若你叫我一声爸爸，我便传你武功。\n",this_object(),ob);
		ob->set_temp("oyf_son",1);
		return;
	}
	else if(ob->query("ouyangfeng_son")){
		message_vision("$N亲切的看了看$n，说道：好儿子，看望爸爸来了？\n",this_object(),ob);
		return;
	}
}
int do_callname(string arg)
{
	object me,ob;
	ob = this_object();
	me = this_player();

	if(!me->query_temp("oyf_son")) return 0;

	if(!arg || arg == "")
		return notify_fail("你要叫什么？\n");
	
	if(arg == "爸爸"){
		message_vision("$N恭恭敬敬的对$n叫了一声：爸爸！！\n",me,ob);
		if(me->query("ouyangfeng_son")){
			message_vision("$n亲切的拍拍$N的头，赞许的说道：嗯，好儿子！\n",me,ob);
			return 1;
		}
		else if(me->query_temp("oyf_son")){
			message_vision(HIW"$n脸上一喜，哈哈大笑的应了一声：嗯，我的好儿子！\n"NOR,me,ob);
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
				sprintf("听说%s认贼做父，做了%s的义子。",me->name(1),ob->name()));
			me->set("ouyangfeng_son",1);
			return 1;
		}
		else {
			message_vision("$n疑惑的瞧了瞧$N，说道：你是我哪个时候生的儿子啊？\n",me,ob);
			return 1;
		}
	}
	message_vision("$N对$n叫了一声："+ arg +"。\n可是$n对$N就是不理不采。\n",me,ob);
	return 1;
}
void reset()
{
	con = 25 + random(5);
}
