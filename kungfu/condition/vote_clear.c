// vote_clear.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1) return 0;
	me->apply_condition("vote_clear", duration - 1);
	if (duration == 1) {
		tell_object(me, HIM "因为响应的人不多，对你的投票取消了。\n" NOR);
		me->delete("vote/reason");
		me->delete("vote/juror");
		me->delete("vote/count");
	}
	return 1;
}
string type() { return "no_clear";}