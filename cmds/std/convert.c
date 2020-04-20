// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object snake,weapon;
	string race,weapon_id,long;
	mapping fam;

	seteuid(getuid());

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法驱蛇。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须先找到一把杖。\n");

	if(arg == "none"){
		if(!weapon->query("race"))
			return notify_fail(weapon->name()+"中并没有附蛇。\n");

		weapon->delete("race");
		weapon->set("long",weapon->query("old_long"));
		message_vision("$N将"+ weapon->name() +"的蛇放开了。\n",me);
		return 1;
	}

	if(!arg || sscanf(arg,"%s on %s",race,weapon_id) != 2)
		return notify_fail("指令格式：convert <蛇> on <兵器>\n");


	if(!objectp(snake = present(race,environment(me)))
	|| (string)snake->query("race") != "蛇类")
		return notify_fail("你只能将蛇附入你的"+ weapon->name()+"。\n");

	if((int)me->query_skill("training",1) < 100 )
		return notify_fail("你的驯兽术不够娴熟，无法驱蛇附杖。\n");

	if(!mapp(fam = me->query("family")) || fam["family_name"] != "白驼山派")
		return notify_fail("你无法理解驯兽术当中的技巧，想要驱蛇附杖恐怕为时过早。\n");

	if((int)me->query("jingli") < 300)
		return notify_fail("你的精力不足，无法驱蛇附杖。\n");

	if(weapon->query("race"))
		return notify_fail("你的"+ weapon->name()+"上已经附着一条蛇了。\n");

	if(snake->query_temp("owner") != me->query("id"))
		return notify_fail(snake->name() + "还没有被你驯服，你无法驱使它。\n");

	if(snake->is_fighting())
		return notify_fail(snake->name()+"正在战斗，对你的驱使毫不理会。\n");

	message_vision("$N口中喃喃自语，不知道说了些什么，$n立刻乖乖的一缩一缩的附上了"+ weapon->name()+"。\n",me,snake);
	weapon->set("race",base_name(snake));
	long = weapon->query("long");
	weapon->set("old_long",long);
	long += "只见上面盘着"+ snake->query("long");
	weapon->set("long",long);
	me->add("jingli",-300);
	destruct(snake);
	return 1;
}

int help(object me)
{
	write(@HELP

指令格式：

	convert <蛇> on <兵器>  驱蛇附杖
	convert none 		驱蛇离杖

这个指令是白驼山派的弟子用来驱蛇附入杖中。

HELP
	);
	return 1;
}
