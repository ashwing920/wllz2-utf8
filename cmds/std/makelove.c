// makelove.c

#include <ansi.h>

void over(object,object);

int main(object me, string arg)
{
	object obj;
	object *ob;

	int i;

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想和谁做爱？\n");

	if( !obj->is_character() || obj->is_corpse())
		return notify_fail("连死的你也想搞啊？\n");

	if((string)me->query("gender")== (string)obj->query("gender"))
		return notify_fail("对不起，目前不开放同性恋，请洁身自爱。\n");

	if((string)me->query("gender") == "无性")
		return notify_fail("你是太监，有心无力，还是算了吧。\n");

	if( obj->query("gender") == "无性")
		return notify_fail("你有心，他无力，还是算了吧。\n");

	if(!living(obj))
		return notify_fail("人家都这样了，你还...\n");

	if((string)obj->query("race") != "人类")
		return notify_fail("你找错对象了吧？它不是人呀！\n");

	if((int)me->query("age") < 18)
		return notify_fail("你年纪还小，这种东西以后再说吧。\n");
	if((int)obj->query("age")< 18)
		return notify_fail("对方还没有成年呢，搞什么搞？\n");

	if(environment(me)->query("outdoors"))
		return notify_fail("不是吧？光天化日之下，有伤风化的！\n");

	if( !environment(me)->query("sleep_room")|| environment(me)->query("no_sleep_room"))
		return notify_fail("这种事情总得找个温馨点儿的地方吧？\n");

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
		if( ob[i]->is_character()&&ob[i]!=me
			&&ob[i]!=obj&&!wizardp(ob[i]) )
			return notify_fail("这儿还有别人呢，多不好意思呀！\n");
	if(!me->query_temp("makelove/quest")){
	if((me->query("gender")=="男性")){
	message_vision(HIM "$N轻轻来到$n身后，双手环抱在$n的腰间，在$n耳边柔声说道：亲爱的，今晚...\n"NOR,me,obj);
		tell_object(obj, HIR"傻子也能看出来他想和你共渡良宵，如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
	}
		else {

	message_vision(HIM "不知是因为烛光，还是酒精，亦或是因为兴奋，$N的小脸儿红红的，端着酒杯，\n$N直勾勾地盯着$n：亲爱的...听说...喝酒...乱性...\n"NOR,me,obj);
	tell_object(obj, HIR "傻子也能看出来她想和你共渡良宵，如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
	}
		obj->set_temp("makelove/quest",1);
	}
	else {
	if((me->query("gender")=="男性")){
		message_vision(HIM "$N回敬似的盯着$n的眼睛，半晌一言不发，突然一把抱住$n，\n一双热唇堵住了$n的嘴，让$n简直喘不上来气，酒杯、红烛打了一地...\n"NOR,me,obj);
		call_out("over", 2, me,obj);
		if( obj->query("gender") == "女性"
		&& !obj->query("baby")
		&& me->query("marry") == obj->query("id")
		&& obj->query("marry") == me->query("id")
		&& random(me->query_con()) <= (me->query("con"))
		&& random(obj->query_con()) >= (obj->query("con")))
			obj->apply_condition("baby",600);

		}
		else {
		message_vision(HIM "$n甚至能看见$N羞红的耳根，$N轻轻挣开$n的怀抱，默默地焚香沐浴，\n$n却再也忍不住，一把将$N抱了起来...\n"NOR,me,obj);
		if( me->query("gender") == "女性"
		&& !me->query("baby")
		&& me->query("marry") == obj->query("id")
		&& obj->query("marry") == me->query("id")
		&& random(me->query_con()) <= (me->query("con"))
		&& random(obj->query_con()) >= (obj->query("con")))
			me->apply_condition("baby",600);

		call_out("over", 2, obj,me);
		}
		me->delete_temp("makelove/quest");
	}


	return 1;
}


void over(object me,object obj)
{
	write(CLR);

	message_vision(HIR"\n\n...一阵疾风骤雨...花开花落....\n\n\n"NOR,me);
	if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30){
		if(me->query("qi")<30||me->query("jing")<30){
			message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n"NOR,me);
			me->unconcious();
	}
		else{
			message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n"NOR,obj);
			obj->unconcious();
		}
	}
	else
	switch(random(10))
	{
	case 0:
		message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,me);
		me->unconcious();
		obj->add("qi",obj->query_str()-55+random(10));
		obj->add("jing",obj->query_con()-55+random(10));
		break;
	case 1:
		message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,obj);
		obj->unconcious();
		me->add("qi",obj->query_str()-55+random(10));
		me->add("jing",obj->query_con()-55+random(10));
		break;
	default:
		if(random(1)){
		message_vision(YEL "$N坐在一旁闷头不语，望了一眼仍在微微娇喘的$n，喃喃说到：要不然...再让我试一次...\n"NOR,me,obj);
		}
		else{
		message_vision(HIY "$n静静地躺在$N的怀里，靠着那起伏的胸膛，听着那均匀的呼吸，感到无限的幸福...\n"NOR,me,obj);
	}
		obj->add("qi",obj->query_str()-55+random(10));
		obj->add("jing",obj->query_con()-55+random(10));
		me->add("qi",obj->query_str()-55+random(10));
		me->add("jing",obj->query_con()-55+random(10));
	}
	if(random(10) == 5
	&& me->query("marry") != obj->query("id")
	&& obj->query("marry") != me->query("id"))
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
		sprintf("听说%s和%s在「%s」花前月下，享尽鱼水之欢，好不快活！",me->name(),obj->name(),
		environment(me)->query("short")));
}

int help(object me)
{
  write(@HELP

做爱！

指令格式 : makelove <人物>

相关知识参看初中《生理卫生》课本

HELP
    );
    return 1;
}
