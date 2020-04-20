//enchant.c
//Design By Robert 蝴蝶君

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts,max_pts;

	if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail("指令格式：enchant <每次使用几成精力>|none\n");

	if( arg=="none" ) {
		me->delete("jiajing");
		write("Ok.\n");
		return 1;
	}
	max_pts = (int)me->query_skill("force") / 4;
	if( pts < 0)
		return notify_fail("你只能用 none 表示不用精力，或数字表示每一击用几点精力。\n");
 	if( pts > max_pts)
 		return notify_fail("以你现在的等级，你只能把精力点数激发到 "HIC + max_pts +NOR" 点。\n");

	me->set("jiajing", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enchant <使用几点精力>|none
 
enchant none 则表示你不使用精力。 

See Also: enable
HELP
        );
        return 1;
}
