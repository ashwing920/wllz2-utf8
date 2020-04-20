// cast.c

#include <skill.h>

#define LOWER_LIMIT 10000

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, spl, trg;
	object target, env;
	
	seteuid(getuid());

	if( me->query_temp("sleeping") ) return notify_fail("你现在正躺着呢。\n");

	env = environment(me);
	if( env->query("restrict_action") ) 
		return notify_fail("这里不能做这件事情。\n");

	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能念咒文。)\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("这里不准念咒文。\n");

	if( !arg ) return notify_fail("指令格式：cast <法术> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
	if( target->query("one_enemy")
		&& target->is_fighting()
		&& !target->is_fighting(me))
		return notify_fail(target->name()+"大喝一声：“你想干什么？”。\n");
	if( userp(target) && ( (int) target->query("combat_exp") < LOWER_LIMIT 
		|| target->query("age")<16 )
		&& !me->query("licensed_to_kill") )
		    return notify_fail("唉！你什么时候才可以改掉以强凌弱的恶习？\n");

	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");

	if( stringp(spells = me->query_skill_mapped("spells")) )
		return (int)SKILL_D(spells)->cast_spell(me, spl, target);
		
	return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");
}

int help (object me)
{
	write(@HELP
指令格式：cast <咒文名称> [on <施咒对象>]
 
施法，你必需要指定<咒文名称>，<施咒对象>则可有可无。
在你使用某一个咒文之前，你必须先用 enable 指令来指定你要使用的咒文系。
 
注：如果你改变自己的咒文系，你原本蓄积的法力并不能直接转换过去，必须
    从 0 开始。
 
HELP
	);
	return 1;
}
