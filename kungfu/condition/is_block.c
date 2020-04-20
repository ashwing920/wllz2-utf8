// is_block.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1) return 0;
	me->apply_condition("is_block", duration - 1);
	if( duration == 1){
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s耳目一新的从暗房走了出来，整个人看起来白皙了许多。",me->query("name")));
		me->move("/d/center/guangchang");
		tell_room( environment(me),HIY"\n一只大脚把"+ me->query("name")+"从暗房踢了出来，骂道：看你下次再胡作非为，哼！\n\n"NOR,({ me }));
		me->enable_player();
		me->set("startroom","/d/center/guangchang");
		me->save();
	}
	else if(!environment(me)->query("parsion_room")){
		me->move("/adm/parsion/jianyu");
		tell_object(me,HIW"狱卒摇了摇头道：你的刑期还没到，回去服刑吧！\n"NOR);
	}
	return 1;
}
string type() { return "no_clear";}