// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object obj;
        if (duration < 1) {
		message("channel:rumor",HIM"【武林传奇】某人：听说官府已经放弃追杀"+ me->query("name") +"了。\n"+ NOR,users());
                me->add("kill_flag",-1);
                return 0;
        }

	else {
	        me->apply_condition("pker", duration - 1);
	        tell_object(me,YEL"官府现在还在四处查找你的踪迹！\n"NOR);
        
	        if(environment(me)->query("chat_room")
	        || environment(me)->query("fight_room")){
	                me->move("/d/center/guangchang");
	                tell_object(me,"那里不是你能呆的地方。\n");
	                message_vision("$N被人赶了出来。\n",me);
	        }
	        
	        if( random(10) == 4 
	        && !environment(me)->query("no_fight")) {
	        	obj = new("/clone/npc/xunbu");
	        	obj->move(environment(me));
	        	message_vision("$N走了过来。\n",obj);
			message_vision(HIR"\n$N对$n喝道：你这个杀人犯，快束手就擒吧！\n\n"NOR,obj,me);
	        	obj->kill_ob(me);
	        }
        }
	return 1;
}
