// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object env;
	env = environment(me);

	if( duration < 1) return 0;
	me->apply_condition("killer", duration - 1);

	if(duration == 1){
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说官府已经放弃追捕%s了！",me->name()));
	}
	else {
		if(random(8) == 7)
			tell_object(me,HIB"官府现在正在通缉你，还是快找个地方躲起来吧！\n"NOR);
		if((env->query("no_fight") || env->query("playerhouse")) 
			&& !env->query("parsion_room")){
			tell_object(me,"突然一个声音喝道：喂！那里不是你能呆的地方，滚！\n");
			message_vision("$N被人从"+ env->short() +"赶了出去，十分狼狈。\n",me);
			me->move("/d/center/guangchang");
		}
	}
	return 1;
}
