// apply_guanfu.c

#include <login.h>

int update_condition(object me, int duration)
{
	if(duration < 1) return 0;
	if(duration == 1){
		me->delete_temp("apply_job/guanfu");
	}
	me->apply_condition("apply_guanfu", duration - 1);
	return 1;
}
