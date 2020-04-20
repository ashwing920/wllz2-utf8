// furen.c 夫人

#include <ansi.h>
int ask_get_baby();
int ask_put_baby();
inherit NPC;

void create()
{
	set_name("梦茹", ({ "meng ru","meng","mother" }));
	set("gender", "女性");
	set("long",@LONG
她是在托儿所负责看护孩子的梦茹。
LONG
);
	set("per",30);
	set("age",25);
	set("int",25);
	set("dex",25);
	set("str",25);
	
	set("combat_exp",20000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set("inquiry",([
		"带走孩子": (: ask_get_baby :),
		"托管孩子": (: ask_put_baby :),
	]));
	setup();

	add_money("silver",3);
	carry_object("/clone/cloth/female3-cloth")->wear();
}
int ask_get_baby()
{
	object me,obj;
	me = this_player();
	
	if( me->query("gender") != "女性"){
		command("say 只有孩子的母亲才可以到这里来带走孩子。");
		return 1;
	}
	if( !me->query("baby")){
		command("say 这位"+ RANK_D->query_respect(me)+"还没孩子呢！");
		return 1;
	}
	if( me->query("baby") && me->query("baby/die")){
		command("poor");
		command("say 你的孩子已经死了呀！sigh . . . ");
		return 1;
	}
	if( me->query("baby/get")){
		command("say 你的孩子不已经带走了吗？");
		return 1;
	}
	if( present(me,environment(this_object()))){
		obj = new("/clone/npc/baby");
		obj->set_name(me->query("baby/name"),({ me->query("baby/id"),"baby" }));
		obj->restore();
		obj->move(me);
		me->set("baby/get",1);
		me->set("baby/put",0);
		message_vision("$N转身从托儿所里抱出了一个孩子，你仔细一看，那正是$n呢！\n",this_object(),obj);
		message_vision("$N对$n说道：小宝宝，快随你妈妈去吧！\n",this_object(),obj);
		message_vision("$N欢天喜地的扑到$n怀里，亲切的叫道：娘！娘！！\n",obj,me);
		command("say 孩子带回去吧，记得离线的时候可要带过来["HIG"托管孩子"NOR + CYN"]哟！");
		return 1;
	}
}
int ask_put_baby()
{
	object me,obj;
	me = this_player();
	
	if( !me->query("baby")){
		command("say 你还没有生儿育女呢，哪来的孩子啊？");
		return 1;
	}

	if(!objectp(obj = present(me->query("baby/id"),me))){
		command("say 孩子呢？你可别把自己的孩子弄丢了呀！");
		return 1;
	}

	if( !me->query("baby/get")){
		command("say 你的孩子是从哪来的？");
		CHANNEL_D->do_channel(this_object(),"chat",sprintf("快来人啊！%s居然拐带人家的孩子！",me->query("name")));
		return 1;
	}
	if( !wizardp(me) && !me->query_temp("give_baby_money")){
		command("say 你还没给钱呢，孩子饿了可怎么办？");
		tell_object(me,"你必须先给"+ this_object()->name() +"一两黄金做为孩子的照看费用！\n");
		return 1;
	}
	if( present(me,environment(this_object()))){
		obj->move(environment(me));
		message_vision("$N把$n从怀里放下，对$n说道：宝宝乖，快跟阿姨玩去，可要听话哦！\n",me,obj);
		message_vision("$n恋恋不舍的看着$N，眼角闪动着晶莹的泪花！\n",me,obj);
		command("pat "+ obj->query("id"));
		command("say 宝宝乖，阿姨带你玩去，给你糖吃哦！");
		message_vision("$N傻傻的点了点头，嘟囔的说了声：哦。\n",obj);
		message_vision("$n跟着"+ this_object()->name() +"走进了托儿所，还回头看了$N一眼。\n",me,obj);
		destruct(obj);
		me->set("baby/get",0);
		me->set("baby/put",1);
		me->delete_temp("give_baby_money");
		me->save();
		return 1;
	}
}
int accept_object(object who, object ob)
{
	if( ob->value() >= 10000 ) {
		message_vision("$N笑了笑，对$n说道：好吧，请用["HIG"ask meng ru about 托管孩子"NOR"]将你的孩子交给我！\n",this_object(),who);
		who->set_temp("give_baby_money",1);
		} 
	else   {
		command("say 就这点儿钱？还不够买奶粉和玩具呢！");
		return 0;
	}
	return 1;
}
