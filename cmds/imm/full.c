// full.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;
	int jin, qi, zhili, neili, shiwu, yinshui;

	 if (wiz_level(me) >= wiz_level("(wizard)") ){
		if(arg){
		if (!find_player(arg))
			return notify_fail(HIR"这个玩家不在线上！\n"NOR);
			ob = find_player(arg);
		}
		if(!arg) ob=me;
	}
	else
	{
		if(!arg) ob=me;
		if(arg) ob=me;
	}

	jin = ob->query("max_jing");
	qi =ob->query("max_qi");
	zhili = ob->query("max_jingli");
	neili = ob->query("max_neili");
	shiwu = ob->max_food_capacity();
	yinshui = ob->max_water_capacity();
	ob->set("eff_jing", jin);
	ob->set("eff_qi", qi);
	ob->set("jing", jin);
	ob->set("qi", qi);
	ob->set("jingli", zhili);
	ob->set("neili", neili);
	ob->set("food", shiwu);
	ob->set("water", yinshui);

	if(userp(ob)
	&& ob != me
	&& !wizardp(ob)) {
		CHANNEL_D->do_channel(find_object(SEC_OB),"sys",sprintf("%s[%s]将%s[%s]状态恢复了。",
			me->query("name"),geteuid(me),ob->query("name"),geteuid(ob)));
		log_file("static/FULL",sprintf("%s[%s]将%s[%s]的状态恢复了[%s]。\n",
		me->query("name"),geteuid(me),ob->query("name"),geteuid(ob),ctime(time())));
	}
	if(ob==me)
		return notify_fail(HIG"你的状态重新恢复完毕！\n"NOR);
	tell_room(ob,HIG+me->query("name")+"将你的状态重新恢复完毕！\n"NOR);
		return notify_fail(HIC"你将"+ob->name()+"的状态重新恢复完毕！\n"NOR);
}
int help(object me)
{
  write(@HELP
指令格式 : full

此指令可让你恢复所有的精气。
HELP
	);
	return 1;
}
