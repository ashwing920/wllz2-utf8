// is_flood.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1) return 0;
	me->apply_condition("is_flood", duration - 1);
	if( duration == 1){
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s口气清新的从厕所走了出来。",me->query("name")));
		me->move("/d/center/guangchang");
		tell_room( environment(me),HIY"\n一只大脚把"+ me->query("name")+"从厕所踢了出来，骂道：看你下次再造谣生事，哼！\n\n"NOR,({ me }));
		me->enable_player();
		me->set("startroom","/d/center/guangchang");
		me->save();
	}
	else if(!environment(me)->query("parsion_room")){
		me->move("/adm/parsion/cesuo");
		tell_object(me,HIW"厕所所长摇了摇头道：你还没漱口呢！快回去！\n"NOR);
	}
	return 1;
}
string type() { return "no_clear";}