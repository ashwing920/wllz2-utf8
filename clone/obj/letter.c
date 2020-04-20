#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("信", ({"xin"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一封信。\n");
		set("unit", "封");
		set("no_get", 1);
		set("no_get_from",1);
		set("no_put",1);
	}
	setup();
}
void init()
{
	add_action("do_give", "give");
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me;
	me = this_player();

	if(!id(arg)) return 0;
	if(me->query("quest/quest_type") == "把信交给") {
		message_vision("$N丢下一封信。\n",me);
		me->delete("quest");
		me->delete("task_time");
		me->delete_temp("good_letter");
		me->set("letter_fail_time",time() + 60);
		destruct(this_object());
		return 1;
	}

}

int do_give(string arg)
{
	object me,ob,money;
	string obj,target;

	int i,j;

	me = this_player();
	i = (int)me->query("quest/exp_bonus");
	j = (int)me->query("quest/pot_bonus");

	if(!arg || arg==" ") return 0;
	if (sscanf(arg,"%s to %s", obj, target)!=2 )
		if(sscanf(arg,"%s %s", target, obj) !=2 )
		return 0;

	if(!id(obj) ) return 0;

	if(!ob = present(target,environment(me)) ) {
		tell_object(me,"你想要把信件交给谁？\n");
		return 1;
	}
	if(ob->query("name") != me->query("quest/quest") || userp(ob)) {
		tell_object(me,"你不能把这样东西给这个人。\n");
		return 1;
	}

	if(!living(ob) ) {
		tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
		return 1;
	}

	if(time() > (int)me->query("quest/task_time")) {
		message_vision("$N说道：你怎么现在才送来？我的事情都被你耽误了！！\n"+NOR, ob, me);
		me->delete_temp("good_letter");
	}
	else {
		message_vision("$N对$n说道：这趟辛苦你了，这是你的报酬！\n",ob,me);
		tell_object(me,"你成功地将信送到了" + ob->query("name") + "的手中。\n");
		tell_object(me, sprintf(HIC"你被奖励了%s点战斗经验，%s点潜能和一些银两。\n"NOR, chinese_number(i),chinese_number(j)) );
		me->add_temp("good_letter",1);
		me->add("combat_exp", i);
		me->add("potential",j);
		me->delete("quest");
		me->delete("task_time");
		money=new("/clone/money/silver");
		money->set_amount(j/5);
		money->move(me,1);
	if(me->query_temp("good_letter") >= 3) {
		me->add("score",1);
		tell_object(me,"你的江湖阅历增加了一点。\n");
		SCORE_D->set_score(me);
		me->delete_temp("good_letter");
		}
	}
	me->receive_damage("qi", 30);
	me->receive_damage("jing", 30);
	destruct(this_object());
	return 1;
}
void owner_is_killed() { destruct(this_object()); }
