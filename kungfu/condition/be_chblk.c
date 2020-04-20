// is_block.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1) return 0;
        me->apply_condition("be_chblk", duration - 1);
        if( duration == 1){
        	me->delete("chblk");
		tell_object(me,HIW"\n系统告诉你：你的聊天频道现在已开启，请勿滥用聊天频道，多谢合作！\n"NOR);
        }
        return 1;
}
string type() { return "no_clear";}