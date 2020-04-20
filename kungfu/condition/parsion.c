// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1) return 0;
	me->apply_condition("parsion", duration - 1);
	if( duration == 1){
		me->delete("thief");
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("为了节省国家粮食，听说%s(%s)已经被赶出了监狱。",
				me->name(1),me->query("id")));
		me->move("/d/center/guangchang");
		me->set("startroom","/d/center/guangchang");
		me->save();
		return 1;
	}
	if(!environment(me)->query("parsion_room")){
		tell_object(me,HIY"狱卒喝道：你想越狱啊？小心你的脑袋！\n"NOR);
		me->move("/d/xingbu/qiushi1");
	}
	return 1;
}
string type() { return "no_clear";}