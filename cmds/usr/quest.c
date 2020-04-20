// quest.c
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,nowtime = time();
	mapping quest,myfam;
	object target;
	object* inv;

	myfam = me->query("family");

	if(arg == "master") {
		inv = all_inventory(environment(me));
		i = sizeof (inv);

	while (i--) {
		if(inv[i]->is_master()){
		target = inv[i];
		break;
		}
	}

	if(!myfam)
		return notify_fail("你还没有加入任何门派呢！\n");

	if(!target)
		return notify_fail("你要跟谁领取任务？\n");

	if(myfam["family_name"] != target->query("family/family_name"))
		return notify_fail(target->name()+"对你呵呵一笑，显然不明白你的意思。\n");

		if( me->query("combat_exp") < 3000000 ) {
			MQUEST_D->give_quest(target,me,1);
			return 1;
		}
		else {
			MQUEST_D->give_job(target,me,1);
			return 1;
		}
	}
	if( !arg || arg =="" || arg != "master") {
		if(!mapp(quest =  me->query("quest")))
			return notify_fail("你现在没有任何任务！\n");

		if(quest["from"] == "门派"){
			if( quest["quest_type"] == "杀" || quest["quest_type"] == "拿")
				write("师长给你的任务是"+ quest["quest_type"] + "『" + quest["quest"] + "』，据称此人最近经常在『"HIG + quest["where"] + NOR"』一带出没。\n");
			else if( quest["quest_type"] == "找" || quest["quest_type"] == "寻")
				write("师长给你的任务是到『"HIG + quest["where"] + NOR"』把『" + quest["quest"] + "』"+ quest["quest_type"] + "回来。\n");

		}
		else if(quest["from"] == "驿站"){
				write("你现在的任务是替"+ quest["get_from"] + quest["quest_type"] + "『" + quest["quest"] + "』。\n");
		}
		else if(quest["from"] == "官府"){
			if(quest["quest_type"] == "抓")
				write("你现在的任务是前往『"HIG + quest["where"] +NOR"』捉拿疑犯『"HIG+ quest["quest"]+NOR"』。\n");
			else if(quest["quest_type"] == "杀")
				write("你现在的任务是追杀通缉要犯『"HIG+ quest["quest"]+NOR"』，据说此人最近经常在『"HIG+ quest["where"]+NOR"』出现。\n");
		}
		else if(quest["from"] == "江湖"){
			write("江湖中传来"+ quest["owner_name"] +"正在寻找"+ quest["quest"]+"的消息。\n");
		}
		else if(quest["from"] == "镖局"){
			write("你现在的任务是护送"+ quest["quest"] +"到"+ quest["where"]+"去，一路保护他的安全。\n");
		}
	}                        
	nowtime = quest["task_time"] - time();

	if( nowtime  > 0 ){
		if(quest["from"] == "江湖")
			tell_object(me,"该消息流传至今，只剩下"+ CHINESE_D->chinese_time(nowtime) +"就失效了。\n");
		else 
			tell_object(me,"距离任务失效时间还有" + CHINESE_D->chinese_time(nowtime) + "，请尽快完成它。\n");
	}
	else
		write("但是你已经没有足够的时间来完成它了。\n");
		return 1;

}
int help(object me)
{
	write(@HELP
指令格式 : quest 可以显示出你当前的门派任务。
	   quest master 可以用来领取门派任务。
	   quest guanfu 可以用来查询当前的官府任务。
HELP
	);
	return 1;
}
