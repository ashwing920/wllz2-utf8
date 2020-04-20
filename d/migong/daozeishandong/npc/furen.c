//furen.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("妇人",({ "furen"}));
	set("long",@LONG
一个脏兮兮的妇人，手上绑着一条麻绳。想必被山贼们抓来这里已经有一
段时间了。她正用一种恐惧而又祈求的眼光看着你，甚是可怜，快把她救
(saveme)出去吧。
LONG);
	set("age", random(20)+20);
	set("gender", "女性");
	set("str", 30);
	set("dex", 20);
	set("savenpc",1);
	setup();
	carry_object("/clone/cloth/cloth")->wield();
}
void init()
{
	add_action("do_saveme","saveme");
	add_action("do_give","give");
}
int do_saveme(string arg)
{
	object me,obj;
	me = this_player();
	obj = this_object();

	if(!id(arg)) return 0;
	if(obj->query("saveme")) return 0;

	message_vision("$N连忙将$n身上的麻绳解开，说道：你快跟我走吧！\n",me,obj);
	message_vision("$n摸摸已经被麻绳勒得通红的手腕，拼命的点了点头。\n",me,obj);
	tell_object(me,obj->name()+"决定跟随着你一起行动。\n");
	obj->set_leader(me);
	if(me->query_temp("apply_job/guanfu/quest",1)
	&& me->query_temp("apply_job/guanfu/place") == "盗贼山洞"){
		obj->set("saveme",me);
	}
	return 1;
}
int do_give(string arg)
{
	object me,ob,target;
	mapping guanfu;
	me = this_player();

	if(!arg || arg == "") return 0;
	if(sscanf(arg,"%s to %s", ob, target)!=2 )
	if(sscanf(arg,"%s %s", target, ob) !=2 ) return 0;
	if(!id(ob) ) return 0;
	if(!mapp(guanfu = me->query_temp("apply_job/guanfu"))) return 0;

	if(!ob = present(target,environment(me)) )
		return notify_fail("你想要把"+ this_object()->name() +"交给谁？\n");

	if(!living(ob) )
		return notify_fail("看来要先把"+ ob->name()+"救醒再说。\n");

	if(!living(this_object()))
		return notify_fail("看来要先把"+ this_object()->name()+"救醒再说。\n");

	if(!ob->is_guanfu())
		return notify_fail("你不能把"+ this_object()->name() +"交给"+ ob->name()+"。\n");

	if(this_object()->query("saveme") == me){
		tell_object(me,"你将"+ this_object()->name()+"交给了官府，完成了解救的任务。\n");
		me->add_temp("apply_job/guanfu/save_npc",1);
	}
	destruct(this_object());
	return 1;
}
